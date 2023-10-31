/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
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
    TOKEN_EQUAL = 292,
    TOKEN_NOT = 293,
    TOKEN_LESS_THAN = 294,
    TOKEN_GREATER_THAN = 295,
    TOKEN_AND = 296,
    TOKEN_OR = 297,
    TOKEN_TYPE_SET = 298,
    TOKEN_SEMICOLON = 299,
    TOKEN_COMMA = 300,
    TOKEN_PLUS_PLUS = 301,
    TOKEN_MINUS_MINUS = 302,
    TOKEN_LESS_THAN_OR_EQUAL = 303,
    TOKEN_GREATER_THAN_OR_EQUAL = 304,
    TOKEN_IDENTIFIER = 305,
    TOKEN_INT_LITERAL = 306,
    TOKEN_FLOAT_LITERAL = 307,
    TOKEN_STRING_LITERAL = 308,
    TOKEN_CHAR_LITERAL = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN_H_INCLUDED  */
