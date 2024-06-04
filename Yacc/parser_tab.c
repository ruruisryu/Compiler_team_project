
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
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "sym_table_lab.h"
#include "hash_func.h"
#include "tn.h"

extern void semantic(int);
extern void ReportParserError(char* message);
void updateReturnType(int returntype, const char *identifier); 
void updateIdentType(const char *type, const char *identifier);

int returnType = 0;
unsigned int currlinenum;

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



#define	YYFINAL		200
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 95)

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
     0,     2,     4,     7,     9,    11,    14,    17,    21,    24,
    27,    31,    35,    37,    41,    45,    49,    51,    53,    55,
    58,    60,    62,    64,    66,    68,    70,    72,    74,    78,
    82,    84,    85,    87,    91,    94,    97,   100,   104,   107,
   111,   113,   116,   118,   120,   124,   128,   130,   134,   136,
   140,   144,   148,   150,   152,   154,   159,   164,   169,   174,
   176,   177,   179,   181,   183,   185,   187,   190,   192,   195,
   201,   209,   215,   221,   227,   233,   239,   242,   244,   246,
   250,   254,   258,   262,   266,   270,   274,   278,   282,   286,
   290,   294,   296,   300,   302,   306,   308,   312,   316,   318,
   322,   326,   330,   334,   336,   340,   344,   346,   350,   354,
   358,   360,   363,   366,   369,   372,   374,   379,   384,   387,
   390,   395,   400,   402,   403,   405,   407,   411,   413,   415,
   417,   421
};

static const short yyrhs[] = {    50,
     0,    51,     0,    50,    51,     0,    52,     0,    71,     0,
    53,    68,     0,     1,    68,     0,    58,    63,    64,     0,
    63,    55,     0,    63,    64,     0,    40,    56,    41,     0,
    40,    56,     1,     0,    57,     0,    56,    42,    57,     0,
    56,    42,    67,     0,    66,    42,    57,     0,    60,     0,
    59,     0,    60,     0,    59,    60,     0,    61,     0,    62,
     0,     5,     0,     9,     0,    30,     0,    11,     0,     3,
     0,    27,     0,    40,    65,    41,     0,    40,    65,     1,
     0,    66,     0,     0,    67,     0,    66,    42,    67,     0,
    60,    74,     0,    60,    54,     0,    43,    44,     0,    43,
    69,    44,     0,    43,     1,     0,    43,    69,     1,     0,
    70,     0,    69,    70,     0,    71,     0,    76,     0,    58,
    72,    47,     0,    58,    72,     1,     0,    73,     0,    72,
    42,    73,     0,    74,     0,    74,    36,     4,     0,    74,
    36,    29,     0,    74,    36,     1,     0,    54,     0,     3,
     0,    27,     0,     3,    45,    75,    46,     0,    27,    45,
    75,    46,     0,     3,    45,    75,     1,     0,    27,    45,
    75,     1,     0,     4,     0,     0,    68,     0,    77,     0,
    78,     0,    79,     0,    80,     0,    81,    47,     0,    47,
     0,    81,     1,     0,     7,    40,    81,    41,    76,     0,
     7,    40,    81,    41,    76,     6,    76,     0,     7,    40,
    81,     1,    76,     0,     7,     1,    81,    41,    76,     0,
    12,    40,    81,    41,    76,     0,    12,    40,    81,     1,
    76,     0,    12,     1,    81,    41,    76,     0,    10,    77,
     0,    82,     0,    83,     0,    89,    36,    82,     0,    89,
    13,    82,     0,    89,    14,    82,     0,    89,    15,    82,
     0,    89,    16,    82,     0,    89,    17,    82,     0,    89,
    36,     1,     0,    89,    13,     1,     0,    89,    14,     1,
     0,    89,    15,     1,     0,    89,    16,     1,     0,    89,
    17,     1,     0,    84,     0,    83,    18,    84,     0,    85,
     0,    84,    19,    85,     0,    86,     0,    85,    20,    86,
     0,    85,    21,    86,     0,    87,     0,    86,    39,    87,
     0,    86,    38,    87,     0,    86,    22,    87,     0,    86,
    23,    87,     0,    88,     0,    87,    31,    88,     0,    87,
    32,    88,     0,    89,     0,    88,    33,    89,     0,    88,
    34,    89,     0,    88,    35,    89,     0,    90,     0,    32,
    89,     0,    37,    89,     0,    24,    89,     0,    25,    89,
     0,    94,     0,    90,    45,    81,    46,     0,    90,    40,
    91,    41,     0,    90,    24,     0,    90,    25,     0,    90,
    45,    81,     1,     0,    90,    40,    91,     1,     0,    92,
     0,     0,    93,     0,    82,     0,    93,    42,    82,     0,
     3,     0,    27,     0,     4,     0,    40,    81,     1,     0,
    40,    81,    41,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    32,    33,    34,    35,    36,    37,    38,    39,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TEIF","TINT","TRETURN","TVOID","TWHILE","TADDASSIGN",
"TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TOR","TAND","TEQUAL","TNOTEQU",
"TGREATE","TLESSE","TINC","TDEC","TEOF","TERROR","TCOMMENT","TFNUMBER","TFLOAT",
"TADD","TSUB","TMUL","TDIV","TMOD","TASSIGN","TNOT","TLESS","TGREAT","TLPAREN",
"TRPAREN","TCOMMA","TLBRACE","TRBRACE","TLBRACKET","TRBRACKET","TSEMI","LOWER_THAN_ELSE",
"mini_c","translation_unit","external_dcl","function_def","function_header",
"function_prototype","type_only_param","type_only_param_list","type_only_param_dcl",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","block_item_list","block_item","declaration","init_dcl_list","init_declarator",
"declarator","opt_number","statement","expression_st","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    52,    52,    53,    54,    54,
    55,    55,    56,    56,    56,    56,    57,    58,    59,    59,
    60,    60,    61,    62,    62,    62,    63,    63,    64,    64,
    65,    65,    66,    66,    67,    67,    68,    68,    68,    68,
    69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
    73,    73,    73,    74,    74,    74,    74,    74,    74,    75,
    75,    76,    76,    76,    76,    76,    77,    77,    77,    78,
    78,    78,    78,    79,    79,    79,    80,    81,    82,    82,
    82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
    82,    83,    83,    84,    84,    85,    85,    85,    86,    86,
    86,    86,    86,    87,    87,    87,    88,    88,    88,    88,
    89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
    90,    90,    91,    91,    92,    93,    93,    94,    94,    94,
    94,    94
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     3,     2,     2,
     3,     3,     1,     3,     3,     3,     1,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
     1,     0,     1,     3,     2,     2,     2,     3,     2,     3,
     1,     2,     1,     1,     3,     3,     1,     3,     1,     3,
     3,     3,     1,     1,     1,     4,     4,     4,     4,     1,
     0,     1,     1,     1,     1,     1,     2,     1,     2,     5,
     7,     5,     5,     5,     5,     5,     2,     1,     1,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
     3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
     1,     2,     2,     2,     2,     1,     4,     4,     2,     2,
     4,     4,     1,     0,     1,     1,     3,     1,     1,     1,
     3,     3
};

static const short yydefact[] = {     0,
     0,    23,    24,    26,    25,     0,     2,     4,     0,     0,
    18,    19,    21,    22,     5,     0,     7,     3,     6,    54,
    55,    53,     0,     0,    47,    49,    20,    39,   128,   130,
     0,     0,     0,     0,     0,   129,     0,     0,     0,    37,
    68,     0,    62,     0,    41,    43,    44,    63,    64,    65,
    66,     0,    78,    79,    92,    94,    96,    99,   104,   107,
   111,   116,    61,    61,    32,     9,    10,    46,     0,    45,
     0,     0,     0,    77,     0,     0,   114,   115,   112,   113,
     0,     0,    40,    38,    42,    69,    67,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   119,   120,   124,     0,
    60,     0,     0,     0,    13,    17,     0,    31,    33,    48,
    52,    50,    51,     0,     0,     0,     0,   131,   132,    10,
    93,   107,    95,    97,    98,   102,   103,   101,   100,   105,
   106,   108,   109,   110,    87,    81,    88,    82,    89,    83,
    90,    84,    91,    85,    86,    80,   126,     0,   123,   125,
     0,    58,    56,    59,    57,    12,    11,     0,    36,    35,
    30,    29,     0,     0,     0,     0,     0,     0,     0,   122,
   118,     0,   121,   117,    14,    15,    16,    34,    73,    72,
    70,    76,    75,    74,   127,     0,    71,     0,     0,     0
};

static const short yydefgoto[] = {   198,
     6,     7,     8,     9,    22,    66,   114,   115,    10,    11,
    12,    13,    14,    82,    67,   117,   118,   119,    43,    44,
    45,    15,    24,    25,    26,   112,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,   158,   159,   160,    62
};

static const short yypact[] = {    88,
   -19,-32768,-32768,-32768,-32768,    22,-32768,-32768,   -19,   102,
   129,-32768,-32768,-32768,-32768,    76,-32768,-32768,-32768,   -15,
    -8,-32768,   -14,    11,-32768,     2,-32768,-32768,-32768,-32768,
    54,   152,    56,   270,   270,-32768,   270,   270,   270,-32768,
-32768,   102,-32768,   121,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    14,-32768,    10,    73,    25,   211,    83,     1,   251,
   187,-32768,    91,    91,   129,-32768,    55,-32768,   102,-32768,
   106,   270,   270,-32768,   270,   270,-32768,-32768,-32768,-32768,
    15,   -14,-32768,-32768,-32768,-32768,-32768,   270,   270,   270,
   270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
   177,   204,   215,   221,   253,   259,-32768,-32768,   270,   270,
-32768,    16,    17,     7,-32768,   102,    18,    60,-32768,-32768,
-32768,-32768,-32768,    63,    19,    80,    49,-32768,-32768,-32768,
    73,-32768,    25,   211,   211,    83,    83,    83,    83,     1,
     1,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    50,-32768,    85,
    38,-32768,-32768,-32768,-32768,-32768,-32768,   129,-32768,-32768,
-32768,-32768,   129,   163,   163,   163,   163,   163,   163,-32768,
-32768,   270,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   130,-32768,-32768,-32768,-32768,   163,-32768,   147,   149,-32768
};

static const short yypgoto[] = {-32768,
-32768,   144,-32768,-32768,    36,-32768,-32768,  -126,    93,-32768,
   -11,-32768,-32768,   150,    72,-32768,-32768,   -56,    20,-32768,
   119,    95,-32768,   100,    58,   107,   137,   140,-32768,-32768,
-32768,   -32,  -100,-32768,    94,    96,    51,   225,    47,   -24,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		333


static const short yytable[] = {    27,
   146,   148,   150,   152,   154,   156,    81,   166,   157,    77,
    78,    68,    79,    80,    86,   128,   162,   164,   171,   175,
    17,    -1,     1,    16,   -27,    65,     2,    88,    19,    63,
     3,   -28,     4,    98,    99,   100,    64,    71,   183,   124,
   125,   185,   126,   127,    90,    91,   187,   167,   168,   178,
   180,     5,    69,   116,    72,   129,    75,    70,   172,   176,
    87,   163,   165,   132,   132,   132,   132,   132,   132,   132,
   132,   132,   132,   142,   143,   144,    28,   161,    29,    30,
     2,   195,    31,   184,     3,    32,     4,    33,     1,   179,
   181,    89,     2,    73,   111,    76,     3,    -8,     4,    34,
    35,   173,    36,   174,    20,     5,   121,    37,    42,   122,
    46,   186,    38,    96,    97,    39,   188,     5,    16,    40,
   177,    83,    41,    29,    30,     2,   182,    31,    21,     3,
    32,     4,    33,     2,   123,   196,    42,     3,    46,     4,
   134,   135,   140,   141,    34,    35,   199,    36,   200,    18,
     5,   169,    37,   130,    29,    30,   116,    38,     5,    23,
    39,   116,    85,    16,    84,    29,    30,    41,   120,    31,
   113,    74,    32,   170,    33,    34,    35,   145,    36,    29,
    30,   131,     0,    37,   133,     0,    34,    35,    38,    36,
     0,    39,     0,     0,    37,     0,     0,     0,    41,    38,
    34,    35,    39,    36,   147,    16,    29,    30,    37,    41,
   107,   108,     0,    38,     0,   149,    39,    29,    30,     0,
     0,   151,     0,    29,    30,     0,   109,    34,    35,     0,
    36,   110,    92,    93,     0,    37,     0,     0,    34,    35,
    38,    36,     0,    39,    34,    35,    37,    36,    94,    95,
     0,    38,    37,   153,    39,    29,    30,    38,     0,   155,
    39,    29,    30,   101,   102,   103,   104,   105,     0,     0,
     0,     0,    29,    30,     0,     0,    34,    35,     0,    36,
     0,     0,    34,    35,    37,    36,   106,     0,     0,    38,
    37,     0,    39,    34,    35,    38,    36,     0,    39,     0,
     0,    37,     0,     0,     0,     0,    38,     0,     0,    39,
   189,   190,   191,   192,   193,   194,   136,   137,   138,   139,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   197
};

static const short yycheck[] = {    11,
   101,   102,   103,   104,   105,   106,    39,     1,   109,    34,
    35,     1,    37,    38,     1,     1,     1,     1,     1,     1,
     1,     0,     1,    43,    40,    40,     5,    18,     9,    45,
     9,    40,    11,    33,    34,    35,    45,    36,     1,    72,
    73,   168,    75,    76,    20,    21,   173,    41,    42,     1,
     1,    30,    42,    65,     1,    41,     1,    47,    41,    41,
    47,    46,    46,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,     1,   110,     3,     4,
     5,   182,     7,    46,     9,    10,    11,    12,     1,    41,
    41,    19,     5,    40,     4,    40,     9,    43,    11,    24,
    25,    42,    27,    41,     3,    30,     1,    32,    16,     4,
    16,   168,    37,    31,    32,    40,   173,    30,    43,    44,
    41,     1,    47,     3,     4,     5,    42,     7,    27,     9,
    10,    11,    12,     5,    29,     6,    44,     9,    44,    11,
    90,    91,    96,    97,    24,    25,     0,    27,     0,     6,
    30,   116,    32,    82,     3,     4,   168,    37,    30,    10,
    40,   173,    44,    43,    44,     3,     4,    47,    69,     7,
    64,    32,    10,   116,    12,    24,    25,     1,    27,     3,
     4,    88,    -1,    32,    89,    -1,    24,    25,    37,    27,
    -1,    40,    -1,    -1,    32,    -1,    -1,    -1,    47,    37,
    24,    25,    40,    27,     1,    43,     3,     4,    32,    47,
    24,    25,    -1,    37,    -1,     1,    40,     3,     4,    -1,
    -1,     1,    -1,     3,     4,    -1,    40,    24,    25,    -1,
    27,    45,    22,    23,    -1,    32,    -1,    -1,    24,    25,
    37,    27,    -1,    40,    24,    25,    32,    27,    38,    39,
    -1,    37,    32,     1,    40,     3,     4,    37,    -1,     1,
    40,     3,     4,    13,    14,    15,    16,    17,    -1,    -1,
    -1,    -1,     3,     4,    -1,    -1,    24,    25,    -1,    27,
    -1,    -1,    24,    25,    32,    27,    36,    -1,    -1,    37,
    32,    -1,    40,    24,    25,    37,    27,    -1,    40,    -1,
    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,
   174,   175,   176,   177,   178,   179,    92,    93,    94,    95,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   196
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
#line 32 "parser.y"
{ semantic(1); ;
    break;}
case 2:
#line 33 "parser.y"
{ semantic(2); ;
    break;}
case 3:
#line 34 "parser.y"
{ semantic(3); ;
    break;}
case 4:
#line 35 "parser.y"
{ semantic(4); ;
    break;}
case 5:
#line 36 "parser.y"
{ semantic(5); ;
    break;}
case 6:
#line 37 "parser.y"
{ semantic(6); ;
    break;}
case 7:
#line 38 "parser.y"
{ yyerrok; ReportParserError("function_def"); ;
    break;}
case 8:
#line 39 "parser.y"
{ semantic(7); ;
    break;}
case 9:
#line 42 "parser.y"
{ semantic(7); ;
    break;}
case 10:
#line 43 "parser.y"
{ semantic(7); ;
    break;}
case 11:
#line 44 "parser.y"
{ semantic(17); ;
    break;}
case 12:
#line 45 "parser.y"
{ yyerrok; ReportParserError("type_only_param"); ;
    break;}
case 13:
#line 46 "parser.y"
{ semantic(20); ;
    break;}
case 14:
#line 47 "parser.y"
{ semantic(21); ;
    break;}
case 15:
#line 48 "parser.y"
{ semantic(21); ;
    break;}
case 16:
#line 49 "parser.y"
{ semantic(21); ;
    break;}
case 17:
#line 50 "parser.y"
{ semantic(22); ;
    break;}
case 18:
#line 52 "parser.y"
{ semantic(8); ;
    break;}
case 19:
#line 53 "parser.y"
{ semantic(9); ;
    break;}
case 20:
#line 54 "parser.y"
{ semantic(10); ;
    break;}
case 21:
#line 55 "parser.y"
{ semantic(11); ;
    break;}
case 22:
#line 56 "parser.y"
{ semantic(12); ;
    break;}
case 23:
#line 57 "parser.y"
{ semantic(13); ;
    break;}
case 24:
#line 58 "parser.y"
{ semantic(14); returnType = 1;;
    break;}
case 25:
#line 59 "parser.y"
{ returnType = 2;;
    break;}
case 26:
#line 60 "parser.y"
{ semantic(15); returnType = 0;;
    break;}
case 27:
#line 61 "parser.y"
{ semantic(16); updateIdentType("function", identStr); updateReturnType(returnType, identStr);;
    break;}
case 29:
#line 63 "parser.y"
{ semantic(17); ;
    break;}
case 30:
#line 64 "parser.y"
{ yyerrok; ReportParserError("formal_param"); ;
    break;}
case 31:
#line 65 "parser.y"
{ semantic(18); ;
    break;}
case 32:
#line 66 "parser.y"
{ semantic(19); ;
    break;}
case 33:
#line 67 "parser.y"
{ semantic(20); ;
    break;}
case 34:
#line 68 "parser.y"
{ semantic(21); ;
    break;}
case 35:
#line 69 "parser.y"
{ semantic(22); ;
    break;}
case 37:
#line 71 "parser.y"
{ semantic(23); ;
    break;}
case 38:
#line 72 "parser.y"
{ semantic(23); ;
    break;}
case 39:
#line 73 "parser.y"
{ yyerrok; ReportParserError("compound_st MISSING RBRACE"); ;
    break;}
case 40:
#line 74 "parser.y"
{ yyerrok; ReportParserError("compound_st MISSING RBRACE"); ;
    break;}
case 41:
#line 75 "parser.y"
{ semantic(26); ;
    break;}
case 42:
#line 76 "parser.y"
{ semantic(27); ;
    break;}
case 43:
#line 77 "parser.y"
{ semantic(28); ;
    break;}
case 44:
#line 78 "parser.y"
{ semantic(29); ;
    break;}
case 45:
#line 79 "parser.y"
{ semantic(28); ;
    break;}
case 46:
#line 80 "parser.y"
{ yyerrok; ReportParserError("declaration MISSING SEMI"); ;
    break;}
case 47:
#line 81 "parser.y"
{ semantic(29); ;
    break;}
case 48:
#line 82 "parser.y"
{ semantic(30); ;
    break;}
case 49:
#line 83 "parser.y"
{ semantic(31); ;
    break;}
case 50:
#line 84 "parser.y"
{ semantic(32); ;
    break;}
case 52:
#line 86 "parser.y"
{ yyerrok; ReportParserError("init_declarator"); ;
    break;}
case 54:
#line 88 "parser.y"
{ semantic(33); updateIdentType("scalar variable", identStr);;
    break;}
case 56:
#line 90 "parser.y"
{ semantic(34);;
    break;}
case 58:
#line 92 "parser.y"
{ yyerrok; ReportParserError("declarator MISSING RBRAKET"); ;
    break;}
case 60:
#line 94 "parser.y"
{ semantic(35); ;
    break;}
case 61:
#line 95 "parser.y"
{ semantic(36); ;
    break;}
case 62:
#line 96 "parser.y"
{ semantic(41); ;
    break;}
case 63:
#line 97 "parser.y"
{ semantic(42); ;
    break;}
case 64:
#line 98 "parser.y"
{ semantic(43); ;
    break;}
case 65:
#line 99 "parser.y"
{ semantic(44); ;
    break;}
case 66:
#line 100 "parser.y"
{ semantic(45); ;
    break;}
case 67:
#line 102 "parser.y"
{ semantic(46); ;
    break;}
case 68:
#line 103 "parser.y"
{ semantic(46); ;
    break;}
case 69:
#line 104 "parser.y"
{ yyerrok; ReportParserError("expression_st MISSING SEMI"); ;
    break;}
case 70:
#line 105 "parser.y"
{ semantic(49); ;
    break;}
case 71:
#line 106 "parser.y"
{ semantic(50); ;
    break;}
case 72:
#line 107 "parser.y"
{ yyerrok; ReportParserError("if_st MISSING RPAREN"); ;
    break;}
case 73:
#line 108 "parser.y"
{ yyerrok; ReportParserError("if_st MISSING LPAREN"); ;
    break;}
case 74:
#line 109 "parser.y"
{ semantic(51); ;
    break;}
case 75:
#line 110 "parser.y"
{ yyerrok; ReportParserError("while_st MISSING RPAREN"); ;
    break;}
case 76:
#line 111 "parser.y"
{ yyerrok; ReportParserError("while_st MISSING LPAREN"); ;
    break;}
case 77:
#line 112 "parser.y"
{ semantic(52); ;
    break;}
case 78:
#line 113 "parser.y"
{ semantic(53); ;
    break;}
case 79:
#line 114 "parser.y"
{ semantic(54); ;
    break;}
case 80:
#line 115 "parser.y"
{ semantic(55); ;
    break;}
case 81:
#line 116 "parser.y"
{ semantic(56); ;
    break;}
case 82:
#line 117 "parser.y"
{ semantic(57); ;
    break;}
case 83:
#line 118 "parser.y"
{ semantic(58); ;
    break;}
case 84:
#line 119 "parser.y"
{ semantic(59); ;
    break;}
case 85:
#line 120 "parser.y"
{ semantic(60); ;
    break;}
case 86:
#line 121 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_EXP"); ;
    break;}
case 87:
#line 122 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_ADDASSIGN_EXP"); ;
    break;}
case 88:
#line 123 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_SUBASSIGN_EXP"); ;
    break;}
case 89:
#line 124 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_MULTIASSIGN_EXP"); ;
    break;}
case 90:
#line 125 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_DIVASSIGN_EXP"); ;
    break;}
case 91:
#line 126 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_MODASSIGN_EXP"); ;
    break;}
case 92:
#line 128 "parser.y"
{ semantic(61); ;
    break;}
case 93:
#line 129 "parser.y"
{ semantic(62); ;
    break;}
case 94:
#line 130 "parser.y"
{ semantic(63); ;
    break;}
case 95:
#line 131 "parser.y"
{ semantic(64); ;
    break;}
case 96:
#line 132 "parser.y"
{ semantic(65); ;
    break;}
case 97:
#line 133 "parser.y"
{ semantic(66); ;
    break;}
case 98:
#line 134 "parser.y"
{ semantic(67); ;
    break;}
case 99:
#line 135 "parser.y"
{ semantic(68); ;
    break;}
case 100:
#line 136 "parser.y"
{ semantic(69); ;
    break;}
case 101:
#line 137 "parser.y"
{ semantic(70); ;
    break;}
case 102:
#line 138 "parser.y"
{ semantic(71); ;
    break;}
case 103:
#line 139 "parser.y"
{ semantic(72); ;
    break;}
case 104:
#line 140 "parser.y"
{ semantic(73); ;
    break;}
case 105:
#line 141 "parser.y"
{ semantic(74); ;
    break;}
case 106:
#line 142 "parser.y"
{ semantic(75); ;
    break;}
case 107:
#line 143 "parser.y"
{ semantic(76); ;
    break;}
case 108:
#line 144 "parser.y"
{ semantic(77); ;
    break;}
case 109:
#line 145 "parser.y"
{ semantic(78); ;
    break;}
case 110:
#line 146 "parser.y"
{ semantic(79); ;
    break;}
case 111:
#line 147 "parser.y"
{ semantic(80); ;
    break;}
case 112:
#line 148 "parser.y"
{ semantic(81); ;
    break;}
case 113:
#line 149 "parser.y"
{ semantic(82); ;
    break;}
case 114:
#line 150 "parser.y"
{ semantic(83); ;
    break;}
case 115:
#line 151 "parser.y"
{ semantic(84); ;
    break;}
case 116:
#line 152 "parser.y"
{ semantic(85); ;
    break;}
case 117:
#line 153 "parser.y"
{ semantic(86); ;
    break;}
case 118:
#line 154 "parser.y"
{ semantic(87); ;
    break;}
case 119:
#line 155 "parser.y"
{ semantic(88); ;
    break;}
case 120:
#line 156 "parser.y"
{ semantic(89); ;
    break;}
case 121:
#line 157 "parser.y"
{ yyerrok; ReportParserError("postfix_exp"); ;
    break;}
case 122:
#line 158 "parser.y"
{ yyerrok; ReportParserError("postfix_exp"); ;
    break;}
case 123:
#line 159 "parser.y"
{ semantic(90); ;
    break;}
case 124:
#line 160 "parser.y"
{ semantic(91); ;
    break;}
case 125:
#line 161 "parser.y"
{ semantic(92); ;
    break;}
case 126:
#line 162 "parser.y"
{ semantic(93); ;
    break;}
case 127:
#line 163 "parser.y"
{ semantic(94); ;
    break;}
case 128:
#line 164 "parser.y"
{ semantic(95); ;
    break;}
case 130:
#line 166 "parser.y"
{ semantic(96); ;
    break;}
case 131:
#line 167 "parser.y"
{ yyerrok; ReportParserError("primary_exp"); ;
    break;}
case 132:
#line 168 "parser.y"
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
#line 169 "parser.y"
  

void semantic(int n)
{
   // printf("reduced rule number = %d\n", n);
}


/* void ReportParserError(char* message, in)
{
   printf("--------------------- %s %d\n", message);
} */


void updateIdentType(const char *type, const char *identifier)
{
    printf("-------------------------updateIdentType-------------------------\n");
    int length = strlen(identifier);

    // 인식된 identifier의 해시값으로 해시테이블과 심볼테이블에 접근해 identifier가 저장되어있는지 확인
    int hashValue = divisionMethod(identifier, HASH_TABLE_SIZE);
    HTpointer hash_ident = lookup_hash_table(identifier, hashValue);

    bool isExist = false;

    // hash_ident 값이 NULL이라면, 해당 identifier가 해시테이블에 저장된 적이 없다는 뜻

    // lookup_sym_table 함수를 통해 심볼테이블의 hash_ident.index 번째 인덱스에 identifier가 저장되어있는지 확인 후 bool 값 return
    // isExist가 false라면 연결된 다음 identifier를 hash_ident에 저장 후 다시 반복
    while (hash_ident != NULL && !isExist) {	
        isExist = lookup_sym_table(identifier, hash_ident->index); 
        if (!isExist) {
            hash_ident = hash_ident->next; 
        }
    }
    printf("identifier: %s\n", identifier);

    if (hash_ident == NULL){
        // 처리해주기
    }

    // sym_table에서 identifier 정보 가져오기
    struct Ident sym_ident = sym_table[hash_ident->index];     

    // identifier의 type 정보가 NULL이거나 "none"이라면 identifier의 type 정보를 업데이트
    if (sym_ident.ident_type == NULL || strcmp(sym_ident.ident_type, "none") == 0) {
        strncpy_s(sym_ident.ident_type, sizeof(sym_ident.ident_type), type, _TRUNCATE);	
        sym_ident.ident_type[sizeof(sym_ident.ident_type) - 1] = '\0'; 
        sym_table[hash_ident->index] = sym_ident;
        printf("sym_ident.ident_type: %s", sym_ident.ident_type);
    } 
    else {
        if (sym_ident.linenumber != currlinenum) {
            printf("Already declared\n");
        }
    }
    printf("updateIdentType complete\n");
}

void updateReturnType(int returntype, const char *identifier)
{
   printf("-------------------------updateReturnType-------------------------\n");
    int length = strlen(identifier);

    // 해당 identifier의 해시코드 구하기
    int hashValue = divisionMethod(identifier, HASH_TABLE_SIZE);

    HTpointer hash_ident = lookup_hash_table(identifier, hashValue);
    bool isExist = false; 	// Hash Table을 읽기 전, false로 초기화

    // hash code 위치에 어떠한 문자라도 존재하는 경우
    while (hash_ident != NULL && !isExist) {	// 현재 가리키는 위치에 문자가 있고 아직 identifier가 발견되지 않은 경우
        isExist = lookup_sym_table(identifier, hash_ident->index);  // 새로운 함수를 사용하여 비교
        if (!isExist) {
            hash_ident = hash_ident->next;  // linked list의 다음 identifier로 이동
        }
    }
    
    if (hash_ident != NULL) {
        // 처리해주기
    }

    // identifier의 type 정보가 function일 경우에만 return값 정보 업데이트
    struct Ident sym_ident = sym_table[hash_ident->index];   
    if (strcmp(sym_ident.ident_type, "function") == 0) {	// type이 function name인 경우
        snprintf(sym_ident.return_type, sizeof(sym_ident.return_type), "%d", returntype);	// 매개변수로 받은 returntype 설정
        printf("sym_ident.return_type: %s", sym_ident.return_type);
        sym_table[hash_ident->index] = sym_ident;
    } 
    else {
        snprintf(sym_ident.return_type, sizeof(sym_ident.return_type), "-1");	// function name이 아닌 경우는 -1로 설정
        sym_table[hash_ident->index] = sym_ident;
    }
    printf("updateReturnType complete\n");
}