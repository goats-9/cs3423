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

    /* global defines */
    #define PREAMBLE            "Name: Gautam Singh\nID: CS21BTECH11018\n"

    /* global and extern variables */
    extern FILE *yyin, *tfile, *pfile;
    extern int yylineno;
    extern int yyerrfl;     // For flagging an error
    extern int yytype;      // For determining type of statement parsed
    int yyretcnt;           // For counting number of return statements

    /* prototypes for yylex and yyerror */
    int yylex();
    int yyerror(char *) { yyerrfl = 1; }

#line 104 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    DTYPE = 259,                   /* DTYPE  */
    CONST = 260,                   /* CONST  */
    NUMBER = 261,                  /* NUMBER  */
    UNARY_OP = 262,                /* UNARY_OP  */
    ARTH_OP = 263,                 /* ARTH_OP  */
    UNARY_LOGICAL_OP = 264,        /* UNARY_LOGICAL_OP  */
    BINARY_LOGICAL_OP = 265,       /* BINARY_LOGICAL_OP  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    GLOBAL = 268,                  /* GLOBAL  */
    LOCAL = 269,                   /* LOCAL  */
    CLASS = 270,                   /* CLASS  */
    DECLARE = 271,                 /* DECLARE  */
    EXPR = 272,                    /* EXPR  */
    TRUE = 273,                    /* TRUE  */
    FALSE = 274,                   /* FALSE  */
    LOOP = 275,                    /* LOOP  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    CALL = 278,                    /* CALL  */
    INCASE = 279,                  /* INCASE  */
    OTHERWISE = 280,               /* OTHERWISE  */
    RETURN = 281,                  /* RETURN  */
    FOR = 282,                     /* FOR  */
    THIS = 283,                    /* THIS  */
    L_PAREN = 284,                 /* L_PAREN  */
    R_PAREN = 285,                 /* R_PAREN  */
    L_SQUARE = 286,                /* L_SQUARE  */
    R_SQUARE = 287,                /* R_SQUARE  */
    L_BRACE = 288,                 /* L_BRACE  */
    R_BRACE = 289,                 /* R_BRACE  */
    ASGN_OP = 290,                 /* ASGN_OP  */
    SEMICOLON = 291,               /* SEMICOLON  */
    COMMA = 292,                   /* COMMA  */
    ARROW = 293,                   /* ARROW  */
    VOID = 294                     /* VOID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
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
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_GLOBAL = 13,                    /* GLOBAL  */
  YYSYMBOL_LOCAL = 14,                     /* LOCAL  */
  YYSYMBOL_CLASS = 15,                     /* CLASS  */
  YYSYMBOL_DECLARE = 16,                   /* DECLARE  */
  YYSYMBOL_EXPR = 17,                      /* EXPR  */
  YYSYMBOL_TRUE = 18,                      /* TRUE  */
  YYSYMBOL_FALSE = 19,                     /* FALSE  */
  YYSYMBOL_LOOP = 20,                      /* LOOP  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_CALL = 23,                      /* CALL  */
  YYSYMBOL_INCASE = 24,                    /* INCASE  */
  YYSYMBOL_OTHERWISE = 25,                 /* OTHERWISE  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_THIS = 28,                      /* THIS  */
  YYSYMBOL_L_PAREN = 29,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 30,                   /* R_PAREN  */
  YYSYMBOL_L_SQUARE = 31,                  /* L_SQUARE  */
  YYSYMBOL_R_SQUARE = 32,                  /* R_SQUARE  */
  YYSYMBOL_L_BRACE = 33,                   /* L_BRACE  */
  YYSYMBOL_R_BRACE = 34,                   /* R_BRACE  */
  YYSYMBOL_ASGN_OP = 35,                   /* ASGN_OP  */
  YYSYMBOL_SEMICOLON = 36,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_ARROW = 38,                     /* ARROW  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_program_body = 42,              /* program_body  */
  YYSYMBOL_function = 43,                  /* function  */
  YYSYMBOL_function_definition = 44,       /* function_definition  */
  YYSYMBOL_dtype_or_void = 45,             /* dtype_or_void  */
  YYSYMBOL_class = 46,                     /* class  */
  YYSYMBOL_class_definition = 47,          /* class_definition  */
  YYSYMBOL_block_scope = 48,               /* block_scope  */
  YYSYMBOL_args = 49,                      /* args  */
  YYSYMBOL_args_comma = 50,                /* args_comma  */
  YYSYMBOL_num_args = 51,                  /* num_args  */
  YYSYMBOL_blocks = 52,                    /* blocks  */
  YYSYMBOL_block = 53,                     /* block  */
  YYSYMBOL_stmt = 54,                      /* stmt  */
  YYSYMBOL_stmt_body = 55,                 /* stmt_body  */
  YYSYMBOL_decl_stmt = 56,                 /* decl_stmt  */
  YYSYMBOL_id_comma = 57,                  /* id_comma  */
  YYSYMBOL_expr_stmt = 58,                 /* expr_stmt  */
  YYSYMBOL_unary_expr_rhs_body = 59,       /* unary_expr_rhs_body  */
  YYSYMBOL_expr_term = 60,                 /* expr_term  */
  YYSYMBOL_unary_expr_term = 61,           /* unary_expr_term  */
  YYSYMBOL_call_stmt = 62,                 /* call_stmt  */
  YYSYMBOL_method_call = 63,               /* method_call  */
  YYSYMBOL_method_name = 64,               /* method_name  */
  YYSYMBOL_method_name_opt = 65,           /* method_name_opt  */
  YYSYMBOL_function_call = 66,             /* function_call  */
  YYSYMBOL_call_params = 67,               /* call_params  */
  YYSYMBOL_call_types = 68,                /* call_types  */
  YYSYMBOL_return_stmt = 69,               /* return_stmt  */
  YYSYMBOL_returnable = 70,                /* returnable  */
  YYSYMBOL_cond_block = 71,                /* cond_block  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_otherwise_block = 73,           /* otherwise_block  */
  YYSYMBOL_predicate = 74,                 /* predicate  */
  YYSYMBOL_predicate_term = 75,            /* predicate_term  */
  YYSYMBOL_unary_pred_body = 76,           /* unary_pred_body  */
  YYSYMBOL_loop_block = 77,                /* loop_block  */
  YYSYMBOL_loop_while_block = 78,          /* loop_while_block  */
  YYSYMBOL_79_2 = 79,                      /* $@2  */
  YYSYMBOL_loop_for_block = 80,            /* loop_for_block  */
  YYSYMBOL_81_3 = 81,                      /* $@3  */
  YYSYMBOL_loop_for_update = 82            /* loop_for_update  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    69,    70,    73,    74,    75,    76,    81,
      82,    85,    88,    89,    92,    95,    98,   103,   104,   107,
     108,   111,   112,   117,   118,   119,   120,   123,   124,   125,
     126,   127,   130,   133,   134,   135,   136,   141,   142,   145,
     146,   151,   152,   155,   158,   159,   160,   161,   162,   165,
     166,   167,   172,   173,   176,   179,   182,   183,   184,   187,
     190,   191,   194,   195,   196,   197,   198,   203,   205,   206,
     207,   212,   212,   215,   216,   221,   222,   223,   224,   225,
     228,   229,   232,   233,   238,   239,   242,   242,   245,   245,
     248,   249
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
  "AND", "OR", "GLOBAL", "LOCAL", "CLASS", "DECLARE", "EXPR", "TRUE",
  "FALSE", "LOOP", "WHILE", "DO", "CALL", "INCASE", "OTHERWISE", "RETURN",
  "FOR", "THIS", "L_PAREN", "R_PAREN", "L_SQUARE", "R_SQUARE", "L_BRACE",
  "R_BRACE", "ASGN_OP", "SEMICOLON", "COMMA", "ARROW", "VOID", "$accept",
  "program", "program_body", "function", "function_definition",
  "dtype_or_void", "class", "class_definition", "block_scope", "args",
  "args_comma", "num_args", "blocks", "block", "stmt", "stmt_body",
  "decl_stmt", "id_comma", "expr_stmt", "unary_expr_rhs_body", "expr_term",
  "unary_expr_term", "call_stmt", "method_call", "method_name",
  "method_name_opt", "function_call", "call_params", "call_types",
  "return_stmt", "returnable", "cond_block", "$@1", "otherwise_block",
  "predicate", "predicate_term", "unary_pred_body", "loop_block",
  "loop_while_block", "$@2", "loop_for_block", "$@3", "loop_for_update", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -62,     2,    18,    30,    -6,   -62,     3,   -62,   -62,
       3,    40,    26,   -62,     2,   -62,    52,   -62,   -62,    26,
      27,   -62,     3,    35,     2,     2,   118,    89,    84,    11,
      73,     5,    80,   -62,   -62,    52,    95,    52,   -62,    96,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   104,
     102,   -62,    74,     3,     3,   132,   132,   101,    81,    -4,
     -62,   -62,    26,   106,   -62,    81,   -62,   -62,   -62,   111,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,    12,   -62,
     -62,   -62,   -62,   137,   -62,   115,   -62,   -62,   -62,   105,
     105,   112,   117,    81,   -62,   -62,   116,   -62,   138,   121,
     122,   144,    43,   112,   113,   150,   124,   123,   -62,   152,
     -62,    81,    71,    81,    81,   135,    88,   120,   120,   125,
     -62,   127,    81,   -62,   -62,   154,   -62,    86,   -62,   116,
     116,     3,   -62,   -62,   -62,   -62,   -62,   -62,    19,   -62,
      21,   139,   112,     6,   156,   -62,   -62,   -62,   120,   -62,
       3,   136,   155,   -62,   -62,   140,   -62,   -62,   141,     3,
     -62,   -62,   -62,     3,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     0,     2,     8,     0,    12,    13,
       0,     0,    22,     1,     0,     6,     0,    14,     7,    22,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    26,     0,    25,    27,     0,
      33,    34,    41,    35,    36,    28,    29,    84,    85,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,    22,
      58,    52,    22,     0,    53,     0,    49,    45,    50,     0,
      46,    47,    69,    51,    68,    48,    70,    67,     0,    24,
      16,    23,    32,    18,    21,     0,     9,    10,    40,    37,
      38,     0,     0,     0,    83,    82,    86,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    43,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      71,     0,     0,    20,    11,     0,    39,     0,    78,    75,
      76,     0,    81,    62,    64,    63,    65,    66,     0,    61,
       0,     0,     0,     0,     0,    77,    87,    59,     0,    54,
       0,     0,    91,    19,    60,    74,    44,    90,     0,     0,
      72,    88,    73,     0,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,   -62,    46,   -62,   103,   -62,    -7,   -62,
     -62,   -14,    77,   -62,   -62,   -62,   -62,   114,    90,   -15,
     -29,   126,     0,   -62,   -62,   -62,   -62,    49,    24,   -62,
     -62,   -62,   -62,   -62,   -61,   -62,    53,   -62,   -62,   -62,
     -62,   -62,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    33,    10,    11,    34,     7,    35,   106,
     107,    21,    36,    37,    38,    39,    40,    89,    41,    73,
      94,    75,    95,    61,    62,    63,    64,   138,   139,    44,
      77,    45,   141,   160,    96,    97,    98,    46,    47,   115,
      48,   163,   158
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    42,    74,    18,   102,    49,     8,    14,    66,     3,
      67,    68,    23,    69,    59,    51,    43,   113,   114,    23,
      42,    12,    42,    70,    71,    -3,     1,    20,    29,    27,
      13,    76,   112,    50,   -57,    43,    16,    43,     2,    60,
       3,     9,   152,    19,    72,    99,    86,    87,   100,   147,
     127,   149,   129,   130,   113,   114,   148,    20,   148,    23,
      22,   143,   110,    42,    52,    24,    25,     3,    26,    27,
      53,    54,    28,   120,   121,    29,    30,    66,    31,    32,
      68,    23,   113,   114,    66,    16,    67,    68,    23,    69,
      92,    66,    57,    67,    68,    23,    69,   113,   114,    70,
      71,   128,    65,     6,    29,    58,    70,    71,    15,    78,
      93,    29,    79,   151,    81,    66,   145,    67,    68,    23,
      69,    55,    56,   133,   146,   134,   135,   113,   114,    80,
      70,    71,    82,    83,    84,    88,    91,   157,   136,   137,
     103,   105,   109,   155,   101,   108,   111,   119,   116,   122,
     117,   118,   162,   123,   124,   126,   164,   131,   144,   153,
     125,   150,    23,   -56,   142,   159,   156,   140,   104,   132,
      90,   161,   154,     0,     0,     0,     0,     0,    85
};

static const yytype_int16 yycheck[] =
{
       7,    16,    31,    10,    65,    19,     4,    13,     3,    15,
       5,     6,     7,     8,     3,    22,    16,    11,    12,     7,
      35,     3,    37,    18,    19,     0,     1,    31,    23,    17,
       0,    31,    93,     6,    38,    35,    33,    37,    13,    28,
      15,    39,    36,     3,    39,    59,    53,    54,    62,    30,
     111,    30,   113,   114,    11,    12,    37,    31,    37,     7,
      14,   122,    91,    78,    29,    13,    14,    15,    16,    17,
      24,    25,    20,    30,   103,    23,    24,     3,    26,    27,
       6,     7,    11,    12,     3,    33,     5,     6,     7,     8,
       9,     3,     3,     5,     6,     7,     8,    11,    12,    18,
      19,    30,    29,     0,    23,    21,    18,    19,     5,    29,
      29,    23,    35,   142,    37,     3,    30,     5,     6,     7,
       8,     3,     4,     3,   131,     5,     6,    11,    12,    34,
      18,    19,    36,    29,    32,     3,    35,   152,    18,    19,
      29,     4,    37,   150,    38,    30,    29,     3,    10,    36,
      29,    29,   159,     3,    30,     3,   163,    22,     4,     3,
      37,    22,     7,    38,    37,    25,    30,   118,    78,   116,
      56,    30,   148,    -1,    -1,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    13,    15,    41,    42,    46,    47,     4,    39,
      44,    45,     3,     0,    13,    46,    33,    48,    48,     3,
      31,    51,    44,     7,    13,    14,    16,    17,    20,    23,
      24,    26,    27,    43,    46,    48,    52,    53,    54,    55,
      56,    58,    59,    62,    69,    71,    77,    78,    80,    51,
       6,    48,    29,    44,    44,     3,     4,     3,    21,     3,
      28,    63,    64,    65,    66,    29,     3,     5,     6,     8,
      18,    19,    39,    59,    60,    61,    62,    70,    29,    52,
      34,    52,    36,    29,    32,    61,    48,    48,     3,    57,
      57,    35,     9,    29,    60,    62,    74,    75,    76,    51,
      51,    38,    74,    29,    58,     4,    49,    50,    30,    37,
      60,    29,    74,    11,    12,    79,    10,    29,    29,     3,
      30,    60,    36,     3,    30,    37,     3,    74,    30,    74,
      74,    22,    76,     3,     5,     6,    18,    19,    67,    68,
      67,    72,    37,    74,     4,    30,    48,    30,    37,    30,
      22,    60,    36,     3,    68,    48,    30,    59,    82,    25,
      73,    30,    48,    81,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    41,    42,    42,    42,    42,    43,
      43,    44,    45,    45,    46,    47,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
      53,    53,    54,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    60,    60,    60,    60,    61,
      61,    61,    62,    62,    63,    64,    65,    65,    65,    66,
      67,    67,    68,    68,    68,    68,    68,    69,    70,    70,
      70,    72,    71,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    76,    76,    77,    77,    79,    78,    81,    80,
      82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     4,     2,     3,     1,     3,
       3,     6,     1,     1,     2,     3,     3,     1,     0,     4,
       2,     3,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     4,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     5,     3,     3,     1,     1,     5,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     0,     8,     2,     0,     3,     3,     4,     3,     1,
       1,     3,     1,     1,     1,     1,     0,     6,     0,    10,
       1,     0
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
  case 4: /* program: error  */
#line 70 "parser.y"
                                    { yyerrfl = 1; }
#line 1369 "y.tab.c"
    break;

  case 5: /* program_body: program_body GLOBAL function_definition block_scope  */
#line 73 "parser.y"
                                                                                  { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
#line 1375 "y.tab.c"
    break;

  case 7: /* program_body: GLOBAL function_definition block_scope  */
#line 75 "parser.y"
                                                                     { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
#line 1381 "y.tab.c"
    break;

  case 9: /* function: GLOBAL function_definition block_scope  */
#line 81 "parser.y"
                                                                     { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
#line 1387 "y.tab.c"
    break;

  case 10: /* function: LOCAL function_definition block_scope  */
#line 82 "parser.y"
                                                                    { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
#line 1393 "y.tab.c"
    break;

  case 11: /* function_definition: dtype_or_void ID num_args L_PAREN args R_PAREN  */
#line 85 "parser.y"
                                                                             { yytype = 0; }
#line 1399 "y.tab.c"
    break;

  case 15: /* class_definition: CLASS ID num_args  */
#line 95 "parser.y"
                                                { yytype = 1; }
#line 1405 "y.tab.c"
    break;

  case 37: /* decl_stmt: DECLARE ID id_comma  */
#line 141 "parser.y"
                                                  { yytype = 2; }
#line 1411 "y.tab.c"
    break;

  case 38: /* decl_stmt: DECLARE DTYPE id_comma  */
#line 142 "parser.y"
                                                     { yytype = 2; }
#line 1417 "y.tab.c"
    break;

  case 41: /* expr_stmt: unary_expr_rhs_body  */
#line 151 "parser.y"
                                                  { yytype = 4; }
#line 1423 "y.tab.c"
    break;

  case 42: /* expr_stmt: EXPR ID ASGN_OP expr_term  */
#line 152 "parser.y"
                                                        { yytype = 3; }
#line 1429 "y.tab.c"
    break;

  case 54: /* method_call: method_name num_args L_PAREN call_params R_PAREN  */
#line 176 "parser.y"
                                                                               { yytype = 5; }
#line 1435 "y.tab.c"
    break;

  case 59: /* function_call: ID num_args L_PAREN call_params R_PAREN  */
#line 187 "parser.y"
                                                                      { yytype = 4; }
#line 1441 "y.tab.c"
    break;

  case 67: /* return_stmt: RETURN returnable  */
#line 203 "parser.y"
                                                { yytype = 8; ++yyretcnt; }
#line 1447 "y.tab.c"
    break;

  case 71: /* $@1: %empty  */
#line 212 "parser.y"
                                                               { yytype = 7; }
#line 1453 "y.tab.c"
    break;

  case 86: /* $@2: %empty  */
#line 242 "parser.y"
                                                   { yytype = 6; }
#line 1459 "y.tab.c"
    break;

  case 88: /* $@3: %empty  */
#line 245 "parser.y"
                                                                                                          { yytype = 6; }
#line 1465 "y.tab.c"
    break;


#line 1469 "y.tab.c"

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

#line 252 "parser.y"


int main(int argc, char *argv[]) {
    yyretcnt = 0;
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
    fprintf(tfile, PREAMBLE);
    // Parse the input file
    yyparse();
    return 0;
}
