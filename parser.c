/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

#include <stdio.h>
#include "decl.h"
#include "expr.h"
#include "type.h"
#include "stmt.h"
extern char *yytext;
extern int yylex();
extern int yyerror( char *str);
extern struct decl *parser_result;

#include "decl.h"
#include <string.h>
#include <stdlib.h>


#line 83 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "token.h".  */
#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_EOF = 0,
    TOKEN_ERROR = 258,
    TOKEN_ARRAY = 259,
    TOKEN_SUBTRACT = 260,
    TOKEN_AUTO = 261,
    TOKEN_BOOLEAN = 262,
    TOKEN_CHAR = 263,
    TOKEN_ELSE = 264,
    TOKEN_FALSE = 265,
    TOKEN_FLOAT = 266,
    TOKEN_FOR = 267,
    TOKEN_FUNCTION = 268,
    TOKEN_COLON = 269,
    TOKEN_IF = 270,
    TOKEN_INT = 271,
    TOKEN_PRINT = 272,
    TOKEN_RETURN = 273,
    TOKEN_STRING = 274,
    TOKEN_TRUE = 275,
    TOKEN_VOID = 276,
    TOKEN_WHILE = 277,
    TOKEN_ADD = 278,
    TOKEN_NEGATIVE = 279,
    TOKEN_MULTIPLY = 280,
    TOKEN_DIVISION = 281,
    TOKEN_MODULO = 282,
    TOKEN_EXPONENT = 283,
    TOKEN_LEFT_PARENTHESIS = 284,
    TOKEN_RIGHT_PARENTHESIS = 285,
    TOKEN_ASSIGN = 286,
    TOKEN_LEFT_BRACE = 287,
    TOKEN_RIGHT_BRACE = 288,
    TOKEN_LEFT_BRACKET = 289,
    TOKEN_RIGHT_BRACKET = 290,
    TOKEN_NOT_EQUAL = 291,
    TOKEN_NOT = 292,
    TOKEN_EQUAL = 293,
    TOKEN_NO = 294,
    TOKEN_LESS_THAN = 295,
    TOKEN_GREATER_THAN = 296,
    TOKEN_AND = 297,
    TOKEN_OR = 298,
    TOKEN_TYPE_SET = 299,
    TOKEN_SEMICOLON = 300,
    TOKEN_COMMA = 301,
    TOKEN_PLUS_PLUS = 302,
    TOKEN_MINUS_MINUS = 303,
    TOKEN_LESS_THAN_OR_EQUAL = 304,
    TOKEN_GREATER_THAN_OR_EQUAL = 305,
    TOKEN_IDENTIFIER = 306,
    TOKEN_INT_LITERAL = 307,
    TOKEN_FLOAT_LITERAL = 308,
    TOKEN_STRING_LITERAL = 309,
    TOKEN_CHAR_LITERAL = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "parser.bison" /* yacc.c:355  */

	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	char * name;
	struct type *type;
	struct param_list *param_list;

#line 189 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    98,   101,   102,   105,   106,   109,   112,
     113,   116,   117,   118,   122,   123,   124,   127,   128,   131,
     132,   133,   134,   135,   136,   137,   140,   141,   142,   146,
     147,   150,   151,   154,   155,   158,   161,   162,   165,   166,
     167,   168,   169,   172,   175,   176,   179,   180,   183,   184,
     187,   190,   191,   194,   195,   198,   201,   202,   205,   206,
     210,   211,   215,   216,   221,   222,   225,   228,   229,   232,
     235,   236,   239,   242,   245,   246,   249,   250,   253,   254,
     257,   258,   261,   262,   265,   266,   267,   270,   271,   272,
     273,   274,   277,   278,   279,   282,   283,   284,   285,   288,
     289,   290,   291,   294,   295,   298,   299,   303,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   317
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "TOKEN_EOF", "error", "$undefined", "TOKEN_ERROR", "TOKEN_ARRAY",
  "TOKEN_SUBTRACT", "TOKEN_AUTO", "TOKEN_BOOLEAN", "TOKEN_CHAR",
  "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FLOAT", "TOKEN_FOR",
  "TOKEN_FUNCTION", "TOKEN_COLON", "TOKEN_IF", "TOKEN_INT", "TOKEN_PRINT",
  "TOKEN_RETURN", "TOKEN_STRING", "TOKEN_TRUE", "TOKEN_VOID",
  "TOKEN_WHILE", "TOKEN_ADD", "TOKEN_NEGATIVE", "TOKEN_MULTIPLY",
  "TOKEN_DIVISION", "TOKEN_MODULO", "TOKEN_EXPONENT",
  "TOKEN_LEFT_PARENTHESIS", "TOKEN_RIGHT_PARENTHESIS", "TOKEN_ASSIGN",
  "TOKEN_LEFT_BRACE", "TOKEN_RIGHT_BRACE", "TOKEN_LEFT_BRACKET",
  "TOKEN_RIGHT_BRACKET", "TOKEN_NOT_EQUAL", "TOKEN_NOT", "TOKEN_EQUAL",
  "TOKEN_NO", "TOKEN_LESS_THAN", "TOKEN_GREATER_THAN", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_TYPE_SET", "TOKEN_SEMICOLON", "TOKEN_COMMA",
  "TOKEN_PLUS_PLUS", "TOKEN_MINUS_MINUS", "TOKEN_LESS_THAN_OR_EQUAL",
  "TOKEN_GREATER_THAN_OR_EQUAL", "TOKEN_IDENTIFIER", "TOKEN_INT_LITERAL",
  "TOKEN_FLOAT_LITERAL", "TOKEN_STRING_LITERAL", "TOKEN_CHAR_LITERAL",
  "$accept", "program", "decl_list", "decl", "identifier", "func_decl",
  "var_decl", "if_dangle", "stmt", "simple_stmt", "compound_stmt",
  "dangle_end", "reg_end", "access", "array_access",
  "array_access_recursive", "type", "stmt_block", "func_type",
  "param_recursive", "every_type", "array_type", "array_size",
  "array_expr_list", "nested_array_braces",
  "nested_array_braces_recursive", "array_decl", "param_list", "stmt_list",
  "return_stmt", "expr_assign", "inc_or_dec", "expr_val", "expr",
  "for_stmt", "for_cond", "for_expr", "expr_list", "expr_list_recursive",
  "expr2", "expr3", "expr4", "expr5", "expr6", "expr7", "expr8", "expr9",
  "boolean_literal", "func_call", "data_atom", "print_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -179

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-179)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,  -179,  -179,    10,    22,   -16,    57,  -179,  -179,  -179,
    -179,  -179,  -179,   241,    55,  -179,  -179,  -179,   257,  -179,
    -179,   -12,    39,   168,  -179,  -179,    63,   168,  -179,    69,
    -179,   188,  -179,  -179,   188,   168,   188,  -179,  -179,  -179,
    -179,    -8,    71,  -179,    60,  -179,  -179,  -179,  -179,    61,
      65,    23,   185,  -179,   149,  -179,    80,  -179,  -179,  -179,
     -16,    66,    93,  -179,    80,    80,    87,    80,   168,   168,
    -179,  -179,   168,   251,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   188,   106,    91,
    -179,    93,    98,  -179,    95,  -179,    95,   109,   115,  -179,
    -179,  -179,  -179,    65,    23,   185,   185,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,   251,    81,   118,
     110,   168,  -179,  -179,  -179,   122,   114,   135,  -179,   134,
    -179,    95,   168,  -179,   -16,  -179,   120,  -179,   151,  -179,
    -179,   147,   173,   161,   163,   168,   168,    76,  -179,   120,
    -179,  -179,    71,  -179,   169,   156,   159,   165,    64,   167,
     183,    93,   122,   251,   168,  -179,   168,  -179,  -179,   251,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
     198,  -179,   114,  -179,   187,   176,   134,  -179,   168,   212,
    -179,   191,   189,   224,  -179,   228,    82,   168,   168,   120,
     229,  -179,  -179,   216,   217,  -179,  -179,   212,   242,   212,
    -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     8,     0,     0,     5,     0,     7,     6,    13,
       1,     2,     4,     0,     0,    41,    42,    39,     0,    38,
      40,     0,     0,    52,    45,    44,     0,     0,    11,     0,
      59,     0,   106,   105,     0,     0,     0,   109,   111,   108,
     110,    33,   114,    34,     0,    70,   115,    71,    51,    69,
      80,    82,    86,    87,    92,    95,    99,   112,   113,   103,
      61,     0,     0,   114,   101,   102,     0,   100,    77,     0,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,    54,    79,   116,    79,     0,     0,    66,
      48,    50,    49,    81,    83,    85,    84,    89,    90,    88,
      91,    94,    93,    97,    98,    96,   104,     0,     0,     0,
       0,     0,    53,    76,   107,    37,    47,     0,    10,    57,
      58,    79,     0,    35,     0,    60,    63,     9,     0,    55,
      78,     0,     0,     0,     0,    77,    65,    33,    19,    63,
      18,    17,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    75,    72,     0,   117,    64,     0,
      62,    43,    21,    25,    23,    32,    31,    26,    20,    22,
       0,    36,    47,    74,     0,     0,    57,    46,    75,     0,
      56,     0,     0,     0,    27,    18,     0,    75,     0,     0,
      32,    30,    15,     0,     0,    28,    73,     0,     0,     0,
      14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,   245,  -179,     0,  -179,    12,   -39,  -116,  -178,
    -179,  -179,  -179,   -30,  -179,    94,    -5,   126,  -179,    79,
    -101,    -4,  -179,   -89,  -179,    83,  -179,  -179,   117,  -179,
    -122,  -121,  -179,    -3,  -166,  -179,  -163,   127,   -93,  -179,
     197,   199,   -13,   201,  -179,   130,   150,  -179,     4,   190,
    -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    41,     7,   148,   193,   149,   150,
     151,   202,   177,    42,    43,   133,   100,   153,    26,   135,
     101,   102,    44,    92,    93,   139,     9,    89,   154,   155,
      45,    46,    47,    94,   158,   165,   184,    97,   122,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     160
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    63,   119,   123,    63,     6,    63,     1,    21,    22,
      10,   195,     8,    25,   156,   157,   126,     8,   195,    27,
      48,    68,    11,   196,    61,   191,    69,   156,   157,   195,
     196,   195,    66,    28,   203,     2,   156,   157,   140,    70,
      71,   196,   176,   196,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,     2,    76,
      88,    77,   182,   105,   106,    96,    98,   156,   157,    99,
      29,    13,   180,   194,   156,   157,   143,   156,   157,   144,
     176,   145,   146,   205,    30,   156,   157,   156,   157,    23,
     169,   194,    60,   205,   143,    73,   136,   192,    31,   145,
     146,    62,    72,    32,    74,    68,   152,    75,    87,   175,
      69,    90,   127,    33,   136,     2,    34,    95,   131,   152,
     117,   118,    35,    70,    71,    91,   128,   200,   152,   141,
      36,   120,   143,     2,   142,   144,   147,   145,   146,   124,
     159,   121,    96,   168,     2,    37,    38,    39,    40,   147,
     125,   129,   136,   159,    82,   130,   132,   201,   147,   152,
     134,   183,   159,   185,    21,    22,   152,   136,   208,   152,
     210,     2,    83,    31,    84,    85,    86,   152,    32,   152,
     138,    64,   162,   161,    65,   183,    67,   163,    33,   147,
     164,    34,   166,   159,   183,   204,   147,    35,    32,   147,
     159,   172,   171,   159,   173,    36,   189,   147,    33,   147,
     174,   159,   178,   159,   113,   114,   115,    35,   198,     2,
      37,    38,    39,    40,   143,    78,    79,   192,   179,   145,
     146,   186,   188,   199,    80,    81,   197,   -16,   -29,     2,
      37,    38,    39,    40,   136,    14,   206,   207,    15,    16,
      12,   209,    17,   137,    18,    14,   181,    19,    15,    16,
      20,   187,    17,     2,    15,    16,   170,    19,    17,   190,
      20,   103,   167,    19,   104,     0,    20,   116,    24,   107,
     108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
       0,    31,    91,    96,    34,     5,    36,     0,    13,    13,
       0,   189,     0,    18,   136,   136,   117,     5,   196,    31,
      23,    29,     0,   189,    27,   188,    34,   149,   149,   207,
     196,   209,    35,    45,   197,    51,   158,   158,   131,    47,
      48,   207,   158,   209,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    51,    36,
      60,    38,   163,    76,    77,    68,    69,   189,   189,    72,
      31,    14,   161,   189,   196,   196,    12,   199,   199,    15,
     196,    17,    18,   199,    45,   207,   207,   209,   209,    34,
      14,   207,    29,   209,    12,    35,    32,    15,     5,    17,
      18,    32,    31,    10,    43,    29,   136,    42,    28,    45,
      34,    45,    31,    20,    32,    51,    23,    30,   121,   149,
      14,    30,    29,    47,    48,    32,    45,    45,   158,   132,
      37,    33,    12,    51,   134,    15,   136,    17,    18,    30,
     136,    46,   145,   146,    51,    52,    53,    54,    55,   149,
      35,    33,    32,   149,     5,    45,    34,   196,   158,   189,
      46,   164,   158,   166,   169,   169,   196,    32,   207,   199,
     209,    51,    23,     5,    25,    26,    27,   207,    10,   209,
      46,    31,    35,    32,    34,   188,    36,    14,    20,   189,
      29,    23,    29,   189,   197,   198,   196,    29,    10,   199,
     196,    45,    33,   199,    45,    37,    30,   207,    20,   209,
      45,   207,    45,   209,    84,    85,    86,    29,    29,    51,
      52,    53,    54,    55,    12,    40,    41,    15,    45,    17,
      18,    33,    45,     9,    49,    50,    45,     9,     9,    51,
      52,    53,    54,    55,    32,     4,    30,    30,     7,     8,
       5,     9,    11,   127,    13,     4,   162,    16,     7,     8,
      19,   182,    11,    51,     7,     8,   149,    16,    11,   186,
      19,    74,   145,    16,    75,    -1,    19,    87,    21,    78,
      79,    80,    81,    82,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,    51,    57,    58,    59,    60,    61,    62,    82,
       0,     0,    58,    14,     4,     7,     8,    11,    13,    16,
      19,    72,    77,    34,    21,    72,    74,    31,    45,    31,
      45,     5,    10,    20,    23,    29,    37,    52,    53,    54,
      55,    60,    69,    70,    78,    86,    87,    88,    89,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      29,    89,    32,    69,   102,   102,    89,   102,    29,    34,
      47,    48,    31,    35,    43,    42,    36,    38,    40,    41,
      49,    50,     5,    23,    25,    26,    27,    28,    60,    83,
      45,    32,    79,    80,    89,    30,    89,    93,    89,    89,
      72,    76,    77,    96,    97,    98,    98,    99,    99,    99,
      99,    99,    99,   101,   101,   101,   105,    14,    30,    79,
      33,    46,    94,    94,    30,    35,    76,    31,    45,    33,
      45,    89,    34,    71,    46,    75,    32,    73,    46,    81,
      94,    89,    60,    12,    15,    17,    18,    60,    62,    64,
      65,    66,    69,    73,    84,    85,    86,    87,    90,   104,
     106,    32,    35,    14,    29,    91,    29,    93,    89,    14,
      84,    33,    45,    45,    45,    45,    64,    68,    45,    45,
      79,    71,    76,    89,    92,    89,    33,    75,    45,    30,
      81,    92,    15,    63,    64,    65,    90,    45,    29,     9,
      45,    63,    67,    92,    89,    64,    30,    30,    63,     9,
      63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    59,    59,    60,    61,
      61,    62,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    87,    87,    88,
      89,    89,    90,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    98,    98,    98,
      98,    98,    99,    99,    99,   100,   100,   100,   100,   101,
     101,   101,   101,   102,   102,   103,   103,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     9,
       8,     4,     6,     1,     7,     2,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     5,     7,     1,
       1,     1,     1,     1,     1,     5,     4,     0,     1,     1,
       1,     1,     1,     3,     1,     1,     5,     0,     1,     1,
       5,     1,     0,     2,     1,     4,     5,     0,     8,     4,
       4,     0,     2,     0,     2,     1,     3,     2,     2,     1,
       1,     1,     2,     7,     1,     0,     2,     0,     3,     0,
       1,     3,     1,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 97 "parser.bison" /* yacc.c:1646  */
    { parser_result = (yyvsp[-1].decl); return 0; }
#line 1468 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 98 "parser.bison" /* yacc.c:1646  */
    { return 0; }
#line 1474 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next = (yyvsp[0].decl);}
#line 1480 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[0].decl);}
#line 1486 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[0].decl);}
#line 1492 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[0].decl);}
#line 1498 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "parser.bison" /* yacc.c:1646  */
    {(yyval.name) = strdup(yytext);}
#line 1504 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-8].name) , type_create(TYPE_FUNCTION, (yyvsp[-5].type), (yyvsp[-3].param_list), 0), 0, (yyvsp[0].stmt), 0);}
#line 1510 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = decl_create((yyvsp[-7].name), type_create(TYPE_FUNCTION, (yyvsp[-4].type), (yyvsp[-2].param_list), 0), 0,  0, 0);}
#line 1516 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = decl_create((yyvsp[-3].name), (yyvsp[-1].type), 0, 0, 0 );}
#line 1522 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].name), (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0 );}
#line 1528 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[0].decl);}
#line 1534 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0);}
#line 1540 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "parser.bison" /* yacc.c:1646  */
    {(yyvsp[-1].stmt)->body = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt);}
#line 1546 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 124 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1552 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1558 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1564 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0);}
#line 1570 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 132 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1576 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[-1].stmt);}
#line 1582 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 134 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[-1].stmt);}
#line 1588 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1594 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt);}
#line 1600 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1606 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 140 "parser.bison" /* yacc.c:1646  */
    {(yyvsp[-1].stmt)->body = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt);}
#line 1612 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 141 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0, 0);}
#line 1618 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 142 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0);}
#line 1624 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 146 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = 0;}
#line 1630 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1636 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1642 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 151 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = 0;}
#line 1648 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 154 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_ident((yyvsp[0].name));}
#line 1654 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 155 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1660 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARRAY_ACCESS, expr_create_ident((yyvsp[-4].name)), expr_create(EXPR_NESTED_ARRAY_ACCESS,  (yyvsp[-2].expr), (yyvsp[0].expr)));}
#line 1666 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NESTED_ARRAY_ACCESS, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1672 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1678 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0);	}
#line 1684 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FLOAT, 0, 0, 0);	}
#line 1690 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, 0, 0, 0);	}
#line 1696 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 168 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0);	}
#line 1702 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 169 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHAR, 0, 0, 0);	}
#line 1708 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 172 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0);}
#line 1714 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 175 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);	}
#line 1720 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 176 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0);	}
#line 1726 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = param_list_create((yyvsp[-3].name), (yyvsp[-1].type), (yyvsp[0].param_list));}
#line 1732 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = 0;}
#line 1738 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 183 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);	}
#line 1744 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 184 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1750 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 187 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), 0, (yyvsp[-2].expr));}
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 190 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1762 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 191 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1768 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 194 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 1774 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 195 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1780 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 198 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NESTED_BRACES, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1786 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 201 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NESTED_BRACES, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1792 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 202 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1798 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 205 "parser.bison" /* yacc.c:1646  */
    {struct expr* temp = expr_create(EXPR_ARRAY_BRACES, (yyvsp[-2].expr), 0); (yyval.decl) = decl_create((yyvsp[-7].name), (yyvsp[-5].type), temp, 0, 0 );}
#line 1804 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 206 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = decl_create((yyvsp[-3].name), (yyvsp[-1].type), 0, 0, 0);}
#line 1810 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 210 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = param_list_create((yyvsp[-3].name), (yyvsp[-1].type), (yyvsp[0].param_list)); }
#line 1816 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 211 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = 0;}
#line 1822 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 215 "parser.bison" /* yacc.c:1646  */
    {(yyvsp[-1].stmt)->next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1828 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 216 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = 0;}
#line 1834 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 221 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[0].expr), 0, 0, 0, 0);}
#line 1840 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 222 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0);}
#line 1846 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 225 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1852 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 228 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create( EXPR_INC, expr_create_ident((yyvsp[-1].name)), 0 ); }
#line 1858 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 229 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create( EXPR_DEC, expr_create_ident((yyvsp[-1].name)), 0 ); }
#line 1864 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 232 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1870 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 235 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1876 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 236 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1882 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 239 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1888 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 242 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), 0, 0, 0); }
#line 1894 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 245 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1900 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 246 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1906 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 249 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_LIST, (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 1912 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 250 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1918 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 253 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_LIST, (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 1924 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 254 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1930 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 257 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1936 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 258 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1942 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 261 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1948 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 262 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1954 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 265 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1960 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 266 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NOT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1966 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 267 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1972 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 270 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1978 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 271 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_LTE, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1984 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 272 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1990 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 273 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1996 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 274 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_GTE, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2002 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 277 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2008 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 278 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2014 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 279 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2020 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 282 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2026 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 283 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2032 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 284 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2038 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 285 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2044 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 288 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2050 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 289 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NOT, (yyvsp[0].expr), 0);}
#line 2056 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 290 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NEG, (yyvsp[0].expr), 0);}
#line 2062 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 291 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_POS, (yyvsp[0].expr), 0);}
#line 2068 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 294 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2074 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 295 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2080 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 298 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_boolean_literal(1);}
#line 2086 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 299 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_boolean_literal(0);}
#line 2092 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 303 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_FUNC_CALL, expr_create_ident((yyvsp[-3].name)), (yyvsp[-1].expr));}
#line 2098 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 306 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_string_literal(strdup(yytext));}
#line 2104 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 307 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_integer_literal(atoi(yytext)); }
#line 2110 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 308 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_char_literal(yytext);}
#line 2116 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 309 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_float_literal(atof(yytext));}
#line 2122 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 310 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2128 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 311 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2134 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 312 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2140 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 313 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2146 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 314 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_PAREN, (yyvsp[-1].expr), 0);}
#line 2152 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 317 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[0].expr), 0, 0, 0, 0);}
#line 2158 "parser.c" /* yacc.c:1646  */
    break;


#line 2162 "parser.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 320 "parser.bison" /* yacc.c:1906  */


// describing error case
int yyerror( char *s ) {
    printf("parse error: %s\n",s);
    return 1;
}
