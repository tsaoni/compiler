/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_hw2.y"

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

#line 115 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    SEMICOLON = 262,
    LoopStmt = 263,
    PRINT = 264,
    INC = 265,
    DEC = 266,
    BIG_EQU = 267,
    SMALL_EQU = 268,
    EQUAL = 269,
    NOT_EQUAL = 270,
    AND = 271,
    OR = 272,
    TRUE = 273,
    FALSE = 274,
    IF = 275,
    ELSE = 276,
    WHILE = 277,
    FOR = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    MUL_ASSIGN = 281,
    QUO_ASSIGN = 282,
    REM_ASSIGN = 283,
    INT_LIT = 284,
    FLOAT_LIT = 285,
    STRING_LIT = 286,
    IDENT = 287
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define SEMICOLON 262
#define LoopStmt 263
#define PRINT 264
#define INC 265
#define DEC 266
#define BIG_EQU 267
#define SMALL_EQU 268
#define EQUAL 269
#define NOT_EQUAL 270
#define AND 271
#define OR 272
#define TRUE 273
#define FALSE 274
#define IF 275
#define ELSE 276
#define WHILE 277
#define FOR 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define MUL_ASSIGN 281
#define QUO_ASSIGN 282
#define REM_ASSIGN 283
#define INT_LIT 284
#define FLOAT_LIT 285
#define STRING_LIT 286
#define IDENT 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "compiler_hw2.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 238 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    39,     2,     2,    46,     2,     2,
      34,    35,    44,    42,     2,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      40,    38,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    91,    95,    96,    97,    98,    99,   100,
     101,   105,   106,   110,   111,   112,   116,   120,   124,   128,
     129,   130,   131,   136,   143,   153,   158,   159,   160,   161,
     165,   213,   214,   215,   219,   234,   248,   253,   257,   258,
     262,   279,   283,   290,   291,   292,   293,   294,   295,   299,
     304,   310,   311,   315,   319,   320,   324,   325,   326,   327,
     328,   329,   333,   334,   338,   339,   343,   344,   348,   349,
     350,   354,   355,   359,   363,   367,   371,   375,   379,   380,
     381,   382,   383,   384,   385,   386,   390,   394,   395,   399,
     402,   408,   412,   417,   421,   432,   435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "STRING",
  "SEMICOLON", "LoopStmt", "PRINT", "INC", "DEC", "BIG_EQU", "SMALL_EQU",
  "EQUAL", "NOT_EQUAL", "AND", "OR", "TRUE", "FALSE", "IF", "ELSE",
  "WHILE", "FOR", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT", "';'",
  "'('", "')'", "'{'", "'}'", "'='", "'\"'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'['", "']'", "$accept", "Program", "Start",
  "StatementList", "IfStmt", "ElseStmt", "Cond", "NewScope", "EndScope",
  "Statement", "DeclarationStmt", "Type", "TypeName", "Ident", "LitInit",
  "Literal", "str", "Expr", "LeaveExpr", "or", "Assign", "Eq", "ErrLHS",
  "AndExpr", "and", "CmprExpr", "Cmpr", "AddExpr", "Add", "MulExpr", "Mul",
  "UnaExpr", "SignOpt", "Reverse", "Atom", "EnterCast", "OneArith",
  "Boolean", "PrintStmt", "LeavePrint", "IndHead", "IndEnd", "BracHead",
  "BracEnd", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    59,    40,    41,   123,   125,    61,    34,
      60,    62,    43,    45,    42,    47,    37,    33,    91,    93
};
# endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,    19,    61,  -127,  -127,  -127,  -127,  -127,  -127,    -8,
       6,    17,    23,    12,    12,   -17,  -127,  -127,    69,  -127,
      68,  -127,  -127,    88,     9,  -127,    33,    47,    67,    53,
    -127,    -4,    -4,    -4,    -4,  -127,  -127,  -127,   123,  -127,
     -20,   203,  -127,    -4,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,    -4,    -4,  -127,  -127,    -4,  -127,  -127,  -127,    -4,
    -127,  -127,  -127,  -127,    29,    76,     0,  -127,  -127,   158,
      68,    -4,  -127,  -127,  -127,    84,  -127,  -127,  -127,  -127,
     196,  -127,  -127,    -4,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    72,  -127,
      -4,    87,  -127,    95,  -127,  -127,  -127,  -127,   203,  -127,
    -127,    85,    -4,    -4,    -4,    -4,    -4,    -4,  -127,    85,
      86,  -127,  -127,   104,   109,   102,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,   111,   111,    -4,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,    61,    61,  -127,
     113,   113,  -127,  -127,   127,   149,   118,    -7,   175,  -127,
      -4,   122,    61,  -127,  -127,    -4,   113,   203,  -127,  -127,
     124,   138,   111,   111,    61,    61,   113,   113,   201,   127,
    -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    75,     1,    26,    27,    29,    28,    21,     0,
       0,     0,     0,    75,    75,    77,     2,    10,     0,    19,
       0,    25,    40,    39,    52,    55,    63,    67,     0,     0,
      22,    75,    75,    75,    75,    73,    74,    76,    75,    30,
      33,    48,    41,    75,    59,    58,    60,    61,    53,    56,
      57,    75,    75,    64,    65,    75,    68,    69,    70,    75,
      87,    88,    34,    35,    95,     0,    78,    81,    71,     0,
       0,    75,    89,    90,    72,     0,    16,    16,    40,     4,
       0,    93,    23,    75,    50,    50,    50,    50,    50,    49,
      20,    50,    38,    51,    54,    62,    66,    37,     0,    79,
      75,     0,    80,     0,    92,    91,    40,    40,    48,    31,
      32,     0,    75,    75,    75,    75,    75,    75,    36,     0,
       0,    96,    82,     0,     0,     0,    94,    24,    40,    40,
      40,    40,    40,    40,    83,    84,    85,     0,     0,    75,
      43,    44,    45,    46,    47,    42,    17,    75,    75,    16,
       0,     0,    40,    18,    15,    75,     0,     0,    75,     6,
      75,     0,    75,    11,    40,    75,     0,    48,    40,    14,
       0,     0,     0,     0,    75,    75,     0,     0,    75,    15,
       8,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   -38,  -127,   -58,   -75,  -126,  -124,  -127,
    -127,  -127,   105,   -25,  -127,   -79,  -127,   -27,   -70,  -127,
     -99,  -127,   164,   125,  -127,  -127,  -127,   -35,  -127,   126,
    -127,  -127,   100,   162,  -127,  -127,   116,   107,  -127,  -127,
     133,    70,  -127,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,   158,   106,   147,   154,    18,
      19,    20,    21,    40,    82,    67,    98,    22,    41,    43,
      90,    91,   112,    23,    51,    24,    52,    25,    55,    26,
      59,    27,    28,    29,    68,    69,    70,    74,    30,   105,
      83,   127,    71,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,   109,   107,    66,    75,    76,    77,    78,   108,   125,
      60,    61,   148,   161,   -77,   -77,    92,    94,    80,     3,
      95,    44,    45,    46,    47,    48,    31,   155,    81,   146,
      15,   162,   -86,   -86,   -86,   -86,   123,   124,    13,    14,
      32,   136,   169,    15,   103,   102,   174,   175,    81,    49,
      50,    33,   178,   179,    13,    14,   111,    34,   140,   141,
     142,   143,   144,   145,     4,     5,     6,     7,   170,     8,
       9,    72,    73,   119,   152,    53,    54,    60,    61,   -77,
     -77,    10,   156,    11,    12,   128,   129,   130,   131,   132,
     133,    56,    57,    58,   167,   135,    62,    63,   171,    39,
      39,    64,    38,    13,    14,    42,    65,    97,    15,   150,
     151,   118,   149,    35,    36,    62,    63,   159,    39,   104,
     163,   181,   120,    -5,   166,    65,     4,     5,     6,     7,
     121,     8,     9,   164,   126,   139,   176,   177,   168,   137,
     180,   -77,   -77,    10,   138,    11,    12,   146,   157,    -7,
     153,   160,     4,     5,     6,     7,   165,     8,     9,   172,
      -5,     4,     5,     6,     7,    13,    14,   -77,   -77,    10,
      15,    11,    12,   173,   101,   -12,    93,    37,     4,     5,
       6,     7,    99,     8,     9,    96,    -7,   110,     0,   134,
       0,    13,    14,   -77,   -77,    10,    15,    11,    12,   100,
       0,    -9,     0,     0,     4,     5,     6,     7,     0,     8,
       9,     0,   -12,     0,    72,    73,     0,    13,    14,   -77,
     -77,    10,    15,    11,    12,    62,    63,    84,    85,    86,
      87,    88,     0,     0,     0,    65,     0,     0,    -9,     0,
       0,    89,     0,    13,    14,     0,     0,     0,    15,   113,
     114,   115,   116,     0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      38,    80,    77,    28,    31,    32,    33,    34,    78,   108,
      10,    11,   138,    20,    18,    19,    43,    52,    38,     0,
      55,    12,    13,    14,    15,    16,    34,   151,    48,    36,
      47,   157,     3,     4,     5,     6,   106,   107,    42,    43,
      34,   120,   166,    47,    71,    70,   172,   173,    48,    40,
      41,    34,   176,   177,    42,    43,    83,    34,   128,   129,
     130,   131,   132,   133,     3,     4,     5,     6,   167,     8,
       9,    18,    19,   100,   149,    42,    43,    10,    11,    18,
      19,    20,   152,    22,    23,   112,   113,   114,   115,   116,
     117,    44,    45,    46,   164,   120,    29,    30,   168,    32,
      32,    34,    33,    42,    43,    17,    39,    31,    47,   147,
     148,    39,   139,    13,    14,    29,    30,   155,    32,    35,
     158,   179,    35,     0,   162,    39,     3,     4,     5,     6,
      35,     8,     9,   160,    49,    33,   174,   175,   165,    35,
     178,    18,    19,    20,    35,    22,    23,    36,    21,     0,
      37,    33,     3,     4,     5,     6,    34,     8,     9,    35,
      37,     3,     4,     5,     6,    42,    43,    18,    19,    20,
      47,    22,    23,    35,    69,     0,    51,    15,     3,     4,
       5,     6,    66,     8,     9,    59,    37,    80,    -1,   119,
      -1,    42,    43,    18,    19,    20,    47,    22,    23,    66,
      -1,     0,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    37,    -1,    18,    19,    -1,    42,    43,    18,
      19,    20,    47,    22,    23,    29,    30,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    39,    -1,    -1,    37,    -1,
      -1,    38,    -1,    42,    43,    -1,    -1,    -1,    47,    85,
      86,    87,    88,    -1,    -1,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     4,     5,     6,     8,     9,
      20,    22,    23,    42,    43,    47,    53,    54,    59,    60,
      61,    62,    67,    73,    75,    77,    79,    81,    82,    83,
      88,    34,    34,    34,    34,    82,    82,    83,    33,    32,
      63,    68,    17,    69,    12,    13,    14,    15,    16,    40,
      41,    74,    76,    42,    43,    78,    44,    45,    46,    80,
      10,    11,    29,    30,    34,    39,    63,    65,    84,    85,
      86,    92,    18,    19,    87,    67,    67,    67,    67,    53,
      38,    48,    64,    90,    24,    25,    26,    27,    28,    38,
      70,    71,    67,    73,    77,    77,    79,    31,    66,    86,
      90,    62,    63,    67,    35,    89,    56,    56,    68,    65,
      87,    67,    72,    72,    72,    72,    72,    72,    39,    67,
      35,    35,    93,    68,    68,    70,    49,    91,    67,    67,
      67,    67,    67,    67,    91,    63,    65,    35,    35,    33,
      68,    68,    68,    68,    68,    68,    36,    57,    57,    67,
      53,    53,    56,    37,    58,    58,    68,    21,    55,    53,
      33,    20,    57,    53,    67,    34,    53,    68,    67,    58,
      70,    68,    35,    35,    57,    57,    53,    53,    58,    58,
      53,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    56,    57,    58,    59,
      59,    59,    59,    60,    60,    61,    62,    62,    62,    62,
      63,    64,    64,    64,    65,    65,    65,    66,    67,    67,
      68,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    73,    73,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    81,    81,    82,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    86,    86,    87,
      87,    88,    89,    90,    91,    92,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     2,    10,     9,    18,    17,
       1,    11,    10,    10,     4,     0,     0,     1,     1,     1,
       3,     1,     1,     3,     5,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     1,     1,     3,     1,     3,     1,
       0,     1,     4,     4,     4,     4,     4,     4,     0,     1,
       0,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     0,     2,     0,     1,     2,
       2,     1,     3,     4,     4,     4,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 87 "compiler_hw2.y"
                          { dump_symbol(); }
#line 1558 "y.tab.c"
    break;

  case 3:
#line 91 "compiler_hw2.y"
      { create_symbol(); new_expr(); }
#line 1564 "y.tab.c"
    break;

  case 16:
#line 116 "compiler_hw2.y"
      { errcond = 1; }
#line 1570 "y.tab.c"
    break;

  case 17:
#line 120 "compiler_hw2.y"
          { create_symbol(); }
#line 1576 "y.tab.c"
    break;

  case 18:
#line 124 "compiler_hw2.y"
          { dump_symbol(); }
#line 1582 "y.tab.c"
    break;

  case 23:
#line 136 "compiler_hw2.y"
                         {  if(declare)
                            {   
                                insert_symbol(id, 0);
                                printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope_level);
                                declare = 0;
                            }
                         }
#line 1594 "y.tab.c"
    break;

  case 24:
#line 143 "compiler_hw2.y"
                                     { if(declare)
                                   {   
                                        insert_symbol(id, 1);
                                        printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope_level);
                                        declare = 0;
                                   }
                                 }
#line 1606 "y.tab.c"
    break;

  case 25:
#line 153 "compiler_hw2.y"
               { /*$1 = $$;*/
                 declare = 1; }
#line 1613 "y.tab.c"
    break;

  case 26:
#line 158 "compiler_hw2.y"
          { strcpy(type, "int"); if(ctype == 'a') ctype ='i'; }
#line 1619 "y.tab.c"
    break;

  case 27:
#line 159 "compiler_hw2.y"
            { strcpy(type, "float"); if(ctype == 'a') ctype = 'f'; }
#line 1625 "y.tab.c"
    break;

  case 28:
#line 160 "compiler_hw2.y"
             { strcpy(type, "string"); }
#line 1631 "y.tab.c"
    break;

  case 29:
#line 161 "compiler_hw2.y"
           { strcpy(type, "bool"); }
#line 1637 "y.tab.c"
    break;

  case 30:
#line 165 "compiler_hw2.y"
            { strcpy(id, (yyval.s_val));
              if(!declare)
              {
                  int ad = lookup_symbol((yyval.s_val));
                  if(ad != -1)
                      printf("IDENT (name=%s, address=%d)\n", (yyval.s_val), ad);
              }
              int k;
              for(k = top; k >= 0; k--)
              {
                  table *t = tb_stack[k];
                  int i;
                  for(i = 0; i <= t -> top; i++)
                      if(strcmp(t -> stack[i] -> id_name, (yyval.s_val)) == 0)
                      {
                          if(k == top && declare)
                          {
                              printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, (yyval.s_val), t -> stack[i] -> line);
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
                  printf("error:%d: undefined: %s\n", yylineno, (yyval.s_val));
                  deferr = 1;
              }
              if(rhs)
                  strcpy(errlhs, "");
            }
#line 1687 "y.tab.c"
    break;

  case 31:
#line 213 "compiler_hw2.y"
                  {}
#line 1693 "y.tab.c"
    break;

  case 32:
#line 214 "compiler_hw2.y"
                  { strcpy(printype, "bool"); }
#line 1699 "y.tab.c"
    break;

  case 34:
#line 219 "compiler_hw2.y"
              {
        printf("INT_LIT %d\n", (yyval.i_val));
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
#line 1719 "y.tab.c"
    break;

  case 35:
#line 234 "compiler_hw2.y"
                {
        printf("FLOAT_LIT %f\n", (yyval.f_val));
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
#line 1738 "y.tab.c"
    break;

  case 36:
#line 248 "compiler_hw2.y"
                  { strcpy(printype, "string"); exprs -> nstk[exprs -> top + 1] = 's'; if(rhs) strcpy(errlhs, "string"); }
#line 1744 "y.tab.c"
    break;

  case 37:
#line 253 "compiler_hw2.y"
                 { printf("STRING_LIT %s\n", (yyval.s_val)); }
#line 1750 "y.tab.c"
    break;

  case 40:
#line 262 "compiler_hw2.y"
      {  while(exprs -> top > -1) 
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
#line 1769 "y.tab.c"
    break;

  case 41:
#line 279 "compiler_hw2.y"
         { precedence('|'); strcpy(printype, "bool"); }
#line 1775 "y.tab.c"
    break;

  case 42:
#line 283 "compiler_hw2.y"
                               { if(exprs -> nstk[0] != 's' && !deferr) 
                              type_validation('=', asgn, exprs -> nstk[0]);
                          asgn = '\0';
                          deferr = 0;
                          printf("ASSIGN\n"); 
                          strcpy(errlhs, "");
                         }
#line 1787 "y.tab.c"
    break;

  case 43:
#line 290 "compiler_hw2.y"
                                        { printf("ADD_ASSIGN\n"); strcpy(errlhs, "");}
#line 1793 "y.tab.c"
    break;

  case 44:
#line 291 "compiler_hw2.y"
                                       { printf("SUB_ASSIGN\n"); strcpy(errlhs, ""); }
#line 1799 "y.tab.c"
    break;

  case 45:
#line 292 "compiler_hw2.y"
                                       { printf("MUL_ASSIGN\n"); strcpy(errlhs, ""); }
#line 1805 "y.tab.c"
    break;

  case 46:
#line 293 "compiler_hw2.y"
                                       { printf("QUO_ASSIGN\n"); strcpy(errlhs, ""); }
#line 1811 "y.tab.c"
    break;

  case 47:
#line 294 "compiler_hw2.y"
                                       { printf("REM_ASSIGN\n"); strcpy(errlhs, ""); }
#line 1817 "y.tab.c"
    break;

  case 49:
#line 299 "compiler_hw2.y"
          { asgn = exprs -> nstk[0]; 
            }
#line 1824 "y.tab.c"
    break;

  case 50:
#line 304 "compiler_hw2.y"
      { if(strcmp(errlhs, ""))
            rhs = 0;
      }
#line 1832 "y.tab.c"
    break;

  case 53:
#line 315 "compiler_hw2.y"
          { precedence('&'); strcpy(printype, "bool"); }
#line 1838 "y.tab.c"
    break;

  case 56:
#line 324 "compiler_hw2.y"
          { precedence('<'); }
#line 1844 "y.tab.c"
    break;

  case 57:
#line 325 "compiler_hw2.y"
          { precedence('>'); }
#line 1850 "y.tab.c"
    break;

  case 58:
#line 326 "compiler_hw2.y"
                { precedence('a'); }
#line 1856 "y.tab.c"
    break;

  case 59:
#line 327 "compiler_hw2.y"
              { precedence('b'); }
#line 1862 "y.tab.c"
    break;

  case 60:
#line 328 "compiler_hw2.y"
            { precedence('c'); }
#line 1868 "y.tab.c"
    break;

  case 61:
#line 329 "compiler_hw2.y"
                { precedence('d'); }
#line 1874 "y.tab.c"
    break;

  case 64:
#line 338 "compiler_hw2.y"
          { precedence('+'); }
#line 1880 "y.tab.c"
    break;

  case 65:
#line 339 "compiler_hw2.y"
          { precedence('-'); }
#line 1886 "y.tab.c"
    break;

  case 68:
#line 348 "compiler_hw2.y"
          { precedence('*'); }
#line 1892 "y.tab.c"
    break;

  case 69:
#line 349 "compiler_hw2.y"
          { precedence('/'); }
#line 1898 "y.tab.c"
    break;

  case 70:
#line 350 "compiler_hw2.y"
          { precedence('%'); }
#line 1904 "y.tab.c"
    break;

  case 71:
#line 354 "compiler_hw2.y"
                   { printf("%s", sign); strcpy(sign, ""); }
#line 1910 "y.tab.c"
    break;

  case 72:
#line 355 "compiler_hw2.y"
                      { printf("%s", sign); strcpy(sign, ""); strcpy(printype, "bool"); }
#line 1916 "y.tab.c"
    break;

  case 73:
#line 359 "compiler_hw2.y"
                  { char s[100] = "POS\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
#line 1925 "y.tab.c"
    break;

  case 74:
#line 363 "compiler_hw2.y"
                  { char s[100] = "NEG\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
#line 1934 "y.tab.c"
    break;

  case 76:
#line 371 "compiler_hw2.y"
                  { char s[100] = "NOT\n";
                    strcat(s, sign);
                    strcpy(sign, s); 
                  }
#line 1943 "y.tab.c"
    break;

  case 86:
#line 390 "compiler_hw2.y"
          { ctype = 'a'; }
#line 1949 "y.tab.c"
    break;

  case 87:
#line 394 "compiler_hw2.y"
          { printf("INC\n"); }
#line 1955 "y.tab.c"
    break;

  case 88:
#line 395 "compiler_hw2.y"
          { printf("DEC\n"); }
#line 1961 "y.tab.c"
    break;

  case 89:
#line 399 "compiler_hw2.y"
           { printf("TRUE\n"); 
             exprs -> nstk[exprs -> top + 1] = 'b';
           }
#line 1969 "y.tab.c"
    break;

  case 90:
#line 402 "compiler_hw2.y"
            { printf("FALSE\n"); 
              exprs -> nstk[exprs -> top + 1] = 'b';
            }
#line 1977 "y.tab.c"
    break;

  case 91:
#line 408 "compiler_hw2.y"
                                { printf("PRINT %s\n", printype); parr = 0; }
#line 1983 "y.tab.c"
    break;

  case 92:
#line 412 "compiler_hw2.y"
          { while(exprs -> top > -1)                                                      
                 print_optr(exprs -> stk[exprs -> top--]); }
#line 1990 "y.tab.c"
    break;

  case 93:
#line 417 "compiler_hw2.y"
          { new_expr(); }
#line 1996 "y.tab.c"
    break;

  case 94:
#line 421 "compiler_hw2.y"
          { estack * p = exprs;
          exprs = exprs -> next;
          while(p -> top > -1) 
              print_optr(p -> stk[p -> top--]);
              free(p); 
            if(rhs)
                strcpy(errlhs, ""); 
          }
#line 2009 "y.tab.c"
    break;

  case 95:
#line 432 "compiler_hw2.y"
          { new_expr(); }
#line 2015 "y.tab.c"
    break;

  case 96:
#line 435 "compiler_hw2.y"
          { estack * p = exprs;
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
#line 2031 "y.tab.c"
    break;


#line 2035 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 448 "compiler_hw2.y"


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
