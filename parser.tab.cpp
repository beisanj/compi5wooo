/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

    #include <stdio.h>
    #include "symbol_table.h"
    #include "hw3_output.hpp"
    #include "llvmCodeGen.h"
    #include "cg.hpp"
    #include "types.h"
    #include <iostream>
    extern int yylineno;
    extern char* yytext;
    int yylex();
    CodeBuffer &cb= CodeBuffer::instance();
     symbolTable* table;
     llvmCodeGen* cgen;
    int yyerror(const char* message);
    extern bool isLoop;
     using namespace output;
     using namespace std;

#line 91 "parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_OR = 4,                         /* OR  */
  YYSYMBOL_AND = 5,                        /* AND  */
  YYSYMBOL_RELOP_EQUAL = 6,                /* RELOP_EQUAL  */
  YYSYMBOL_RELOP_GREATER = 7,              /* RELOP_GREATER  */
  YYSYMBOL_ADD_SUB = 8,                    /* ADD_SUB  */
  YYSYMBOL_MULT_DIV = 9,                   /* MULT_DIV  */
  YYSYMBOL_NOT = 10,                       /* NOT  */
  YYSYMBOL_RPAREN = 11,                    /* RPAREN  */
  YYSYMBOL_LPAREN = 12,                    /* LPAREN  */
  YYSYMBOL_RBRACE = 13,                    /* RBRACE  */
  YYSYMBOL_LBRACE = 14,                    /* LBRACE  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_NUM = 19,                       /* NUM  */
  YYSYMBOL_BYTE = 20,                      /* BYTE  */
  YYSYMBOL_BOOL = 21,                      /* BOOL  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_B = 23,                         /* B  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_CONST = 26,                     /* CONST  */
  YYSYMBOL_SC = 27,                        /* SC  */
  YYSYMBOL_CONTINUE = 28,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_Statements = 34,                /* Statements  */
  YYSYMBOL_Statement = 35,                 /* Statement  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_Call = 38,                      /* Call  */
  YYSYMBOL_Type = 39,                      /* Type  */
  YYSYMBOL_Exp = 40,                       /* Exp  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_OPENSUBTABLE = 43,              /* OPENSUBTABLE  */
  YYSYMBOL_CLOSESUBTABLE = 44,             /* CLOSESUBTABLE  */
  YYSYMBOL_CHECKIFBOOL = 45                /* CHECKIFBOOL  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    39,    39,    41,    42,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    53,    53,    54,    55,    58,    61,
      62,    63,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    77,    78,    78,    79,    80,    81,
      84,    86,    88
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "OR", "AND",
  "RELOP_EQUAL", "RELOP_GREATER", "ADD_SUB", "MULT_DIV", "NOT", "RPAREN",
  "LPAREN", "RBRACE", "LBRACE", "IF", "ELSE", "STRING", "INT", "NUM",
  "BYTE", "BOOL", "ID", "B", "TRUE", "FALSE", "CONST", "SC", "CONTINUE",
  "BREAK", "RETURN", "WHILE", "$accept", "Program", "Statements",
  "Statement", "$@1", "$@2", "Call", "Type", "Exp", "$@3", "$@4",
  "OPENSUBTABLE", "CLOSESUBTABLE", "CHECKIFBOOL", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      80,   -57,    -8,   -57,   -57,   -57,     6,   -19,   -12,    -2,
      34,    55,    80,   -57,    29,    38,    80,    49,    49,    49,
     -57,   -57,   -57,    49,   -57,   -57,   -57,     3,    62,    49,
      95,   -57,    40,    52,   -57,   -57,   -57,   133,    46,    35,
     117,   133,    49,   -57,   -57,   -57,    54,   125,   -57,   -57,
     -57,    49,    49,    49,    49,   -57,   -57,   -57,    68,    45,
     -57,    49,   -57,    49,    49,    14,     2,    76,   -57,    80,
     -57,   -57,   -57,   138,    25,   -57,   -57,    70,    80,   -57,
     -57,    80,   -57,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    40,     0,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
      17,    16,    10,     0,     1,     4,     9,     0,     0,     0,
       0,    29,    27,    25,    30,    31,    26,    42,     0,     0,
       0,    13,     0,     6,    41,    32,     0,     0,    28,    35,
      33,     0,     0,     0,     0,    40,     8,    18,     0,     0,
       5,     0,    22,     0,     0,    38,    37,    23,    24,     0,
      40,     7,    39,    36,    34,    41,    14,    12,     0,    40,
      41,     0,    15,    41,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,    71,   -11,   -57,   -57,     0,    58,   -16,   -57,
     -57,   -50,   -56,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    58,    78,    36,    15,    37,    64,
      63,    16,    60,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    25,    39,    40,    17,    69,    42,    41,    20,    18,
      53,    54,    14,    45,    47,    21,    14,    25,    19,    77,
      76,    52,    53,    54,    82,    22,    59,    84,    14,    81,
      43,    51,    52,    53,    54,    65,    66,    67,    68,    49,
      50,    51,    52,    53,    54,    72,    23,    73,    74,    49,
      50,    51,    52,    53,    54,    24,    26,    55,    75,    29,
      27,    30,    56,    48,    19,    61,    31,    80,    32,    14,
      83,    33,    71,    34,    35,    44,     1,     2,    14,    70,
       3,    14,     4,     5,     6,    54,    79,    28,    46,     0,
       7,     8,     9,    10,     1,     2,     0,     0,     3,     0,
       4,     5,     6,     0,     0,    29,     0,    30,     7,     8,
       9,    10,    31,     3,    32,     4,     5,    33,     0,    34,
      35,    49,    50,    51,    52,    53,    54,     0,    57,    49,
      50,    51,    52,    53,    54,     0,    62,    49,    50,    51,
      52,    53,    54,    50,    51,    52,    53,    54
};

static const yytype_int8 yycheck[] =
{
       0,    12,    18,    19,    12,    55,     3,    23,    27,     3,
       8,     9,    12,    29,    30,    27,    16,    28,    12,    75,
      70,     7,     8,     9,    80,    27,    42,    83,    28,    79,
      27,     6,     7,     8,     9,    51,    52,    53,    54,     4,
       5,     6,     7,     8,     9,    61,    12,    63,    64,     4,
       5,     6,     7,     8,     9,     0,    27,    11,    69,    10,
      22,    12,    27,    23,    12,    11,    17,    78,    19,    69,
      81,    22,    27,    24,    25,    13,    14,    15,    78,    11,
      18,    81,    20,    21,    22,     9,    16,    16,    30,    -1,
      28,    29,    30,    31,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    22,    -1,    -1,    10,    -1,    12,    28,    29,
      30,    31,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,     4,     5,     6,     7,     8,     9,    -1,    11,     4,
       5,     6,     7,     8,     9,    -1,    11,     4,     5,     6,
       7,     8,     9,     5,     6,     7,     8,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    18,    20,    21,    22,    28,    29,    30,
      31,    33,    34,    35,    38,    39,    43,    12,     3,    12,
      27,    27,    27,    12,     0,    35,    27,    22,    34,    10,
      12,    17,    19,    22,    24,    25,    38,    40,    45,    40,
      40,    40,     3,    27,    13,    40,    39,    40,    23,     4,
       5,     6,     7,     8,     9,    11,    27,    11,    36,    40,
      44,    11,    11,    42,    41,    40,    40,    40,    40,    43,
      11,    27,    40,    40,    40,    35,    43,    44,    37,    16,
      35,    43,    44,    35,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    36,    37,    35,    35,    35,    38,    39,
      39,    39,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    41,    40,    42,    40,    40,    40,    40,
      43,    44,    45
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     3,     5,     4,     2,
       2,    11,     7,     0,     0,     9,     2,     2,     4,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     2,     1,
       1,     1,     2,     0,     4,     0,     4,     3,     3,     4,
       0,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: Statements  */
#line 39 "parser.ypp"
                                                                    {}
#line 1193 "parser.tab.cpp"
    break;

  case 3: /* Statements: Statement  */
#line 41 "parser.ypp"
                                                                    {}
#line 1199 "parser.tab.cpp"
    break;

  case 4: /* Statements: Statements Statement  */
#line 42 "parser.ypp"
                                                                    {}
#line 1205 "parser.tab.cpp"
    break;

  case 5: /* Statement: LBRACE OPENSUBTABLE Statements RBRACE CLOSESUBTABLE  */
#line 45 "parser.ypp"
                                                                                             {}
#line 1211 "parser.tab.cpp"
    break;

  case 6: /* Statement: Type ID SC  */
#line 46 "parser.ypp"
                                                                    {checkIfCanDefine(yyvsp[-1]->name); table->SubTables.back()->addSymbol(yyvsp[-1]->name,yyvsp[-2]->name,1);}
#line 1217 "parser.tab.cpp"
    break;

  case 7: /* Statement: Type ID ASSIGN Exp SC  */
#line 47 "parser.ypp"
                                   { checkIfCanDefine(yyvsp[-3]->name);  table->SubTables.back()->addSymbol(yyvsp[-3]->name,yyvsp[-4]->name,1);  Node* node= checkIfLegalCastingWithBool(yyvsp[-3],yyvsp[-1]);}
#line 1223 "parser.tab.cpp"
    break;

  case 8: /* Statement: ID ASSIGN Exp SC  */
#line 48 "parser.ypp"
                                                                    {checkIfDefinedID(yyvsp[-3]); Node* node=checkIfLegalCastingWithBool(yyvsp[-3],yyvsp[-1]); }
#line 1229 "parser.tab.cpp"
    break;

  case 9: /* Statement: Call SC  */
#line 49 "parser.ypp"
                                                                    {yyval = yyvsp[-1];}
#line 1235 "parser.tab.cpp"
    break;

  case 10: /* Statement: RETURN SC  */
#line 50 "parser.ypp"
                                                                    {}
#line 1241 "parser.tab.cpp"
    break;

  case 11: /* Statement: IF LPAREN CHECKIFBOOL RPAREN OPENSUBTABLE Statement CLOSESUBTABLE ELSE OPENSUBTABLE Statement CLOSESUBTABLE  */
#line 51 "parser.ypp"
                                                                                                                         {}
#line 1247 "parser.tab.cpp"
    break;

  case 12: /* Statement: IF LPAREN CHECKIFBOOL RPAREN OPENSUBTABLE Statement CLOSESUBTABLE  */
#line 52 "parser.ypp"
                                                                                {}
#line 1253 "parser.tab.cpp"
    break;

  case 13: /* $@1: %empty  */
#line 53 "parser.ypp"
                              {checkIfBool(yyvsp[0]);}
#line 1259 "parser.tab.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 53 "parser.ypp"
                                                                     {isLoop=true;}
#line 1265 "parser.tab.cpp"
    break;

  case 15: /* Statement: WHILE LPAREN Exp $@1 RPAREN OPENSUBTABLE $@2 Statement CLOSESUBTABLE  */
#line 53 "parser.ypp"
                                                                                                             {isLoop=false;}
#line 1271 "parser.tab.cpp"
    break;

  case 16: /* Statement: BREAK SC  */
#line 54 "parser.ypp"
                                                                    {if(!isLoop) {errorUnexpectedBreak(yylineno);exit(0);}}
#line 1277 "parser.tab.cpp"
    break;

  case 17: /* Statement: CONTINUE SC  */
#line 55 "parser.ypp"
                                                                    {if(!isLoop) { errorUnexpectedContinue(yylineno);exit(0);}}
#line 1283 "parser.tab.cpp"
    break;

  case 18: /* Call: ID LPAREN Exp RPAREN  */
#line 58 "parser.ypp"
                                                                   {yyval=table->checkIfLegalFunction(yyvsp[-3]->name,yyvsp[-1]); }
#line 1289 "parser.tab.cpp"
    break;

  case 19: /* Type: INT  */
#line 61 "parser.ypp"
                                                                    {yyval= new Num(yyvsp[0]->name); }
#line 1295 "parser.tab.cpp"
    break;

  case 20: /* Type: BYTE  */
#line 62 "parser.ypp"
                                                                    {yyval= new NumB(yyvsp[0]->name);}
#line 1301 "parser.tab.cpp"
    break;

  case 21: /* Type: BOOL  */
#line 63 "parser.ypp"
                                                                    {yyval= new Bool(yyvsp[0]->name);}
#line 1307 "parser.tab.cpp"
    break;

  case 22: /* Exp: LPAREN Exp RPAREN  */
#line 66 "parser.ypp"
                                                                    {yyval=yyvsp[-1];}
#line 1313 "parser.tab.cpp"
    break;

  case 23: /* Exp: Exp ADD_SUB Exp  */
#line 67 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]);checkIfOpIsIntOrByte(yyvsp[0]);createRes(yyvsp[-2],yyvsp[0],yyval); emitBinop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval); }
#line 1319 "parser.tab.cpp"
    break;

  case 24: /* Exp: Exp MULT_DIV Exp  */
#line 68 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]);checkIfOpIsIntOrByte(yyvsp[0]);createRes(yyvsp[-2],yyvsp[0],yyval); emitBinop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval); }
#line 1325 "parser.tab.cpp"
    break;

  case 25: /* Exp: ID  */
#line 69 "parser.ypp"
                                                                    { checkIfDefinedID(yyvsp[0]); yyval= new IDClass(yyvsp[0]);}
#line 1331 "parser.tab.cpp"
    break;

  case 26: /* Exp: Call  */
#line 70 "parser.ypp"
                                                                    { yyval=new Node(yyvsp[0]); }
#line 1337 "parser.tab.cpp"
    break;

  case 27: /* Exp: NUM  */
#line 71 "parser.ypp"
                                                                    {yyval = new Num(yyvsp[0]->name); emitNum(yyval);}
#line 1343 "parser.tab.cpp"
    break;

  case 28: /* Exp: NUM B  */
#line 72 "parser.ypp"
                                                                    {checkIfLegalByte(yyvsp[-1]->name); yyval = new NumB(yyvsp[-1]->name); emitNum(yyval);}
#line 1349 "parser.tab.cpp"
    break;

  case 29: /* Exp: STRING  */
#line 73 "parser.ypp"
                                                                    {yyval = new STRINGClass(yyvsp[0]->name);}
#line 1355 "parser.tab.cpp"
    break;

  case 30: /* Exp: TRUE  */
#line 74 "parser.ypp"
                                                                    {yyval = new Bool(yyvsp[0]->name); yyval->t_label=cb.freshLabel();yyval->f_label=cb.freshLabel();  cb.emit("br label "+yyval->t_label);}
#line 1361 "parser.tab.cpp"
    break;

  case 31: /* Exp: FALSE  */
#line 75 "parser.ypp"
                                                                    {yyval = new Bool(yyvsp[0]->name);yyval->t_label=cb.freshLabel();yyval->f_label=cb.freshLabel(); cb.emit("br label "+yyval->f_label);}
#line 1367 "parser.tab.cpp"
    break;

  case 32: /* Exp: NOT Exp  */
#line 76 "parser.ypp"
                                                                    { checkIfBool(yyvsp[0]); string realVal= (yyvsp[0]->value=="false")? "true":"false"; yyval=new Bool(realVal); yyval->t_label=yyvsp[0]->f_label; yyval->f_label=yyvsp[0]->t_label; }
#line 1373 "parser.tab.cpp"
    break;

  case 33: /* $@3: %empty  */
#line 77 "parser.ypp"
               {cb.emit(yyvsp[-1]->t_label+":"); }
#line 1379 "parser.tab.cpp"
    break;

  case 34: /* Exp: Exp AND $@3 Exp  */
#line 77 "parser.ypp"
                                                                                                 {checkIfAndOperandsAreBool(yyvsp[-3],yyvsp[0]); string realVal= calculateOp1AndOp2(yyvsp[-3],yyvsp[0]); yyval=new Bool(realVal); yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); cb.emit(yyvsp[-3]->f_label+":"); cb.emit("br label "+yyval->f_label); cb.emit(yyvsp[0]->f_label+":"); cb.emit("br label "+yyval->f_label); cb.emit(yyvsp[0]->t_label+":"); cb.emit("br label "+yyval->t_label); }
#line 1385 "parser.tab.cpp"
    break;

  case 35: /* $@4: %empty  */
#line 78 "parser.ypp"
              {cb.emit(yyvsp[-1]->f_label+":");}
#line 1391 "parser.tab.cpp"
    break;

  case 36: /* Exp: Exp OR $@4 Exp  */
#line 78 "parser.ypp"
                                                                                                {checkIfAndOperandsAreBool(yyvsp[-3],yyvsp[0]); string realVal= calculateOp1OrOp2(yyvsp[-3],yyvsp[0]); yyval=new Bool(realVal); yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); cb.emit(yyvsp[-3]->t_label+":"); cb.emit("br label "+yyval->t_label); cb.emit(yyvsp[0]->f_label+":"); cb.emit("br label "+yyval->f_label); cb.emit(yyvsp[0]->t_label+":"); cb.emit("br label "+yyval->t_label);}
#line 1397 "parser.tab.cpp"
    break;

  case 37: /* Exp: Exp RELOP_GREATER Exp  */
#line 79 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]); checkIfOpIsIntOrByte(yyvsp[0]);   yyval=new Bool("false");  yyval->t_label=yyvsp[-1]->f_label; yyval->f_label=yyvsp[-1]->t_label; emitRelop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval); }
#line 1403 "parser.tab.cpp"
    break;

  case 38: /* Exp: Exp RELOP_EQUAL Exp  */
#line 80 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]); checkIfOpIsIntOrByte(yyvsp[0]);  yyval=new Bool("false"); yyval->t_label=yyvsp[-1]->f_label; yyval->f_label=yyvsp[-1]->t_label;  /*calculateResOfComparison($1,$2,$3);*/emitRelop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval);}
#line 1409 "parser.tab.cpp"
    break;

  case 39: /* Exp: LPAREN Type RPAREN Exp  */
#line 81 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]); checkIfOpIsIntOrByte(yyvsp[0]); yyval=checkIfLegalCasting(yyvsp[-2],yyvsp[0]); }
#line 1415 "parser.tab.cpp"
    break;

  case 40: /* OPENSUBTABLE: %empty  */
#line 84 "parser.ypp"
                    {table->addSubTable();}
#line 1421 "parser.tab.cpp"
    break;

  case 41: /* CLOSESUBTABLE: %empty  */
#line 86 "parser.ypp"
                     {table->removeSubTable();}
#line 1427 "parser.tab.cpp"
    break;

  case 42: /* CHECKIFBOOL: Exp  */
#line 88 "parser.ypp"
                      {checkIfBool(yyvsp[0]); yyval=new Bool("false");}
#line 1433 "parser.tab.cpp"
    break;


#line 1437 "parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 90 "parser.ypp"


int main(){

       table=  new symbolTable();
        llvmCodeGen* cgen= new llvmCodeGen();
        emitInitial();
     int n=yyparse();
        table->removeSubTable();
        closeMain();
        cb.printCodeBuffer();
        cb.printGlobalBuffer();
        return n;
}

int yyerror(const char * message){
	errorSyn(yylineno);
	exit(0);
}
