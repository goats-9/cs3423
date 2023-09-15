/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    /*
    Name    : Gautam Singh
    ID      : CS21BTECH11018
    Date    : 2023-09-14
    File    : parser.y
    Purpose : File to implement a parser for a C-like language.
              Takes program source `source.clike` and does the following:
              1. Outputs the parsed file in the equivalent `source.parsed` file.
              2. Reports syntax errors in the source file.
    */
#line 14 "parser.y"

    /* global includes */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* global extern variables */
    extern FILE *yyin, *tfile, *pfile;

    /* prototypes for yylex and yyerror */
    int yylex();
    int yyerror(char *);

#line 97 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_DTYPE = 4,                      /* DTYPE  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_UNARY_OP = 7,                   /* UNARY_OP  */
  YYSYMBOL_ARTH_OP = 8,                    /* ARTH_OP  */
  YYSYMBOL_UNARY_LOGICAL_OP = 9,           /* UNARY_LOGICAL_OP  */
  YYSYMBOL_BINARY_LOGICAL_OP = 10,         /* BINARY_LOGICAL_OP  */
  YYSYMBOL_LOGICAL_JOIN_OP = 11,           /* LOGICAL_JOIN_OP  */
  YYSYMBOL_GLOBAL = 12,                    /* GLOBAL  */
  YYSYMBOL_LOCAL = 13,                     /* LOCAL  */
  YYSYMBOL_CLASS = 14,                     /* CLASS  */
  YYSYMBOL_DECLARE = 15,                   /* DECLARE  */
  YYSYMBOL_EXPR = 16,                      /* EXPR  */
  YYSYMBOL_TRUE = 17,                      /* TRUE  */
  YYSYMBOL_FALSE = 18,                     /* FALSE  */
  YYSYMBOL_LOOP = 19,                      /* LOOP  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_CALL = 22,                      /* CALL  */
  YYSYMBOL_INCASE = 23,                    /* INCASE  */
  YYSYMBOL_OTHERWISE = 24,                 /* OTHERWISE  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_THIS = 27,                      /* THIS  */
  YYSYMBOL_L_PAREN = 28,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 29,                   /* R_PAREN  */
  YYSYMBOL_L_SQUARE = 30,                  /* L_SQUARE  */
  YYSYMBOL_R_SQUARE = 31,                  /* R_SQUARE  */
  YYSYMBOL_L_BRACE = 32,                   /* L_BRACE  */
  YYSYMBOL_R_BRACE = 33,                   /* R_BRACE  */
  YYSYMBOL_ASGN_OP = 34,                   /* ASGN_OP  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_ARROW = 37,                     /* ARROW  */
  YYSYMBOL_VOID = 38,                      /* VOID  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_program_body = 41,              /* program_body  */
  YYSYMBOL_function = 42,                  /* function  */
  YYSYMBOL_function_definition_global = 43, /* function_definition_global  */
  YYSYMBOL_function_definition_local = 44, /* function_definition_local  */
  YYSYMBOL_function_definition = 45,       /* function_definition  */
  YYSYMBOL_dtype_or_void = 46,             /* dtype_or_void  */
  YYSYMBOL_class = 47,                     /* class  */
  YYSYMBOL_class_definition = 48,          /* class_definition  */
  YYSYMBOL_block_scope = 49,               /* block_scope  */
  YYSYMBOL_args = 50,                      /* args  */
  YYSYMBOL_args_comma = 51,                /* args_comma  */
  YYSYMBOL_num_args = 52,                  /* num_args  */
  YYSYMBOL_blocks = 53,                    /* blocks  */
  YYSYMBOL_block = 54,                     /* block  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_stmt_body = 56,                 /* stmt_body  */
  YYSYMBOL_decl_stmt = 57,                 /* decl_stmt  */
  YYSYMBOL_expr_stmt = 58,                 /* expr_stmt  */
  YYSYMBOL_unary_expr_rhs_body = 59,       /* unary_expr_rhs_body  */
  YYSYMBOL_expr_rhs_body = 60,             /* expr_rhs_body  */
  YYSYMBOL_expr_term = 61,                 /* expr_term  */
  YYSYMBOL_call_stmt = 62,                 /* call_stmt  */
  YYSYMBOL_call_stmt_body = 63,            /* call_stmt_body  */
  YYSYMBOL_method_call = 64,               /* method_call  */
  YYSYMBOL_method_name = 65,               /* method_name  */
  YYSYMBOL_id_or_this = 66,                /* id_or_this  */
  YYSYMBOL_function_call = 67,             /* function_call  */
  YYSYMBOL_call_params = 68,               /* call_params  */
  YYSYMBOL_call_params_comma = 69,         /* call_params_comma  */
  YYSYMBOL_return_stmt = 70,               /* return_stmt  */
  YYSYMBOL_cond_block = 71,                /* cond_block  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_predicate = 73,                 /* predicate  */
  YYSYMBOL_predicate_body_start = 74,      /* predicate_body_start  */
  YYSYMBOL_predicate_term = 75,            /* predicate_term  */
  YYSYMBOL_predicate_body = 76,            /* predicate_body  */
  YYSYMBOL_unary_pred = 77,                /* unary_pred  */
  YYSYMBOL_unary_pred_body = 78,           /* unary_pred_body  */
  YYSYMBOL_loop_block = 79,                /* loop_block  */
  YYSYMBOL_loop_while_block = 80,          /* loop_while_block  */
  YYSYMBOL_81_2 = 81,                      /* $@2  */
  YYSYMBOL_loop_for_block = 82,            /* loop_for_block  */
  YYSYMBOL_83_3 = 83,                      /* $@3  */
  YYSYMBOL_loop_for_update = 84            /* loop_for_update  */
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    75,    76,    77,    82,    83,    86,    89,
      92,    93,    96,    97,   100,   103,   104,   107,   112,   113,
     114,   117,   118,   119,   122,   123,   124,   129,   130,   133,
     134,   135,   136,   137,   140,   143,   144,   145,   146,   151,
     152,   157,   158,   161,   164,   165,   168,   169,   170,   171,
     172,   173,   174,   175,   180,   183,   184,   187,   190,   191,
     194,   195,   196,   199,   202,   203,   204,   207,   208,   209,
     210,   215,   216,   217,   222,   222,   225,   228,   229,   232,
     233,   236,   237,   238,   241,   242,   243,   246,   247,   252,
     253,   254,   257,   257,   260,   260,   263,   264,   265
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "DTYPE", "CONST",
  "NUMBER", "UNARY_OP", "ARTH_OP", "UNARY_LOGICAL_OP", "BINARY_LOGICAL_OP",
  "LOGICAL_JOIN_OP", "GLOBAL", "LOCAL", "CLASS", "DECLARE", "EXPR", "TRUE",
  "FALSE", "LOOP", "WHILE", "DO", "CALL", "INCASE", "OTHERWISE", "RETURN",
  "FOR", "THIS", "L_PAREN", "R_PAREN", "L_SQUARE", "R_SQUARE", "L_BRACE",
  "R_BRACE", "ASGN_OP", "SEMICOLON", "COMMA", "ARROW", "VOID", "$accept",
  "program", "program_body", "function", "function_definition_global",
  "function_definition_local", "function_definition", "dtype_or_void",
  "class", "class_definition", "block_scope", "args", "args_comma",
  "num_args", "blocks", "block", "stmt", "stmt_body", "decl_stmt",
  "expr_stmt", "unary_expr_rhs_body", "expr_rhs_body", "expr_term",
  "call_stmt", "call_stmt_body", "method_call", "method_name",
  "id_or_this", "function_call", "call_params", "call_params_comma",
  "return_stmt", "cond_block", "$@1", "predicate", "predicate_body_start",
  "predicate_term", "predicate_body", "unary_pred", "unary_pred_body",
  "loop_block", "loop_while_block", "$@2", "loop_for_block", "$@3",
  "loop_for_update", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,  -124,     6,     8,     9,  -124,   -16,   109,   -16,  -124,
    -124,  -124,  -124,    33,    21,  -124,   200,   109,  -124,  -124,
      54,  -124,    35,  -124,    79,    49,     6,   121,    67,    68,
      86,    71,    12,    73,  -124,   -16,   -16,  -124,    70,    53,
    -124,    94,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   103,   106,   173,  -124,   135,   136,   107,    71,
    -124,     5,  -124,  -124,  -124,   105,  -124,    99,   119,   110,
    -124,  -124,   118,  -124,  -124,  -124,  -124,  -124,  -124,     7,
    -124,  -124,  -124,  -124,  -124,    30,  -124,   120,  -124,  -124,
     191,   129,   123,    91,    16,   124,  -124,   143,   128,    51,
     149,  -124,  -124,   173,   130,  -124,   161,   138,  -124,   131,
    -124,  -124,  -124,    90,   110,    54,   132,   155,  -124,  -124,
     127,  -124,   127,   -16,   134,    71,    11,  -124,   -16,  -124,
      20,    20,   142,   147,    91,  -124,   148,   131,    51,  -124,
     160,   173,   150,  -124,   182,  -124,  -124,  -124,   116,  -124,
    -124,  -124,    90,  -124,  -124,  -124,   -16,   158,    56,   185,
      20,    20,   164,  -124,  -124,  -124,  -124,   166,    11,  -124,
    -124,  -124,  -124,  -124,   -16,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,     0,     0,     0,     2,     0,     0,     0,    11,
      12,    13,     8,     0,     0,     1,     0,     0,     4,    14,
       0,    26,     0,    15,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,    33,     0,     0,
      29,     0,    35,    36,    41,    37,    38,    30,    31,    89,
      90,     3,     0,     0,     0,     9,     0,     0,     0,     0,
      62,     0,    61,    54,    55,     0,    56,     0,     0,    47,
      49,    50,     0,    51,    52,    72,    53,    71,    48,     0,
       6,     7,    17,    27,    34,     0,    24,     0,    39,    40,
       0,     0,     0,     0,    62,     0,    87,    79,     0,     0,
       0,    85,    74,     0,     0,    20,     0,     0,    43,    45,
      42,    44,    92,     0,    59,     0,     0,     0,    76,    83,
       0,    77,     0,     0,     0,     0,     0,    10,     0,    66,
       0,     0,     0,     0,     0,    88,     0,    86,     0,    80,
       0,     0,     0,    23,     0,    18,    93,    70,     0,    64,
      65,    63,     0,    58,    84,    81,     0,     0,     0,     0,
       0,     0,     0,    75,    46,    98,    96,     0,     0,    67,
      68,    57,    94,    21,     0,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,    66,  -124,    32,  -124,   163,  -124,    42,  -124,
      -8,  -124,    34,   -18,   165,  -124,  -124,  -124,  -124,   126,
     -15,  -124,   -29,  -124,  -124,   176,    69,   -88,  -124,    58,
    -123,  -124,  -124,  -124,   -27,  -124,    97,    82,    89,   104,
    -124,  -124,  -124,  -124,  -124,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    34,     6,    36,    12,    13,     7,     8,
      17,   107,   145,    23,    38,    39,    40,    41,    42,    43,
      76,   110,    96,    45,    63,    78,   115,    65,    66,   132,
     149,    46,    47,   123,    97,    98,    99,   121,   100,   101,
      48,    49,   128,    50,   174,   167
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    44,    52,    77,    68,   116,    21,     9,   150,    15,
      10,    14,   143,    60,    25,    69,    16,    70,    71,    25,
      72,   147,    21,    28,    44,    87,   -86,    80,    81,    73,
      74,   105,    91,   -25,   106,    22,    20,   169,   170,    62,
     -22,    53,   -60,    92,    11,   -78,   116,   144,    35,   -69,
      75,    22,   119,   -25,    24,    21,   148,   165,    37,   -19,
      25,   111,   120,    25,    44,     2,    26,     3,    27,    28,
      58,    35,    29,    18,   124,    30,    31,    54,    32,    33,
     -82,    37,   -25,    51,    22,   -97,   -28,    60,    59,    61,
     135,   129,    60,   130,   114,   135,   131,   133,   142,    67,
      94,    79,    69,    82,    70,    71,    25,    72,    95,    -5,
       1,   -16,   157,    62,   -73,   140,    73,    74,    62,   160,
     146,     2,   161,     3,    56,    57,    62,    67,   137,    84,
      69,    85,    70,    71,    25,    72,    95,    86,    88,    89,
     102,    90,    93,   166,    73,    74,   103,   -60,   163,   108,
     112,   113,   117,   -88,    62,    67,    60,   118,    69,   122,
      70,    71,    25,    72,   126,   125,   175,   127,   -62,   134,
     141,   151,    73,    74,    60,   152,    69,   154,    70,    71,
      25,    72,    62,    67,   156,   158,   159,   164,   168,    55,
      73,    74,   109,   171,    69,   172,    70,    71,    25,    72,
      62,    24,   173,   153,    83,   104,    64,    25,    73,    74,
     162,   139,     2,    26,     3,    27,    28,   138,    62,    29,
     155,   136,    30,    31,     0,    32,    33
};

static const yytype_int16 yycheck[] =
{
       8,    16,    20,    32,    31,    93,     1,     1,   131,     0,
       4,     3,     1,     1,     7,     3,    32,     5,     6,     7,
       8,     1,     1,    16,    39,    54,    10,    35,    36,    17,
      18,     1,    59,    28,     4,    30,     3,   160,   161,    27,
      29,     6,    37,    61,    38,    29,   134,    36,    16,    29,
      38,    30,     1,    32,     1,     1,    36,     1,    16,    29,
       7,    90,    11,     7,    79,    12,    13,    14,    15,    16,
       3,    39,    19,     7,   103,    22,    23,    28,    25,    26,
      29,    39,    28,    17,    30,    29,    33,     1,    20,     3,
     117,     1,     1,     3,     3,   122,     6,   115,   125,    28,
       1,    28,     3,    33,     5,     6,     7,     8,     9,     0,
       1,    32,   141,    27,    35,   123,    17,    18,    27,     3,
     128,    12,     6,    14,     3,     4,    27,    28,     1,    35,
       3,    28,     5,     6,     7,     8,     9,    31,     3,     3,
      21,    34,    37,   158,    17,    18,    28,    37,   156,    29,
      21,    28,    28,    10,    27,    28,     1,    29,     3,    10,
       5,     6,     7,     8,     3,    35,   174,    29,    37,    37,
      36,    29,    17,    18,     1,    28,     3,    29,     5,     6,
       7,     8,    27,    28,    24,    35,     4,    29,     3,    26,
      17,    18,     1,    29,     3,    29,     5,     6,     7,     8,
      27,     1,   168,   134,    39,    79,    30,     7,    17,    18,
     152,   122,    12,    13,    14,    15,    16,   120,    27,    19,
     138,   117,    22,    23,    -1,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    12,    14,    40,    41,    43,    47,    48,     1,
       4,    38,    45,    46,     3,     0,    32,    49,    41,    49,
       3,     1,    30,    52,     1,     7,    13,    15,    16,    19,
      22,    23,    25,    26,    42,    43,    44,    47,    53,    54,
      55,    56,    57,    58,    59,    62,    70,    71,    79,    80,
      82,    41,    52,     6,    28,    45,     3,     4,     3,    20,
       1,     3,    27,    63,    64,    66,    67,    28,    73,     3,
       5,     6,     8,    17,    18,    38,    59,    61,    64,    28,
      49,    49,    33,    53,    35,    28,    31,    61,     3,     3,
      34,    73,    52,    37,     1,     9,    61,    73,    74,    75,
      77,    78,    21,    28,    58,     1,     4,    50,    29,     1,
      60,    61,    21,    28,     3,    65,    66,    28,    29,     1,
      11,    76,    10,    72,    61,    35,     3,    29,    81,     1,
       3,     6,    68,    52,    37,    73,    78,     1,    75,    77,
      49,    36,    73,     1,    36,    51,    49,     1,    36,    69,
      69,    29,    28,    65,    29,    76,    24,    61,    35,     4,
       3,     6,    68,    49,    29,     1,    59,    84,     3,    69,
      69,    29,    29,    51,    83,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    42,    43,    44,
      45,    45,    46,    46,    47,    48,    48,    49,    50,    50,
      50,    51,    51,    51,    52,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    65,    65,
      66,    66,    66,    67,    68,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    72,    71,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    77,    78,    78,    79,
      79,    79,    81,    80,    83,    82,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     2,     2,     2,     2,
       6,     1,     1,     1,     2,     3,     1,     3,     3,     0,
       1,     4,     0,     1,     3,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     3,
       3,     1,     4,     4,     1,     1,     6,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     7,     3,     1,
       1,     1,     1,     5,     2,     2,     1,     3,     3,     0,
       1,     2,     2,     1,     0,     7,     3,     2,     1,     1,
       3,     3,     0,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     0,    10,     1,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 10: /* function_definition: dtype_or_void ID num_args L_PAREN args R_PAREN  */
#line 92 "parser.y"
                                                                             { fprintf(pfile, " : function definition"); }
#line 1303 "parser.tab.c"
    break;

  case 15: /* class_definition: CLASS ID num_args  */
#line 103 "parser.y"
                                                { fprintf(pfile, " : class definition"); }
#line 1309 "parser.tab.c"
    break;

  case 39: /* decl_stmt: DECLARE ID ID  */
#line 151 "parser.y"
                                            { fprintf(pfile, " : declaration statement"); }
#line 1315 "parser.tab.c"
    break;

  case 40: /* decl_stmt: DECLARE DTYPE ID  */
#line 152 "parser.y"
                                               { fprintf(pfile, " : declaration statement"); }
#line 1321 "parser.tab.c"
    break;

  case 41: /* expr_stmt: unary_expr_rhs_body  */
#line 157 "parser.y"
                                                  { fprintf(pfile, " : expression statement"); }
#line 1327 "parser.tab.c"
    break;

  case 42: /* expr_stmt: EXPR ID ASGN_OP expr_rhs_body  */
#line 158 "parser.y"
                                                            { fprintf(pfile, " : expression statement"); }
#line 1333 "parser.tab.c"
    break;

  case 57: /* method_call: id_or_this ARROW method_name num_args L_PAREN call_params R_PAREN  */
#line 187 "parser.y"
                                                                                                { fprintf(pfile, " : call statement with object"); }
#line 1339 "parser.tab.c"
    break;

  case 63: /* function_call: ID num_args L_PAREN call_params R_PAREN  */
#line 199 "parser.y"
                                                                      { fprintf(pfile, " : call statement"); }
#line 1345 "parser.tab.c"
    break;

  case 71: /* return_stmt: RETURN expr_term  */
#line 215 "parser.y"
                                               { fprintf(pfile, " : return statement"); }
#line 1351 "parser.tab.c"
    break;

  case 72: /* return_stmt: RETURN VOID  */
#line 216 "parser.y"
                                          { fprintf(pfile, " : return statement"); }
#line 1357 "parser.tab.c"
    break;

  case 74: /* $@1: %empty  */
#line 222 "parser.y"
                                                  { fprintf(pfile, " : conditional statment"); }
#line 1363 "parser.tab.c"
    break;

  case 92: /* $@2: %empty  */
#line 257 "parser.y"
                                                      { fprintf(pfile, " : loop"); }
#line 1369 "parser.tab.c"
    break;

  case 94: /* $@3: %empty  */
#line 260 "parser.y"
                                                                                                          { fprintf(pfile, " : loop"); }
#line 1375 "parser.tab.c"
    break;


#line 1379 "parser.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 268 "parser.y"


int main(int argc, char *argv[]) {
    // Set input filestream
    if (argv[1]) yyin = fopen(argv[1], "r");
    else yyin = stdin;
    // Set output token filestream
    if (argv[2]) tfile = fopen(argv[2], "w");
    else {
        printf("[ERROR] Cannot open output token filestream.");
        return 1;
    }
    // Set output parsed filestream
    if (argv[3]) pfile = fopen(argv[3], "w");
    else {
        printf("[ERROR] Cannot open parsed filestream.");
        return 1;
    }
    // Parse the input file
    yyparse();
    return 0;
}
