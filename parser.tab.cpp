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
    extern llvmCodeGen* cg;
    extern std::vector<WhileLabels*> whiles;
    int yylex();
    CodeBuffer &cb= CodeBuffer::instance();
     symbolTable* table;
     llvmCodeGen* cgen;
    int yyerror(const char* message);
    extern int isLoop;
     using namespace output;
     using namespace std;

#line 93 "parser.tab.cpp"

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
  YYSYMBOL_38_3 = 38,                      /* $@3  */
  YYSYMBOL_39_4 = 39,                      /* $@4  */
  YYSYMBOL_Call = 40,                      /* Call  */
  YYSYMBOL_Type = 41,                      /* Type  */
  YYSYMBOL_Exp = 42,                       /* Exp  */
  YYSYMBOL_43_5 = 43,                      /* $@5  */
  YYSYMBOL_44_6 = 44,                      /* $@6  */
  YYSYMBOL_OPENSUBTABLE = 45,              /* OPENSUBTABLE  */
  YYSYMBOL_CLOSESUBTABLE = 46,             /* CLOSESUBTABLE  */
  YYSYMBOL_CHECKIFBOOL = 47,               /* CHECKIFBOOL  */
  YYSYMBOL_M2 = 48,                        /* M2  */
  YYSYMBOL_M3 = 49                         /* M3  */
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
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

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
       0,    41,    41,    43,    44,    47,    48,    49,    50,    51,
      52,    53,    53,    54,    55,    55,    55,    55,    56,    57,
      60,    63,    64,    65,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    79,    80,    80,    81,
      82,    83,    86,    88,    90,    92,    94
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
  "Statement", "$@1", "$@2", "$@3", "$@4", "Call", "Type", "Exp", "$@5",
  "$@6", "OPENSUBTABLE", "CLOSESUBTABLE", "CHECKIFBOOL", "M2", "M3", YY_NULLPTR
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

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -79,   -79,   -79,   -79,   -79,    -5,    -7,    11,    12,
     -79,    40,    83,   -79,    15,   -79,    83,    51,   114,    24,
     -79,   -79,   -79,    53,   -79,   -79,   -79,    42,    65,   114,
     114,    98,   -79,    43,    -5,   -79,   -79,   -79,   136,   114,
     114,    -1,   -79,   152,    56,   -79,    58,   144,   -79,   -79,
     -79,   114,   114,   114,   114,   -79,    41,   152,   114,   -79,
     -79,   -79,   114,   -79,   114,   114,    27,     6,    61,   -79,
     -79,    64,    47,    83,   -79,    52,    16,   -79,   -79,   -79,
     -79,   -79,    83,    60,   -79,   -79,   -79,   -79,    83,   -79,
     -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    42,    46,    21,    22,    23,    46,     0,     0,     0,
      14,     0,     2,     3,     0,    46,     0,     0,     0,     0,
      19,    18,    10,     0,     1,     4,     9,     0,     0,     0,
       0,     0,    31,    29,    27,    32,    33,    28,     0,     0,
       0,     0,    43,    44,     0,    34,     0,     0,    30,    37,
      35,     0,     0,     0,     0,    20,     0,    15,     0,     6,
       5,    42,     0,    24,     0,     0,    40,    39,    25,    26,
       8,     0,     0,     0,    41,    38,    36,    42,     7,    45,
      16,    43,     0,    13,    43,    42,    17,    11,     0,    43,
      12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,    68,   -11,   -79,   -79,   -79,   -79,     0,    50,
     -21,   -79,   -79,   -56,   -78,   -79,   -79,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    88,    23,    71,    82,    37,    15,
      38,    65,    64,    16,    60,    44,    81,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    25,    58,    83,    19,    73,    86,    18,    43,    45,
      47,    90,    14,    27,    53,    54,    14,    25,    56,    57,
      20,    80,    51,    52,    53,    54,    59,    39,    14,    87,
      66,    67,    68,    69,    52,    53,    54,    72,    21,    22,
      24,    74,    26,    75,    76,    49,    50,    51,    52,    53,
      54,    49,    50,    51,    52,    53,    54,    50,    51,    52,
      53,    54,    79,    29,    41,    40,    48,    61,    70,    62,
      54,    84,     0,    14,    78,    77,    85,    89,    42,     1,
       2,    46,    14,     3,    28,     4,     5,     6,    14,     0,
       0,     0,     0,     7,     8,     9,    10,     1,     2,     0,
       0,     3,     0,     4,     5,     6,     0,     0,    30,     0,
      31,     7,     8,     9,    10,    32,     3,    33,     4,     5,
      34,     0,    35,    36,    30,     0,    31,     0,     0,     0,
       0,    32,     0,    33,     0,     0,    34,     0,    35,    36,
      49,    50,    51,    52,    53,    54,     0,    55,    49,    50,
      51,    52,    53,    54,     0,    63,    49,    50,    51,    52,
      53,    54
};

static const yytype_int8 yycheck[] =
{
       0,    12,     3,    81,     6,    61,    84,    12,    29,    30,
      31,    89,    12,    15,     8,     9,    16,    28,    39,    40,
      27,    77,     6,     7,     8,     9,    27,     3,    28,    85,
      51,    52,    53,    54,     7,     8,     9,    58,    27,    27,
       0,    62,    27,    64,    65,     4,     5,     6,     7,     8,
       9,     4,     5,     6,     7,     8,     9,     5,     6,     7,
       8,     9,    73,    12,    22,    12,    23,    11,    27,    11,
       9,    82,    -1,    73,    27,    11,    16,    88,    13,    14,
      15,    31,    82,    18,    16,    20,    21,    22,    88,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    -1,    -1,    10,    -1,
      12,    28,    29,    30,    31,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    10,    -1,    12,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22,    -1,    24,    25,
       4,     5,     6,     7,     8,     9,    -1,    11,     4,     5,
       6,     7,     8,     9,    -1,    11,     4,     5,     6,     7,
       8,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    18,    20,    21,    22,    28,    29,    30,
      31,    33,    34,    35,    40,    41,    45,    49,    12,    49,
      27,    27,    27,    37,     0,    35,    27,    49,    34,    12,
      10,    12,    17,    19,    22,    24,    25,    40,    42,     3,
      12,    22,    13,    42,    47,    42,    41,    42,    23,     4,
       5,     6,     7,     8,     9,    11,    42,    42,     3,    27,
      46,    11,    11,    11,    44,    43,    42,    42,    42,    42,
      27,    38,    42,    45,    42,    42,    42,    11,    27,    35,
      45,    48,    39,    46,    35,    16,    46,    45,    36,    35,
      46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    36,    35,    35,    37,    38,    39,    35,    35,    35,
      40,    41,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    43,    42,    44,    42,    42,
      42,    42,    45,    46,    47,    48,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     4,     6,     5,     2,
       2,     0,    14,     9,     0,     0,     0,    10,     2,     2,
       4,     1,     1,     1,     3,     3,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     0,     4,     0,     4,     3,
       3,     4,     0,     0,     1,     0,     0
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
#line 41 "parser.ypp"
                                                                    {}
#line 1206 "parser.tab.cpp"
    break;

  case 3: /* Statements: Statement  */
#line 43 "parser.ypp"
                                                                    {}
#line 1212 "parser.tab.cpp"
    break;

  case 4: /* Statements: Statements Statement  */
#line 44 "parser.ypp"
                                                                    {}
#line 1218 "parser.tab.cpp"
    break;

  case 5: /* Statement: LBRACE OPENSUBTABLE Statements RBRACE CLOSESUBTABLE  */
#line 47 "parser.ypp"
                                                                                             {}
#line 1224 "parser.tab.cpp"
    break;

  case 6: /* Statement: Type M3 ID SC  */
#line 48 "parser.ypp"
                                                                        {checkIfCanDefine(yyvsp[-1]->name); table->SubTables.back()->addSymbol(yyvsp[-1]->name,yyvsp[-3]->name,1); int offset=table->getOffset(yyvsp[-1]->name); emitStoreDefault(yyval,offset);}
#line 1230 "parser.tab.cpp"
    break;

  case 7: /* Statement: Type M3 ID ASSIGN Exp SC  */
#line 49 "parser.ypp"
                                      { checkIfCanDefine(yyvsp[-3]->name); table->SubTables.back()->addSymbol(yyvsp[-3]->name,yyvsp[-5]->name,1);Node* node= checkIfLegalCastingWithBool(yyvsp[-3],yyvsp[-1]); int offset=table->getOffset(yyvsp[-3]->name); if(yyvsp[-1]->name=="BOOL"){emitPhiVal(yyvsp[-1]); } emitStore(yyvsp[-1],offset);}
#line 1236 "parser.tab.cpp"
    break;

  case 8: /* Statement: ID M3 ASSIGN Exp SC  */
#line 50 "parser.ypp"
                                                                       {checkIfDefinedID(yyvsp[-4]); Node* node=checkIfLegalCastingWithBool(yyvsp[-4],yyvsp[-1]); int offset=table->getOffset(yyvsp[-4]->name); if(yyvsp[-1]->name=="BOOL"){emitPhiVal(yyvsp[-1]);} emitStore(yyvsp[-1],offset); }
#line 1242 "parser.tab.cpp"
    break;

  case 9: /* Statement: Call SC  */
#line 51 "parser.ypp"
                                                                    {yyval = yyvsp[-1];}
#line 1248 "parser.tab.cpp"
    break;

  case 10: /* Statement: RETURN SC  */
#line 52 "parser.ypp"
                                                                    {cb.emit("ret i32 0");}
#line 1254 "parser.tab.cpp"
    break;

  case 11: /* $@1: %empty  */
#line 53 "parser.ypp"
                                                                                                        {cb.emit("br label %"+yyvsp[-7]->f_label); cb.emit(yyvsp[-7]->f_label+":");}
#line 1260 "parser.tab.cpp"
    break;

  case 12: /* Statement: IF M3 LPAREN CHECKIFBOOL RPAREN OPENSUBTABLE Statement M2 CLOSESUBTABLE ELSE OPENSUBTABLE $@1 Statement CLOSESUBTABLE  */
#line 53 "parser.ypp"
                                                                                                                                                                                               { yyval=new Node("");  yyval->n_label= yyvsp[-6]->n_label; cb.emit("br label %"+yyval->n_label); cb.emit(yyval->n_label+":");}
#line 1266 "parser.tab.cpp"
    break;

  case 13: /* Statement: IF M3 LPAREN CHECKIFBOOL RPAREN OPENSUBTABLE Statement M2 CLOSESUBTABLE  */
#line 54 "parser.ypp"
                                                                                      {yyval=new Node(""); yyval->n_label=yyvsp[-1]->n_label; cb.emit(yyvsp[-5]->f_label+":"); cb.emit("br label %"+yyval->n_label); cb.emit(yyval->n_label+":"); }
#line 1272 "parser.tab.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 55 "parser.ypp"
                    {emitPrepForWhile();}
#line 1278 "parser.tab.cpp"
    break;

  case 15: /* $@3: %empty  */
#line 55 "parser.ypp"
                                                     {checkIfBool(yyvsp[0]); editLabelsOfWhile(yyvsp[0]);}
#line 1284 "parser.tab.cpp"
    break;

  case 16: /* $@4: %empty  */
#line 55 "parser.ypp"
                                                                                                                   {isLoop++;}
#line 1290 "parser.tab.cpp"
    break;

  case 17: /* Statement: WHILE $@2 LPAREN Exp $@3 RPAREN OPENSUBTABLE $@4 Statement CLOSESUBTABLE  */
#line 55 "parser.ypp"
                                                                                                                                                        {isLoop--; emitEndOfWhile();}
#line 1296 "parser.tab.cpp"
    break;

  case 18: /* Statement: BREAK SC  */
#line 56 "parser.ypp"
                                                                    {if(!isLoop) {errorUnexpectedBreak(yylineno);exit(0);} cb.emit("br label %" + cg->whiles.back()->f_label);}
#line 1302 "parser.tab.cpp"
    break;

  case 19: /* Statement: CONTINUE SC  */
#line 57 "parser.ypp"
                                                                    {if(!isLoop) { errorUnexpectedContinue(yylineno);exit(0);} cb.emit("br label %" + cg->whiles.back()->t_label);}
#line 1308 "parser.tab.cpp"
    break;

  case 20: /* Call: ID LPAREN Exp RPAREN  */
#line 60 "parser.ypp"
                                                                   {yyval=table->checkIfLegalFunction(yyvsp[-3]->name,yyvsp[-1]); emitFunctionCall(yyval,yyvsp[-3],yyvsp[-1]); }
#line 1314 "parser.tab.cpp"
    break;

  case 21: /* Type: INT  */
#line 63 "parser.ypp"
                                                                    {yyval= new Num(yyvsp[0]->name); }
#line 1320 "parser.tab.cpp"
    break;

  case 22: /* Type: BYTE  */
#line 64 "parser.ypp"
                                                                    {yyval= new NumB(yyvsp[0]->name);}
#line 1326 "parser.tab.cpp"
    break;

  case 23: /* Type: BOOL  */
#line 65 "parser.ypp"
                                                                    {yyval= new Bool(yyvsp[0]->name);}
#line 1332 "parser.tab.cpp"
    break;

  case 24: /* Exp: LPAREN Exp RPAREN  */
#line 68 "parser.ypp"
                                                                    {yyval=yyvsp[-1];}
#line 1338 "parser.tab.cpp"
    break;

  case 25: /* Exp: Exp ADD_SUB Exp  */
#line 69 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]);checkIfOpIsIntOrByte(yyvsp[0]);createRes(yyvsp[-2],yyvsp[0],yyval); emitBinop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval); }
#line 1344 "parser.tab.cpp"
    break;

  case 26: /* Exp: Exp MULT_DIV Exp  */
#line 70 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]);checkIfOpIsIntOrByte(yyvsp[0]);createRes(yyvsp[-2],yyvsp[0],yyval); emitBinop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval); }
#line 1350 "parser.tab.cpp"
    break;

  case 27: /* Exp: ID  */
#line 71 "parser.ypp"
                                                                    {checkIfDefinedID(yyvsp[0]); yyval= new IDClass(yyvsp[0]); table->getOffset(yyvsp[0]->name); int offset=table->getOffset(yyvsp[0]->name);  if(table->checkIfBool(yyvsp[0]->name)){yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); } emitLocalVar(yyval,offset); if(table->checkIfBool(yyvsp[0]->name)) {emitPrepForBool(yyval);} }
#line 1356 "parser.tab.cpp"
    break;

  case 28: /* Exp: Call  */
#line 72 "parser.ypp"
                                                                    { yyval=new Node(yyvsp[0]); }
#line 1362 "parser.tab.cpp"
    break;

  case 29: /* Exp: NUM  */
#line 73 "parser.ypp"
                                                                    {yyval = new Num(yyvsp[0]->name); emitNum(yyval);  yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel();}
#line 1368 "parser.tab.cpp"
    break;

  case 30: /* Exp: NUM B  */
#line 74 "parser.ypp"
                                                                    {checkIfLegalByte(yyvsp[-1]->name); yyval = new NumB(yyvsp[-1]->name); emitNumB(yyval);  yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel();}
#line 1374 "parser.tab.cpp"
    break;

  case 31: /* Exp: STRING  */
#line 75 "parser.ypp"
                                                                    {yyval = new STRINGClass(yyvsp[0]->name); emitString(yyval);}
#line 1380 "parser.tab.cpp"
    break;

  case 32: /* Exp: TRUE  */
#line 76 "parser.ypp"
                                                                    {yyval = new Bool(yyvsp[0]->name); yyval->t_label=cb.freshLabel();yyval->f_label=cb.freshLabel();  cb.emit("br label %"+yyval->t_label);}
#line 1386 "parser.tab.cpp"
    break;

  case 33: /* Exp: FALSE  */
#line 77 "parser.ypp"
                                                                    {yyval = new Bool(yyvsp[0]->name);yyval->t_label=cb.freshLabel();yyval->f_label=cb.freshLabel(); cb.emit("br label %"+yyval->f_label);}
#line 1392 "parser.tab.cpp"
    break;

  case 34: /* Exp: NOT Exp  */
#line 78 "parser.ypp"
                                                                    { checkIfBool(yyvsp[0]); string realVal= (yyvsp[0]->value=="false")? "true":"false"; yyval=new Bool(realVal); yyval->t_label=yyvsp[0]->f_label; yyval->f_label=yyvsp[0]->t_label; }
#line 1398 "parser.tab.cpp"
    break;

  case 35: /* $@5: %empty  */
#line 79 "parser.ypp"
               {/*cb.emit("br label %"+$1->t_label);*/ cb.emit(yyvsp[-1]->t_label+":"); }
#line 1404 "parser.tab.cpp"
    break;

  case 36: /* Exp: Exp AND $@5 Exp  */
#line 79 "parser.ypp"
                                                                                                                                        {checkIfAndOperandsAreBool(yyvsp[-3],yyvsp[0]); string realVal= calculateOp1AndOp2(yyvsp[-3],yyvsp[0]); yyval=new Bool(realVal); yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); /* cb.emit("br label %"+$$->f_label); */ cb.emit(yyvsp[-3]->f_label+":"); cb.emit("br label %"+yyval->f_label); cb.emit(yyvsp[0]->f_label+":"); cb.emit("br label %"+yyval->f_label); cb.emit(yyvsp[0]->t_label+":"); cb.emit("br label %"+yyval->t_label); }
#line 1410 "parser.tab.cpp"
    break;

  case 37: /* $@6: %empty  */
#line 80 "parser.ypp"
              {/*cb.emit("br label %"+$1->f_label);*/ cb.emit(yyvsp[-1]->f_label+":");}
#line 1416 "parser.tab.cpp"
    break;

  case 38: /* Exp: Exp OR $@6 Exp  */
#line 80 "parser.ypp"
                                                                                                                                       {checkIfAndOperandsAreBool(yyvsp[-3],yyvsp[0]); string realVal= calculateOp1OrOp2(yyvsp[-3],yyvsp[0]); yyval=new Bool(realVal); yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); /* cb.emit("br label %"+$$->f_label); */ cb.emit(yyvsp[-3]->t_label+":"); cb.emit("br label %"+yyval->t_label); cb.emit(yyvsp[0]->f_label+":"); cb.emit("br label %"+yyval->f_label); cb.emit(yyvsp[0]->t_label+":"); cb.emit("br label %"+yyval->t_label);}
#line 1422 "parser.tab.cpp"
    break;

  case 39: /* Exp: Exp RELOP_GREATER Exp  */
#line 81 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]); checkIfOpIsIntOrByte(yyvsp[0]);   yyval=new Bool("false");  /*$$->t_label=$3->t_label; $$->f_label=$3->f_label;*/ yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); yyval->nodereg=cb.freshVar(); emitRelop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval); }
#line 1428 "parser.tab.cpp"
    break;

  case 40: /* Exp: Exp RELOP_EQUAL Exp  */
#line 82 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]); checkIfOpIsIntOrByte(yyvsp[0]);  yyval=new Bool("false"); /*$$->t_label=$3->t_label; $$->f_label=$3->f_label;*/ yyval->t_label=cb.freshLabel(); yyval->f_label=cb.freshLabel(); yyval->nodereg=cb.freshVar(); emitRelop(yyvsp[-2],yyvsp[0],yyvsp[-1],yyval);}
#line 1434 "parser.tab.cpp"
    break;

  case 41: /* Exp: LPAREN Type RPAREN Exp  */
#line 83 "parser.ypp"
                                                                    {checkIfOpIsIntOrByte(yyvsp[-2]); checkIfOpIsIntOrByte(yyvsp[0]); yyval=checkIfLegalCasting(yyvsp[-2],yyvsp[0]); yyval->t_label=yyvsp[0]->t_label; yyval->f_label=yyvsp[0]->f_label; yyval->nodereg=cb.freshVar(); emitConversion(yyval->nodereg,yyvsp[-2],yyvsp[0]); }
#line 1440 "parser.tab.cpp"
    break;

  case 42: /* OPENSUBTABLE: %empty  */
#line 86 "parser.ypp"
                    {table->addSubTable();}
#line 1446 "parser.tab.cpp"
    break;

  case 43: /* CLOSESUBTABLE: %empty  */
#line 88 "parser.ypp"
                     {table->removeSubTable();}
#line 1452 "parser.tab.cpp"
    break;

  case 44: /* CHECKIFBOOL: Exp  */
#line 90 "parser.ypp"
                      {checkIfBool(yyvsp[0]); yyval=new Bool("false"); yyval->t_label= yyvsp[0]->t_label; yyval->f_label=yyvsp[0]->f_label; cb.emit("br label %"+yyval->t_label); cb.emit(yyval->t_label+":"); }
#line 1458 "parser.tab.cpp"
    break;

  case 45: /* M2: %empty  */
#line 92 "parser.ypp"
          {yyval=new Node(""); yyval->n_label=cb.freshLabel(); cb.emit("br label %"+yyval->n_label);}
#line 1464 "parser.tab.cpp"
    break;

  case 46: /* M3: %empty  */
#line 94 "parser.ypp"
          {emitPrepForIf();}
#line 1470 "parser.tab.cpp"
    break;


#line 1474 "parser.tab.cpp"

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

#line 98 "parser.ypp"


int main(){

       table=  new symbolTable();
        llvmCodeGen* cgen= new llvmCodeGen();
        emitInitial();
     int n=yyparse();
        table->removeSubTable();
        closeMain();
        cb.printGlobalBuffer();
        cb.printCodeBuffer();
        return n;
}

int yyerror(const char * message){
	errorSyn(yylineno);
	exit(0);
}
