/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
