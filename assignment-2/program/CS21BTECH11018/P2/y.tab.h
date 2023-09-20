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
    LOGICAL_JOIN_OP = 266,         /* LOGICAL_JOIN_OP  */
    GLOBAL = 267,                  /* GLOBAL  */
    LOCAL = 268,                   /* LOCAL  */
    CLASS = 269,                   /* CLASS  */
    DECLARE = 270,                 /* DECLARE  */
    EXPR = 271,                    /* EXPR  */
    TRUE = 272,                    /* TRUE  */
    FALSE = 273,                   /* FALSE  */
    LOOP = 274,                    /* LOOP  */
    WHILE = 275,                   /* WHILE  */
    DO = 276,                      /* DO  */
    CALL = 277,                    /* CALL  */
    INCASE = 278,                  /* INCASE  */
    OTHERWISE = 279,               /* OTHERWISE  */
    RETURN = 280,                  /* RETURN  */
    FOR = 281,                     /* FOR  */
    THIS = 282,                    /* THIS  */
    L_PAREN = 283,                 /* L_PAREN  */
    R_PAREN = 284,                 /* R_PAREN  */
    L_SQUARE = 285,                /* L_SQUARE  */
    R_SQUARE = 286,                /* R_SQUARE  */
    L_BRACE = 287,                 /* L_BRACE  */
    R_BRACE = 288,                 /* R_BRACE  */
    ASGN_OP = 289,                 /* ASGN_OP  */
    SEMICOLON = 290,               /* SEMICOLON  */
    COMMA = 291,                   /* COMMA  */
    ARROW = 292,                   /* ARROW  */
    VOID = 293,                    /* VOID  */
    TOK_EOF = 294                  /* TOK_EOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define DTYPE 259
#define CONST 260
#define NUMBER 261
#define UNARY_OP 262
#define ARTH_OP 263
#define UNARY_LOGICAL_OP 264
#define BINARY_LOGICAL_OP 265
#define LOGICAL_JOIN_OP 266
#define GLOBAL 267
#define LOCAL 268
#define CLASS 269
#define DECLARE 270
#define EXPR 271
#define TRUE 272
#define FALSE 273
#define LOOP 274
#define WHILE 275
#define DO 276
#define CALL 277
#define INCASE 278
#define OTHERWISE 279
#define RETURN 280
#define FOR 281
#define THIS 282
#define L_PAREN 283
#define R_PAREN 284
#define L_SQUARE 285
#define R_SQUARE 286
#define L_BRACE 287
#define R_BRACE 288
#define ASGN_OP 289
#define SEMICOLON 290
#define COMMA 291
#define ARROW 292
#define VOID 293
#define TOK_EOF 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
