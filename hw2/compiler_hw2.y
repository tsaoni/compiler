/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }


    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(/* ... */);
    static void insert_symbol(char *, int);
    static int lookup_symbol(char *);
    static void dump_symbol(/* ... */);
    static void precedence(char);
    static void print_optr(char);
    static void new_expr();
    static void type_validation(char, char, char);
    static char *ret_type(char);

    int declare = 0;
    int scope_level = -1;
    int addr = 0;
    int top = -1;
    int parr = 0;
    int errcond = 0;
    int deferr = 0;
    int rhs = 1;
    char type[10], printype[10], ctype = '\0', asgn = '\0';
    char id[10];
    char check_valid[2][10] = {{'\0'}, {'\0'}};
    table *tb_stack[10];
    char sign[100];
    char errlhs[7] = "";
    char ptable[2][13] = {{'|', '&', '<', '>', 'a', 'b', 'c', 'd', '+', '-', '*', '/', '%'},
                          {'0', '1', '2', '2', '2', '2', '2', '2', '3', '3', '4', '4', '4'}};
    estack *exprs;
%}

%define parse.error verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token INT FLOAT BOOL STRING
%token SEMICOLON
%token  LoopStmt
%token PRINT 
%token INC DEC
%token BIG_EQU SMALL_EQU EQUAL NOT_EQUAL
%token AND OR
%token TRUE FALSE
%token IF ELSE WHILE FOR
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN

/* Token with return, which need to specify type */
%token <i_val> INT_LIT 
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> IDENT

/* Nonterminal with return, which need to sepcify type */

/* Yacc will start at this nonterminal */
%start Program


/* Grammar section */
%%

Program
    : Start StatementList { dump_symbol(); }
;

Start
    : { create_symbol(); new_expr(); }
;

StatementList
    : Statement ';' StatementList
    | Statement ';'
    | WHILE '(' Expr Cond LeaveExpr ')' NewScope StatementList EndScope StatementList
    | WHILE '(' Expr Cond LeaveExpr ')' NewScope StatementList EndScope 
    | FOR '(' Expr LeaveExpr Assign ';' Expr Cond LeaveExpr ';' Expr LeaveExpr Assign ')' NewScope StatementList EndScope StatementList
    | FOR '(' Expr LeaveExpr Assign ';' Expr Cond LeaveExpr ';' Expr LeaveExpr Assign ')' NewScope StatementList EndScope 
    | IfStmt
;

IfStmt
    : IF '(' Expr Cond LeaveExpr ')' NewScope StatementList EndScope ElseStmt StatementList
    | IF '(' Expr Cond LeaveExpr ')' NewScope StatementList EndScope ElseStmt
;

ElseStmt
    : ELSE IF '(' Expr LeaveExpr ')' NewScope StatementList EndScope ElseStmt
    | ELSE NewScope StatementList EndScope
    |
;

Cond
    : { errcond = 1; }
;

NewScope
    : '{' { create_symbol(); }
;

EndScope
    : '}' { dump_symbol(); }
;

Statement
    : DeclarationStmt
    | Expr LeaveExpr Assign
    | LoopStmt
    | PrintStmt
;


DeclarationStmt
    : Type Ident LitInit {  if(declare)
                            {   
                                insert_symbol(id, 0);
                                printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope_level);
                                declare = 0;
                            }
                         }
    | Type Ident IndHead Expr IndEnd { if(declare)
                                   {   
                                        insert_symbol(id, 1);
                                        printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope_level);
                                        declare = 0;
                                   }
                                 }
;

Type
    : TypeName { /*$1 = $$;*/
                 declare = 1; }
;

TypeName
    : INT { strcpy(type, "int"); if(ctype == 'a') ctype ='i'; } 
    | FLOAT { strcpy(type, "float"); if(ctype == 'a') ctype = 'f'; }
    | STRING { strcpy(type, "string"); }
    | BOOL { strcpy(type, "bool"); }
;

Ident
    : IDENT { strcpy(id, $<s_val>$);
              if(!declare)
              {
                  int ad = lookup_symbol($<s_val>$);
                  if(ad != -1)
                      printf("IDENT (name=%s, address=%d)\n", $<s_val>$, ad);
              }
              int k;
              for(k = top; k >= 0; k--)
              {
                  table *t = tb_stack[k];
                  int i;
                  for(i = 0; i <= t -> top; i++)
                      if(strcmp(t -> stack[i] -> id_name, $<s_val>$) == 0)
                      {
                          if(k == top && declare)
                          {
                              printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, $<s_val>$, t -> stack[i] -> line);
                              declare = 0;
                              break;
                          }
                          if(t -> stack[i] -> arr)
                              parr = 1;
                          strcpy(printype, t -> stack[i] -> type);
                          if(ctype)
                          {
                              printf("%c to %c\n", t -> stack[i] -> type[0] - 32, ctype - 32);
                              exprs -> nstk[exprs -> top + 1] = ctype;
                          }
                          else
                              exprs -> nstk[exprs -> top + 1] = t -> stack[i] -> type[0];
                          ctype = '\0';
                          break;
                      }
                  if(i < t -> top + 1)
                  break;
              }
              if(k < 0 && !declare)
              {
                  printf("error:%d: undefined: %s\n", yylineno, $<s_val>$);
                  deferr = 1;
              }
              if(rhs)
                  strcpy(errlhs, "");
            }
;

LitInit
    : '=' Literal {}
    | '=' Boolean { strcpy(printype, "bool"); }
    |
;

Literal
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>$);
        if(!parr)
            strcpy(printype, "int");
        if(ctype)
        {
            printf("I to %c\n", ctype - 32);
            exprs -> nstk[exprs -> top + 1] = ctype;
        }
        else
            exprs -> nstk[exprs -> top + 1] = 'i';
        ctype = '\0';
        if(rhs)
            strcpy(errlhs, "int");
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>$);
        strcpy(printype, "float");
        if(ctype)
        {
            printf("F to %c\n", ctype - 32);
            exprs -> nstk[exprs -> top + 1] = ctype;
        }
        else
            exprs -> nstk[exprs -> top + 1] = 'f';
        ctype = '\0';
        if(rhs)
            strcpy(errlhs, "float");
    }
    | '"' str '"' { strcpy(printype, "string"); exprs -> nstk[exprs -> top + 1] = 's'; if(rhs) strcpy(errlhs, "string"); }
;


str
    : STRING_LIT { printf("STRING_LIT %s\n", $<s_val>$); }
;

Expr
    : AndExpr or Expr 
    | AndExpr
;

LeaveExpr
    : {  while(exprs -> top > -1) 
         {
             int k = exprs -> top;
             type_validation(exprs -> stk[k], exprs -> nstk[k], exprs -> nstk[k + 1]);
             print_optr(exprs -> stk[exprs -> top--]); 
         }

            if(errcond && exprs -> nstk[0] != 'b')
                printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, ret_type(exprs -> nstk[0]));
            errcond = 0;
            if(!rhs)
                printf("error:%d: cannot assign to %s\n", yylineno, errlhs);
            rhs = 1;
      }
;

or
    : OR { precedence('|'); strcpy(printype, "bool"); }
;

Assign
    : Eq ErrLHS Expr LeaveExpr { if(exprs -> nstk[0] != 's' && !deferr) 
                              type_validation('=', asgn, exprs -> nstk[0]);
                          asgn = '\0';
                          deferr = 0;
                          printf("ASSIGN\n"); 
                          strcpy(errlhs, "");
                         }
    | ADD_ASSIGN  ErrLHS Expr LeaveExpr { printf("ADD_ASSIGN\n"); strcpy(errlhs, "");}
    | SUB_ASSIGN ErrLHS Expr LeaveExpr { printf("SUB_ASSIGN\n"); strcpy(errlhs, ""); }
    | MUL_ASSIGN ErrLHS Expr LeaveExpr { printf("MUL_ASSIGN\n"); strcpy(errlhs, ""); }
    | QUO_ASSIGN ErrLHS Expr LeaveExpr { printf("QUO_ASSIGN\n"); strcpy(errlhs, ""); }
    | REM_ASSIGN ErrLHS Expr LeaveExpr { printf("REM_ASSIGN\n"); strcpy(errlhs, ""); }
    | 
;

Eq
    : '=' { asgn = exprs -> nstk[0]; 
            }
;

ErrLHS
    : { if(strcmp(errlhs, ""))
            rhs = 0;
      }
;

AndExpr
    : CmprExpr and AndExpr 
    | CmprExpr
;

and
    : AND { precedence('&'); strcpy(printype, "bool"); }
;

CmprExpr
    : CmprExpr Cmpr AddExpr 
    | AddExpr
;

Cmpr
    : '<' { precedence('<'); }
    | '>' { precedence('>'); }
    | SMALL_EQU { precedence('a'); }
    | BIG_EQU { precedence('b'); }
    | EQUAL { precedence('c'); }
    | NOT_EQUAL { precedence('d'); }
;

AddExpr
    : MulExpr Add AddExpr 
    | MulExpr 
;

Add
    : '+' { precedence('+'); }
    | '-' { precedence('-'); }
;

MulExpr
    : UnaExpr Mul MulExpr 
    | UnaExpr 
;

Mul
    : '*' { precedence('*'); }
    | '/' { precedence('/'); }
    | '%' { precedence('%'); }
;

UnaExpr
    : SignOpt Atom { printf("%s", sign); strcpy(sign, ""); }
    | Reverse Boolean { printf("%s", sign); strcpy(sign, ""); strcpy(printype, "bool"); }
;

SignOpt
    : '+' SignOpt { char s[100] = "POS\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
    | '-' SignOpt { char s[100] = "NEG\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
    |
;

Reverse
    : '!' Reverse { char s[100] = "NOT\n";
                    strcat(s, sign);
                    strcpy(sign, s); 
                  }   
    | 
;

Atom
    : Ident
    | Ident OneArith
    | OneArith Ident
    | Literal
    | BracHead Expr BracEnd
    | Ident IndHead Expr IndEnd
    | EnterCast TypeName ')' Ident
    | EnterCast TypeName ')' Literal
;

EnterCast
    : '(' { ctype = 'a'; }
;

OneArith
    : INC { printf("INC\n"); }
    | DEC { printf("DEC\n"); }
;

Boolean
    : TRUE { printf("TRUE\n"); 
             exprs -> nstk[exprs -> top + 1] = 'b';
           }
    | FALSE { printf("FALSE\n"); 
              exprs -> nstk[exprs -> top + 1] = 'b';
            }
;

PrintStmt
    : PRINT '(' Expr LeavePrint { printf("PRINT %s\n", printype); parr = 0; }
;

LeavePrint
    : ')' { while(exprs -> top > -1)                                                      
                 print_optr(exprs -> stk[exprs -> top--]); }
;

IndHead
    : '[' { new_expr(); }
;

IndEnd
    : ']' { estack * p = exprs;
          exprs = exprs -> next;
          while(p -> top > -1) 
              print_optr(p -> stk[p -> top--]);
              free(p); 
            if(rhs)
                strcpy(errlhs, ""); 
          }
;

BracHead
    : '(' { new_expr(); }
;
BracEnd
    : ')' { estack * p = exprs;
          exprs = exprs -> next;
          while(p -> top > -1) 
          {
              int k = p -> top;
              type_validation(p -> stk[k], p -> nstk[k], p -> nstk[k + 1]);
              print_optr(p -> stk[p -> top--]);
          }
          exprs -> nstk[exprs -> top + 1] = p -> nstk[0];
          free(p); 
          }
;

%%

/* C code section */
static void create_symbol(/* ... */)
{
    tb_stack[++top] = (table *)malloc(sizeof(table));
    tb_stack[top] -> scope_level = ++scope_level;
    tb_stack[top] -> top = -1;
}

static void insert_symbol(char *id, int arr)
{
    int t = ++tb_stack[top] -> top;
    tb_stack[top] -> stack[t] = (entry *)malloc(sizeof(entry));
    tb_stack[top] -> stack[t] -> addr = addr;
    tb_stack[top] -> stack[t] -> line = yylineno;
    tb_stack[top] -> stack[t] -> arr = arr;
    strcpy(tb_stack[top] -> stack[t] -> id_name, id);
    strcpy(tb_stack[top] -> stack[t] -> type, type);
    addr++;
}

static int lookup_symbol(char *id)
{
    for(int i = top; i >= 0; i--)
        for(int j = 0; j <= tb_stack[i] -> top; j++)
            if(!strcmp(tb_stack[i] -> stack[j] -> id_name, id))
                return tb_stack[i] -> stack[j] -> addr;
    return -1;
}

static void dump_symbol(/* ... */)
{
    printf("> Dump symbol table (scope level: %d)\n", scope_level--);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i = 0; i <= tb_stack[top] -> top; i++)
    {
        entry *e = tb_stack[top] -> stack[i];
        if(!e -> arr)
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", i, e -> id_name, e -> type, e -> addr, e -> line, "-");
        else
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", i, e -> id_name, "array", e -> addr, e -> line, e -> type);
        free(e);
    }
    free(tb_stack[top]);
    top--;
}

char *ret_type(char c)
{
    switch(c)
    {
        case 'i':
            return "int";
        case 'f':
            return "float";
        case 'b':
            return "bool";
    }
    return NULL;
}

void type_validation(char op, char fst, char snd)
{
    char tp1[6], tp2[6];
    strcpy(tp1, ret_type(fst));
    strcpy(tp2, ret_type(snd));

    if(op == '%')
    {
        if(fst != 'i')
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, tp1);
        else if(snd != 'i')
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, tp2);
    }
    else if(op == '|' || op == '&')
    {
        char s[10];
        if(op == '|')
            strcpy(s, "OR");
        else if(op == '&')
            strcpy(s, "AND");
        if(fst != 'b')
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, s, tp1);
        else if(snd != 'b')
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, s, tp2);
    }
    else if(fst != snd)
    {
        char s[10];
        switch(op)
        {
            case '+':
                strcpy(s, "ADD");
                break;
            case '-':
                strcpy(s, "SUB");
                break;
            case '*':
                strcpy(s, "MUL");
                break;
            case '/':
                strcpy(s, "QUO");
                break;
            case '=':
                strcpy(s, "ASSIGN");
                break;
        }
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, s, tp1, tp2);
    }
    else if(op == '<' || op == '>' || op == 'a' || op == 'b' || op == 'c' || op == 'd')
        exprs -> nstk[exprs -> top] = 'b';
}

void new_expr()
{
    estack *p = (estack *)malloc(sizeof(estack));
    memset(p -> stk, '\0', 100);
    memset(p -> nstk, '\0', 100);
    p -> top = -1;
    p -> next = exprs;
    exprs = p;
}


void precedence(char c)
{
    if(exprs -> top != -1)
    {
        int ci, i;
        for(int i = 0; i < 13; i++)
            if(c == ptable[0][i])
            {
                ci = ptable[1][i];
                break;
            }
        for(i = 12; ptable[1][i] >= ci; i--)
            if(exprs -> top > -1 && exprs -> stk[exprs -> top] == ptable[0][i])
            {
                int k = exprs -> top;
                type_validation(exprs -> stk[k], exprs -> nstk[k], exprs -> nstk[k + 1]);
                print_optr(exprs -> stk[exprs -> top--]);
                i = 12;
            }
    }
    exprs -> stk[++exprs -> top] = c;
}

void print_optr(char optr)
{
    switch(optr)
    {
        case '|':
            printf("OR\n");
            break;
        case '&':
            printf("AND\n");
            break;
        case '<':
            printf("LSS\n");
            break;
        case '>':
            printf("GTR\n");
            break;
        case 'a':
            printf("LEQ\n");
            break;
        case 'b':
            printf("GEQ\n");
            break;
        case 'c':
            printf("EQL\n");
            break;
        case 'd':
            printf("NEQ\n");
            break;
        case '+':
            printf("ADD\n");
            break;
        case '-':
            printf("SUB\n");
            break;
        case '*':
            printf("MUL\n");
            break;
        case '/':
            printf("QUO\n");
            break;
        case '%':
            printf("REM\n");
    }

}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}
