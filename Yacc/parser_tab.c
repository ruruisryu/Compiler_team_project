
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TCONST	260
#define	TELSE	261
#define	TIF	262
#define	TEIF	263
#define	TINT	264
#define	TRETURN	265
#define	TVOID	266
#define	TWHILE	267
#define	TADDASSIGN	268
#define	TSUBASSIGN	269
#define	TMULASSIGN	270
#define	TDIVASSIGN	271
#define	TMODASSIGN	272
#define	TOR	273
#define	TAND	274
#define	TEQUAL	275
#define	TNOTEQU	276
#define	TGREATE	277
#define	TLESSE	278
#define	TINC	279
#define	TDEC	280
#define	TEOF	281
#define	TERROR	282
#define	TCOMMENT	283
#define	TFNUMBER	284
#define	TFLOAT	285
#define	TADD	286
#define	TSUB	287
#define	TMUL	288
#define	TDIV	289
#define	TMOD	290
#define	TASSIGN	291
#define	TNOT	292
#define	TLESS	293
#define	TGREAT	294
#define	TLPAREN	295
#define	TRPAREN	296
#define	TCOMMA	297
#define	TLBRACE	298
#define	TRBRACE	299
#define	TLBRACKET	300
#define	TRBRACKET	301
#define	TSEMI	302
#define	LOWER_THAN_ELSE	303

#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

void semantic(int);

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		165
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 99)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    16,    20,    25,
    30,    34,    36,    38,    42,    46,    48,    50,    52,    55,
    57,    59,    61,    63,    65,    67,    71,    73,    74,    76,
    80,    83,    88,    90,    91,    93,    96,   100,   102,   106,
   108,   112,   114,   119,   121,   122,   124,   125,   127,   130,
   132,   134,   136,   138,   140,   143,   145,   146,   152,   160,
   166,   170,   172,   174,   178,   182,   186,   190,   194,   198,
   200,   204,   206,   210,   212,   216,   220,   222,   226,   230,
   234,   238,   240,   244,   248,   250,   254,   258,   262,   264,
   267,   270,   273,   276,   278,   283,   288,   291,   294,   296,
   297,   299,   301,   305,   307,   309
};

static const short yyrhs[] = {    50,
     0,    51,     0,    50,    51,     0,    52,     0,    54,     0,
    72,     0,    53,    69,     0,    59,    64,    65,     0,    59,
    64,    55,    47,     0,    59,    64,    65,    47,     0,    40,
    56,    41,     0,    57,     0,    58,     0,    57,    42,    58,
     0,    57,    42,    68,     0,    59,     0,    60,     0,    61,
     0,    60,    61,     0,    62,     0,    63,     0,     5,     0,
     9,     0,    11,     0,     3,     0,    40,    66,    41,     0,
    67,     0,     0,    68,     0,    67,    42,    68,     0,    59,
    75,     0,    43,    70,    77,    44,     0,    71,     0,     0,
    72,     0,    71,    72,     0,    59,    73,    47,     0,    74,
     0,    73,    42,    74,     0,    75,     0,    75,    36,     4,
     0,     3,     0,     3,    45,    76,    46,     0,     4,     0,
     0,    78,     0,     0,    79,     0,    78,    79,     0,    69,
     0,    80,     0,    82,     0,    83,     0,    84,     0,    81,
    47,     0,    85,     0,     0,     7,    40,    85,    41,    79,
     0,     7,    40,    85,    41,    79,     6,    79,     0,    12,
    40,    85,    41,    79,     0,    10,    81,    47,     0,    86,
     0,    87,     0,    93,    36,    86,     0,    93,    13,    86,
     0,    93,    14,    86,     0,    93,    15,    86,     0,    93,
    16,    86,     0,    93,    17,    86,     0,    88,     0,    87,
    18,    88,     0,    89,     0,    88,    19,    89,     0,    90,
     0,    89,    20,    90,     0,    89,    21,    90,     0,    91,
     0,    90,    39,    91,     0,    90,    38,    91,     0,    90,
    22,    91,     0,    90,    23,    91,     0,    92,     0,    91,
    31,    92,     0,    91,    32,    92,     0,    93,     0,    92,
    33,    93,     0,    92,    34,    93,     0,    92,    35,    93,
     0,    94,     0,    32,    93,     0,    37,    93,     0,    24,
    93,     0,    25,    93,     0,    98,     0,    94,    45,    85,
    46,     0,    94,    40,    95,    41,     0,    94,    24,     0,
    94,    25,     0,    96,     0,     0,    97,     0,    86,     0,
    97,    42,    86,     0,     3,     0,     4,     0,    40,    85,
    41,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    22,    23,    24,    25,    26,    27,    28,    29,    31,    32,
    33,    34,    35,    36,    37,    38,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TEIF","TINT","TRETURN","TVOID","TWHILE","TADDASSIGN",
"TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TOR","TAND","TEQUAL","TNOTEQU",
"TGREATE","TLESSE","TINC","TDEC","TEOF","TERROR","TCOMMENT","TFNUMBER","TFLOAT",
"TADD","TSUB","TMUL","TDIV","TMOD","TASSIGN","TNOT","TLESS","TGREAT","TLPAREN",
"TRPAREN","TCOMMA","TLBRACE","TRBRACE","TLBRACKET","TRBRACKET","TSEMI","LOWER_THAN_ELSE",
"mini_c","translation_unit","external_dcl","function_def","function_header",
"type_function_header","type_param","opt_type_param","type_param_list","type_param_dcl",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    51,    52,    53,    54,    54,
    55,    56,    57,    57,    57,    58,    59,    60,    60,    61,
    61,    62,    63,    63,    64,    65,    66,    66,    67,    67,
    68,    69,    70,    70,    71,    71,    72,    73,    73,    74,
    74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
    79,    79,    79,    79,    80,    81,    81,    82,    82,    83,
    84,    85,    86,    86,    86,    86,    86,    86,    86,    87,
    87,    88,    88,    89,    89,    89,    90,    90,    90,    90,
    90,    91,    91,    91,    92,    92,    92,    92,    93,    93,
    93,    93,    93,    94,    94,    94,    94,    94,    95,    95,
    96,    97,    97,    98,    98,    98
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     3,     4,     4,
     3,     1,     1,     3,     3,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     1,     3,     1,     0,     1,     3,
     2,     4,     1,     0,     1,     2,     3,     1,     3,     1,
     3,     1,     4,     1,     0,     1,     0,     1,     2,     1,
     1,     1,     1,     1,     2,     1,     0,     5,     7,     5,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
     3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
     3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
     2,     2,     2,     1,     4,     4,     2,     2,     1,     0,
     1,     1,     3,     1,     1,     3
};

static const short yydefact[] = {     0,
    22,    23,    24,     1,     2,     4,     0,     5,     0,    17,
    18,    20,    21,     6,     3,    34,     7,    42,     0,     0,
    38,    40,    19,     0,    47,    33,    35,    45,    28,     0,
     8,     0,    37,     0,    42,   104,   105,     0,    57,     0,
     0,     0,     0,     0,     0,    50,     0,    46,    48,    51,
     0,    52,    53,    54,    56,    62,    63,    70,    72,    74,
    77,    82,    85,    89,    94,    36,    44,     0,     0,    12,
    13,    16,     0,    27,    29,     9,    10,    39,    41,     0,
     0,     0,    92,    93,    90,    91,     0,    32,    49,    55,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
    98,   100,     0,    43,    11,     0,    31,    26,     0,     0,
    61,     0,   106,    71,    85,    73,    75,    76,    80,    81,
    79,    78,    83,    84,    86,    87,    88,    65,    66,    67,
    68,    69,    64,   102,     0,    99,   101,     0,    14,    15,
     0,    30,    57,    57,    96,     0,    95,    58,    60,   103,
    57,    59,     0,     0,     0
};

static const short yydefgoto[] = {   163,
     4,     5,     6,     7,     8,    30,    69,    70,    71,     9,
    10,    11,    12,    13,    19,    31,    73,    74,    75,    46,
    25,    26,    14,    20,    21,    22,    68,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,   145,   146,   147,    65
};

static const short yypact[] = {    63,
-32768,-32768,-32768,    63,-32768,-32768,   -22,-32768,    38,    63,
-32768,-32768,-32768,-32768,-32768,    63,-32768,    -9,     3,    -3,
-32768,    10,-32768,    46,    75,    63,-32768,    48,    63,    26,
    33,    46,-32768,    82,    51,-32768,-32768,    57,     5,    58,
     5,     5,     5,     5,     5,-32768,    59,    75,-32768,-32768,
    55,-32768,-32768,-32768,-32768,-32768,    90,    97,    49,    12,
    52,    42,    11,     8,-32768,-32768,-32768,    74,    68,    79,
-32768,    46,    83,    81,-32768,-32768,-32768,-32768,-32768,     5,
    78,     5,-32768,-32768,-32768,-32768,    85,-32768,-32768,-32768,
     5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
     5,     5,     5,     5,     5,     5,     5,     5,     5,-32768,
-32768,     5,     5,-32768,-32768,    63,-32768,-32768,    63,    86,
-32768,    87,-32768,    97,-32768,    49,    12,    12,    52,    52,
    52,    52,    42,    42,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    88,-32768,    91,    84,-32768,-32768,
    46,-32768,   107,   107,-32768,     5,-32768,   128,-32768,-32768,
   107,-32768,   135,   136,-32768
};

static const short yypgoto[] = {-32768,
-32768,   133,-32768,-32768,-32768,-32768,-32768,-32768,    22,   -15,
-32768,   130,-32768,-32768,-32768,-32768,-32768,-32768,  -106,   134,
-32768,-32768,    -4,-32768,   110,   -70,-32768,-32768,-32768,   -48,
-32768,   104,-32768,-32768,-32768,   -42,   -89,-32768,    54,    56,
    -1,    -7,    -5,   -37,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		150


static const short yytable[] = {    89,
    24,   117,    87,    83,    84,    85,    86,    36,    37,   150,
    24,    27,   152,    72,   138,   139,   140,   141,   142,   143,
    16,    66,   144,   104,   105,   106,   107,   108,    41,    42,
   -25,   110,   111,    95,    96,    28,    43,   120,    32,   122,
    18,    44,    29,    33,    45,    34,   109,   112,    35,    97,
    98,    67,   113,   125,   125,   125,   125,   125,   125,   125,
   125,   125,   125,   135,   136,   137,   160,     1,    93,    94,
   148,     2,    76,     3,   101,   102,   103,    36,    37,    77,
   117,    38,    99,   100,    39,    79,    40,   129,   130,   131,
   132,   127,   128,   133,   134,    28,    80,    82,    41,    42,
    72,    90,    88,   151,   158,   159,    43,    91,   115,    36,
    37,    44,   162,    38,    45,    92,    39,    16,    40,   114,
   116,   -57,   119,   118,   121,   123,   153,   154,   155,   157,
    41,    42,   156,   161,   164,   165,    15,   149,    43,    23,
    17,    78,    81,    44,   124,     0,    45,   126,     0,    16
};

static const short yycheck[] = {    48,
    16,    72,    45,    41,    42,    43,    44,     3,     4,   116,
    26,    16,   119,    29,   104,   105,   106,   107,   108,   109,
    43,    26,   112,    13,    14,    15,    16,    17,    24,    25,
    40,    24,    25,    22,    23,    45,    32,    80,    42,    82,
     3,    37,    40,    47,    40,    36,    36,    40,     3,    38,
    39,     4,    45,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   156,     5,    20,    21,
   113,     9,    47,    11,    33,    34,    35,     3,     4,    47,
   151,     7,    31,    32,    10,     4,    12,    95,    96,    97,
    98,    93,    94,    99,   100,    45,    40,    40,    24,    25,
   116,    47,    44,   119,   153,   154,    32,    18,    41,     3,
     4,    37,   161,     7,    40,    19,    10,    43,    12,    46,
    42,    47,    42,    41,    47,    41,    41,    41,    41,    46,
    24,    25,    42,     6,     0,     0,     4,   116,    32,    10,
     7,    32,    39,    37,    91,    -1,    40,    92,    -1,    43
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 22 "parser.y"
{ semantic(1); ;
    break;}
case 2:
#line 23 "parser.y"
{ semantic(2); ;
    break;}
case 3:
#line 24 "parser.y"
{ semantic(3); ;
    break;}
case 4:
#line 25 "parser.y"
{ semantic(4); ;
    break;}
case 5:
#line 26 "parser.y"
{ semantic(4); ;
    break;}
case 6:
#line 27 "parser.y"
{ semantic(5); ;
    break;}
case 7:
#line 28 "parser.y"
{ semantic(6); ;
    break;}
case 8:
#line 29 "parser.y"
{ semantic(7); ;
    break;}
case 9:
#line 31 "parser.y"
{ semantic(7); ;
    break;}
case 10:
#line 32 "parser.y"
{ semantic(7); ;
    break;}
case 11:
#line 33 "parser.y"
{ semantic(17); ;
    break;}
case 12:
#line 34 "parser.y"
{ semantic(18); ;
    break;}
case 13:
#line 35 "parser.y"
{ semantic(20); ;
    break;}
case 14:
#line 36 "parser.y"
{ semantic(21); ;
    break;}
case 15:
#line 37 "parser.y"
{ semantic(21); ;
    break;}
case 16:
#line 38 "parser.y"
{ semantic(22); ;
    break;}
case 17:
#line 40 "parser.y"
{ semantic(8); ;
    break;}
case 18:
#line 41 "parser.y"
{ semantic(9); ;
    break;}
case 19:
#line 42 "parser.y"
{ semantic(10); ;
    break;}
case 20:
#line 43 "parser.y"
{ semantic(11); ;
    break;}
case 21:
#line 44 "parser.y"
{ semantic(12); ;
    break;}
case 22:
#line 45 "parser.y"
{ semantic(13); ;
    break;}
case 23:
#line 46 "parser.y"
{ semantic(14); ;
    break;}
case 24:
#line 47 "parser.y"
{ semantic(15); ;
    break;}
case 25:
#line 48 "parser.y"
{ semantic(16); ;
    break;}
case 26:
#line 49 "parser.y"
{ semantic(17); ;
    break;}
case 27:
#line 50 "parser.y"
{ semantic(18); ;
    break;}
case 28:
#line 51 "parser.y"
{ semantic(19); ;
    break;}
case 29:
#line 52 "parser.y"
{ semantic(20); ;
    break;}
case 30:
#line 53 "parser.y"
{ semantic(21); ;
    break;}
case 31:
#line 54 "parser.y"
{ semantic(22); ;
    break;}
case 32:
#line 55 "parser.y"
{ semantic(23); ;
    break;}
case 33:
#line 56 "parser.y"
{ semantic(24); ;
    break;}
case 34:
#line 57 "parser.y"
{ semantic(25); ;
    break;}
case 35:
#line 58 "parser.y"
{ semantic(26); ;
    break;}
case 36:
#line 59 "parser.y"
{ semantic(27); ;
    break;}
case 37:
#line 60 "parser.y"
{ semantic(28); ;
    break;}
case 38:
#line 61 "parser.y"
{ semantic(29); ;
    break;}
case 39:
#line 62 "parser.y"
{ semantic(30); ;
    break;}
case 40:
#line 63 "parser.y"
{ semantic(31); ;
    break;}
case 41:
#line 64 "parser.y"
{ semantic(32); ;
    break;}
case 42:
#line 65 "parser.y"
{ semantic(33); ;
    break;}
case 43:
#line 66 "parser.y"
{ semantic(34); ;
    break;}
case 44:
#line 67 "parser.y"
{ semantic(35); ;
    break;}
case 45:
#line 68 "parser.y"
{ semantic(36); ;
    break;}
case 46:
#line 69 "parser.y"
{ semantic(37); ;
    break;}
case 47:
#line 70 "parser.y"
{ semantic(38); ;
    break;}
case 48:
#line 71 "parser.y"
{ semantic(39); ;
    break;}
case 49:
#line 72 "parser.y"
{ semantic(40); ;
    break;}
case 50:
#line 73 "parser.y"
{ semantic(41); ;
    break;}
case 51:
#line 74 "parser.y"
{ semantic(42); ;
    break;}
case 52:
#line 75 "parser.y"
{ semantic(43); ;
    break;}
case 53:
#line 76 "parser.y"
{ semantic(44); ;
    break;}
case 54:
#line 77 "parser.y"
{ semantic(45); ;
    break;}
case 55:
#line 79 "parser.y"
{ semantic(46); ;
    break;}
case 56:
#line 80 "parser.y"
{ semantic(47); ;
    break;}
case 57:
#line 81 "parser.y"
{ semantic(48); ;
    break;}
case 58:
#line 82 "parser.y"
{ semantic(49); ;
    break;}
case 59:
#line 83 "parser.y"
{ semantic(50); ;
    break;}
case 60:
#line 84 "parser.y"
{ semantic(51); ;
    break;}
case 61:
#line 85 "parser.y"
{ semantic(52); ;
    break;}
case 62:
#line 86 "parser.y"
{ semantic(53); ;
    break;}
case 63:
#line 87 "parser.y"
{ semantic(54); ;
    break;}
case 64:
#line 88 "parser.y"
{ semantic(55); ;
    break;}
case 65:
#line 89 "parser.y"
{ semantic(56); ;
    break;}
case 66:
#line 90 "parser.y"
{ semantic(57); ;
    break;}
case 67:
#line 91 "parser.y"
{ semantic(58); ;
    break;}
case 68:
#line 92 "parser.y"
{ semantic(59); ;
    break;}
case 69:
#line 93 "parser.y"
{ semantic(60); ;
    break;}
case 70:
#line 95 "parser.y"
{ semantic(61); ;
    break;}
case 71:
#line 96 "parser.y"
{ semantic(62); ;
    break;}
case 72:
#line 97 "parser.y"
{ semantic(63); ;
    break;}
case 73:
#line 98 "parser.y"
{ semantic(64); ;
    break;}
case 74:
#line 99 "parser.y"
{ semantic(65); ;
    break;}
case 75:
#line 100 "parser.y"
{ semantic(66); ;
    break;}
case 76:
#line 101 "parser.y"
{ semantic(67); ;
    break;}
case 77:
#line 102 "parser.y"
{ semantic(68); ;
    break;}
case 78:
#line 103 "parser.y"
{ semantic(69); ;
    break;}
case 79:
#line 104 "parser.y"
{ semantic(70); ;
    break;}
case 80:
#line 105 "parser.y"
{ semantic(71); ;
    break;}
case 81:
#line 106 "parser.y"
{ semantic(72); ;
    break;}
case 82:
#line 107 "parser.y"
{ semantic(73); ;
    break;}
case 83:
#line 108 "parser.y"
{ semantic(74); ;
    break;}
case 84:
#line 109 "parser.y"
{ semantic(75); ;
    break;}
case 85:
#line 110 "parser.y"
{ semantic(76); ;
    break;}
case 86:
#line 111 "parser.y"
{ semantic(77); ;
    break;}
case 87:
#line 112 "parser.y"
{ semantic(78); ;
    break;}
case 88:
#line 113 "parser.y"
{ semantic(79); ;
    break;}
case 89:
#line 114 "parser.y"
{ semantic(80); ;
    break;}
case 90:
#line 115 "parser.y"
{ semantic(81); ;
    break;}
case 91:
#line 116 "parser.y"
{ semantic(82); ;
    break;}
case 92:
#line 117 "parser.y"
{ semantic(83); ;
    break;}
case 93:
#line 118 "parser.y"
{ semantic(84); ;
    break;}
case 94:
#line 119 "parser.y"
{ semantic(85); ;
    break;}
case 95:
#line 120 "parser.y"
{ semantic(86); ;
    break;}
case 96:
#line 121 "parser.y"
{ semantic(87); ;
    break;}
case 97:
#line 122 "parser.y"
{ semantic(88); ;
    break;}
case 98:
#line 123 "parser.y"
{ semantic(89); ;
    break;}
case 99:
#line 124 "parser.y"
{ semantic(90); ;
    break;}
case 100:
#line 125 "parser.y"
{ semantic(91); ;
    break;}
case 101:
#line 126 "parser.y"
{ semantic(92); ;
    break;}
case 102:
#line 127 "parser.y"
{ semantic(93); ;
    break;}
case 103:
#line 128 "parser.y"
{ semantic(94); ;
    break;}
case 104:
#line 129 "parser.y"
{ semantic(95); ;
    break;}
case 105:
#line 130 "parser.y"
{ semantic(96); ;
    break;}
case 106:
#line 131 "parser.y"
{ semantic(97); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 132 "parser.y"
  
void semantic(int n)
{
   printf("reduced rule number = %d\n", n);
}