
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

extern int lineNumber; 
extern const char* dataTypesChar[];
extern void semantic(int);
extern void ReportParserError(char* message);
HTpointer getIdentHash(const char *identifier);
int getIdentType(const char *identifier);
int checkIdentExists(const char *identifier);
void updateIdentType(int numType, dataType variableType, const char *identifier); 
void updateReturnType(int returnType, const char *identifier); 
void updateFunctionParameter(int type, dataType variableType, const char *function_name);
void updateInvokedFuncArgs(dataType argument_type);
void isIllegalInvoke(const char *function_name);

int numType = 0;
char currentFunctionName[1000]; // 함수 이름 저장용 전역 변수

// 함수 정상 사용 체크를 위한 파라미터 배열과 파라미터 개수 변수
dataType* invoked_func_args;
int invoked_func_args_cnt = 0;

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



#define	YYFINAL		211
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
     0,     2,     4,     7,     9,    11,    14,    17,    21,    24,
    27,    31,    35,    37,    41,    45,    49,    51,    53,    55,
    58,    60,    62,    64,    66,    68,    70,    72,    74,    75,
    79,    83,    85,    86,    88,    92,    96,    99,   102,   105,
   109,   113,   115,   116,   118,   121,   123,   125,   129,   133,
   135,   139,   141,   143,   147,   151,   155,   159,   163,   167,
   169,   171,   173,   178,   183,   185,   186,   188,   190,   192,
   194,   196,   199,   201,   204,   208,   214,   222,   228,   234,
   240,   246,   252,   255,   257,   259,   263,   267,   269,   271,
   273,   275,   277,   279,   281,   285,   289,   291,   295,   299,
   301,   305,   309,   313,   317,   319,   323,   327,   331,   335,
   339,   343,   347,   351,   353,   357,   361,   365,   369,   371,
   375,   379,   383,   387,   391,   395,   397,   399,   401,   403,
   406,   409,   412,   415,   417,   422,   427,   430,   433,   438,
   443,   445,   446,   448,   450,   454,   456,   458,   462
};

static const short yyrhs[] = {    50,
     0,    51,     0,    50,    51,     0,    52,     0,    72,     0,
    53,    68,     0,     1,    68,     0,    58,    63,    64,     0,
    63,    55,     0,    63,    64,     0,    40,    56,    41,     0,
    40,    56,     1,     0,    57,     0,    56,    42,    57,     0,
    56,    42,    67,     0,    66,    42,    57,     0,    60,     0,
    59,     0,    60,     0,    59,    60,     0,    61,     0,    62,
     0,     5,     0,     9,     0,    30,     0,    11,     0,     3,
     0,    27,     0,     0,    40,    65,    41,     0,    40,    65,
     1,     0,    66,     0,     0,    67,     0,    66,    42,    67,
     0,    66,    67,     1,     0,    60,    75,     0,    60,    76,
     0,    60,    54,     0,    43,    69,    44,     0,    43,    69,
     1,     0,    70,     0,     0,    71,     0,    70,    71,     0,
    72,     0,    78,     0,    58,    73,    47,     0,    58,    73,
     1,     0,    74,     0,    73,    42,    74,     0,    75,     0,
    76,     0,    75,    36,     4,     0,    75,    36,    29,     0,
    76,    36,     4,     0,    76,    36,    29,     0,    75,    36,
     1,     0,    76,    36,     1,     0,    54,     0,     3,     0,
    27,     0,    75,    45,    77,    46,     0,    75,    45,    77,
     1,     0,     4,     0,     0,    68,     0,    79,     0,    80,
     0,    81,     0,    82,     0,    83,    47,     0,    47,     0,
    83,     1,     0,    83,     1,    85,     0,     7,    40,    83,
    41,    78,     0,     7,    40,    83,    41,    78,     6,    78,
     0,     7,    40,    83,     1,    78,     0,     7,     1,    83,
    41,    78,     0,    12,    40,    83,    41,    78,     0,    12,
    40,    83,     1,    78,     0,    12,     1,    83,    41,    78,
     0,    10,    79,     0,    84,     0,    86,     0,    94,    85,
    84,     0,    94,    85,     1,     0,    36,     0,    13,     0,
    14,     0,    15,     0,    16,     0,    17,     0,    87,     0,
    86,    18,    87,     0,    86,    18,     1,     0,    88,     0,
    87,    19,    88,     0,    87,    19,     1,     0,    89,     0,
    88,    20,    89,     0,    88,    21,    89,     0,    88,    20,
     1,     0,    88,    21,     1,     0,    90,     0,    89,    39,
    90,     0,    89,    38,    90,     0,    89,    22,    90,     0,
    89,    23,    90,     0,    89,    39,     1,     0,    89,    38,
     1,     0,    89,    22,     1,     0,    89,    23,     1,     0,
    91,     0,    90,    31,    91,     0,    90,    32,    91,     0,
    90,    31,     1,     0,    90,    32,     1,     0,    92,     0,
    91,    33,    92,     0,    91,    34,    92,     0,    91,    35,
    92,     0,    91,    33,     1,     0,    91,    34,     1,     0,
    91,    35,     1,     0,    93,     0,     4,     0,    29,     0,
    94,     0,    32,    93,     0,    37,    93,     0,    24,    93,
     0,    25,    93,     0,    98,     0,    94,    45,    83,    46,
     0,    94,    40,    95,    41,     0,    94,    24,     0,    94,
    25,     0,    94,    45,    83,     1,     0,    94,    40,    95,
     1,     0,    96,     0,     0,    97,     0,    84,     0,    97,
    42,    84,     0,     3,     0,    27,     0,    40,    83,     1,
     0,    40,    83,    41,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    56,    57,    58,    59,    60,    61,    62,    63,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    87,    88,    90,
    91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
   102,   104,   105,   107,   108,   109,   110,   112,   113,   114,
   115,   116,   117,   118,   120,   122,   123,   125,   126,   127,
   129,   130,   132,   133,   135,   136,   137,   138,   139,   140,
   141,   143,   144,   145,   146,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   158,   159,   160,   162,   163,   164,
   165,   166,   167,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   181,   182,   183,   184,   185,   186,
   187,   188,   189,   191,   192,   193,   194,   195,   197,   198,
   199,   200,   201,   202,   203,   205,   206,   207,   209,   210,
   211,   212,   213,   215,   216,   217,   218,   219,   220,   221,
   223,   224,   225,   226,   227,   228,   229,   230,   231
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
"compound_st","opt_block_items","block_item_list","block_item","declaration",
"init_dcl_list","init_declarator","ident","array","opt_number","statement","expression_st",
"if_st","while_st","return_st","expression","assignment_exp","assignment_op",
"logical_or_exp","logical_and_exp","equality_exp","relational_exp","additive_exp",
"multiplicative_exp","unary_number","unary_exp","postfix_exp","opt_actual_param",
"actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    52,    52,    53,    54,    54,
    55,    55,    56,    56,    56,    56,    57,    58,    59,    59,
    60,    60,    61,    62,    62,    62,    63,    63,    63,    64,
    64,    65,    65,    66,    66,    66,    67,    67,    67,    68,
    68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
    73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
    75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
    78,    79,    79,    79,    79,    80,    80,    80,    80,    81,
    81,    81,    82,    83,    84,    84,    84,    85,    85,    85,
    85,    85,    85,    86,    86,    86,    87,    87,    87,    88,
    88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
    89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
    91,    91,    91,    91,    91,    92,    92,    92,    93,    93,
    93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
    95,    95,    96,    97,    97,    98,    98,    98,    98
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     3,     2,     2,
     3,     3,     1,     3,     3,     3,     1,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
     3,     1,     0,     1,     3,     3,     2,     2,     2,     3,
     3,     1,     0,     1,     2,     1,     1,     3,     3,     1,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
     1,     1,     4,     4,     1,     0,     1,     1,     1,     1,
     1,     2,     1,     2,     3,     5,     7,     5,     5,     5,
     5,     5,     2,     1,     1,     3,     3,     1,     1,     1,
     1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
     3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
     3,     3,     3,     3,     3,     1,     1,     1,     1,     2,
     2,     2,     2,     1,     4,     4,     2,     2,     4,     4,
     1,     0,     1,     1,     3,     1,     1,     3,     3
};

static const short yydefact[] = {     0,
     0,    23,    24,    26,    25,     0,     2,     4,     0,    29,
    18,    19,    21,    22,     5,    43,     7,     3,     6,    61,
    62,    60,     0,     0,    50,    52,    53,    20,   146,   127,
     0,     0,     0,     0,     0,   147,   128,     0,     0,     0,
    73,    29,    67,     0,    42,    44,    46,    47,    68,    69,
    70,    71,     0,    84,    85,    94,    97,   100,   105,   114,
   119,   126,   129,   134,    33,     9,    10,    49,    29,    48,
     0,    66,     0,     0,     0,    83,     0,     0,   132,   129,
   133,   130,   131,     0,     0,    41,    40,    45,    74,    72,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    89,    90,    91,    92,    93,   137,   138,
    88,   142,     0,     0,     0,    13,    17,     0,    32,    34,
    51,    58,    54,    55,    65,     0,    59,    56,    57,     0,
     0,     0,     0,   148,   149,    10,    75,    96,    95,    99,
    98,   103,   101,   104,   102,   112,   108,   113,   109,   111,
   107,   110,   106,   117,   115,   118,   116,   123,   120,   124,
   121,   125,   122,   144,     0,   141,   143,     0,    87,    86,
    12,    11,     0,    39,    37,    38,    31,    30,     0,    29,
     0,    64,    63,     0,     0,     0,     0,     0,     0,   140,
   136,     0,   139,   135,    14,    15,    16,    35,    36,    79,
    78,    76,    82,    81,    80,   145,     0,    77,     0,     0,
     0
};

static const short yydefgoto[] = {   209,
     6,     7,     8,     9,    22,    66,   115,   116,    10,    11,
    12,    13,    14,    85,    67,   118,   119,   120,    43,    44,
    45,    46,    15,    24,    25,    26,    27,   126,    48,    49,
    50,    51,    52,    53,    54,   114,    55,    56,    57,    58,
    59,    60,    61,    62,    63,   165,   166,   167,    64
};

static const short yypact[] = {   416,
   -14,-32768,-32768,-32768,-32768,    21,-32768,-32768,   -14,   110,
   342,-32768,-32768,-32768,-32768,    82,-32768,-32768,-32768,   -15,
    -7,-32768,    -5,     5,-32768,   -18,     2,-32768,-32768,-32768,
    40,   145,    94,   353,   353,-32768,-32768,   353,   353,   371,
-32768,   110,-32768,    14,    82,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,     6,-32768,    83,    86,    24,   137,    65,   254,
-32768,-32768,   399,-32768,   342,-32768,    67,-32768,   110,-32768,
   126,   136,   127,   371,   371,-32768,   371,   371,-32768,    75,
-32768,-32768,-32768,    15,    -5,-32768,-32768,-32768,   439,-32768,
   162,   180,   194,   212,   221,   239,   253,   271,   280,   298,
   312,   330,   339,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   371,   371,   357,    18,-32768,    76,    41,    93,-32768,
-32768,-32768,-32768,-32768,-32768,     9,-32768,-32768,-32768,    95,
    42,   101,    47,-32768,-32768,-32768,-32768,-32768,    86,-32768,
    24,-32768,   137,-32768,   137,-32768,    65,-32768,    65,-32768,
    65,-32768,    65,-32768,   254,-32768,   254,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    49,-32768,   105,    11,-32768,-32768,
-32768,-32768,   342,-32768,   107,-32768,-32768,-32768,   342,   110,
   149,-32768,-32768,   114,   114,   114,   114,   114,   114,-32768,
-32768,   371,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   147,-32768,-32768,-32768,-32768,   114,-32768,   158,   164,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   161,-32768,-32768,  -106,-32768,-32768,  -145,     1,-32768,
   -11,-32768,-32768,   163,   103,-32768,-32768,   -95,    22,-32768,
-32768,   148,     4,-32768,   102,  -104,  -103,-32768,   244,   168,
-32768,-32768,-32768,   -38,  -111,   112,-32768,    99,   104,    39,
   132,    45,    77,   367,   -30,-32768,-32768,-32768,-32768
};


#define	YYLAST		475


static const short yytable[] = {    28,
   164,    84,   170,    80,    80,    68,    89,    80,    80,   182,
   174,   193,   175,   176,    86,   134,    42,    71,   171,    47,
    -1,     1,    17,   181,   -27,     2,    72,   195,    16,     3,
    19,     4,   -28,   197,    65,   130,   131,    73,   132,   133,
    74,   177,   185,    93,    94,    42,    69,   188,    47,   190,
     5,    70,    90,   117,   183,   135,   194,    87,   172,   173,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    80,    80,   174,   168,   175,   176,   196,    20,    75,
   206,   178,   186,   198,    29,    30,     2,   189,    31,   191,
     3,    32,     4,    33,    77,    99,   100,     2,   109,   110,
    91,     3,    21,     4,    92,    34,    35,   180,    36,    -8,
    37,     5,    20,    38,   112,   -29,    29,    30,    39,   113,
    31,    40,     5,    32,    16,    33,   122,   127,    41,   123,
   128,   143,   145,    78,   179,   184,    21,    34,    35,   125,
    36,   187,    37,   155,   157,    38,   192,    29,    30,   199,
    39,    72,   207,    40,   124,   129,    16,   210,    95,    96,
    41,   117,   138,   211,    29,    30,    18,   117,    34,    35,
   121,    36,    23,    37,    97,    98,    38,   159,   161,   163,
   140,    39,    29,    30,    40,    34,    35,   136,    36,   139,
    37,    41,    88,    38,   142,   141,    29,    30,    39,    76,
   137,    40,     0,    34,    35,     0,    36,     0,    37,     0,
     0,    38,   144,     0,    29,    30,    39,    34,    35,    40,
    36,   146,    37,    29,    30,    38,   147,   149,   151,   153,
    39,     0,     0,    40,     0,    34,    35,     0,    36,   148,
    37,    29,    30,    38,    34,    35,     0,    36,    39,    37,
     0,    40,    38,   150,     0,    29,    30,    39,     0,     0,
    40,     0,    34,    35,     0,    36,     0,    37,     0,     0,
    38,   152,     0,    29,    30,    39,    34,    35,    40,    36,
   154,    37,    29,    30,    38,     0,   101,   102,   103,    39,
     0,     0,    40,     0,    34,    35,     0,    36,   156,    37,
    29,    30,    38,    34,    35,     0,    36,    39,    37,     0,
    40,    38,   158,     0,    29,    30,    39,     0,     0,    40,
     0,    34,    35,     0,    36,     0,    37,     0,     0,    38,
   160,     0,    29,    30,    39,    34,    35,    40,    36,   162,
    37,    29,    30,    38,     0,     0,     2,     0,    39,     0,
     3,    40,     4,    34,    35,    29,    36,   169,    37,    29,
    30,    38,    34,    35,     0,    36,    39,    37,     0,    40,
    38,     5,     0,    29,    30,    39,    34,    35,    40,    36,
    34,    35,     0,    36,    38,    37,     0,     0,    38,    39,
     0,     0,    40,    39,    34,    35,    40,    36,     0,    37,
    79,    81,    38,     0,    82,    83,     0,    39,     0,     0,
    40,   104,   105,   106,   107,   108,     1,     0,     0,     0,
     2,     0,   109,   110,     3,     0,     4,   200,   201,   202,
   203,   204,   205,     0,   111,     0,     0,     0,   112,     0,
     0,     0,     0,   113,     0,     5,     0,     0,     0,     0,
   208,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   111
};

static const short yycheck[] = {    11,
   112,    40,   114,    34,    35,     1,     1,    38,    39,     1,
   117,     1,   117,   117,     1,     1,    16,    36,     1,    16,
     0,     1,     1,   119,    40,     5,    45,   173,    43,     9,
     9,    11,    40,   179,    40,    74,    75,    36,    77,    78,
     1,     1,     1,    20,    21,    45,    42,     1,    45,     1,
    30,    47,    47,    65,    46,    41,    46,    44,    41,    42,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   180,   113,   180,   180,   173,     3,    40,
   192,    41,    41,   179,     3,     4,     5,    41,     7,    41,
     9,    10,    11,    12,     1,    31,    32,     5,    24,    25,
    18,     9,    27,    11,    19,    24,    25,   119,    27,    43,
    29,    30,     3,    32,    40,    40,     3,     4,    37,    45,
     7,    40,    30,    10,    43,    12,     1,     1,    47,     4,
     4,    93,    94,    40,    42,    41,    27,    24,    25,     4,
    27,    41,    29,    99,   100,    32,    42,     3,     4,     1,
    37,    45,     6,    40,    29,    29,    43,     0,    22,    23,
    47,   173,     1,     0,     3,     4,     6,   179,    24,    25,
    69,    27,    10,    29,    38,    39,    32,   101,   102,   103,
     1,    37,     3,     4,    40,    24,    25,    85,    27,    91,
    29,    47,    45,    32,     1,    92,     3,     4,    37,    32,
    89,    40,    -1,    24,    25,    -1,    27,    -1,    29,    -1,
    -1,    32,     1,    -1,     3,     4,    37,    24,    25,    40,
    27,     1,    29,     3,     4,    32,    95,    96,    97,    98,
    37,    -1,    -1,    40,    -1,    24,    25,    -1,    27,     1,
    29,     3,     4,    32,    24,    25,    -1,    27,    37,    29,
    -1,    40,    32,     1,    -1,     3,     4,    37,    -1,    -1,
    40,    -1,    24,    25,    -1,    27,    -1,    29,    -1,    -1,
    32,     1,    -1,     3,     4,    37,    24,    25,    40,    27,
     1,    29,     3,     4,    32,    -1,    33,    34,    35,    37,
    -1,    -1,    40,    -1,    24,    25,    -1,    27,     1,    29,
     3,     4,    32,    24,    25,    -1,    27,    37,    29,    -1,
    40,    32,     1,    -1,     3,     4,    37,    -1,    -1,    40,
    -1,    24,    25,    -1,    27,    -1,    29,    -1,    -1,    32,
     1,    -1,     3,     4,    37,    24,    25,    40,    27,     1,
    29,     3,     4,    32,    -1,    -1,     5,    -1,    37,    -1,
     9,    40,    11,    24,    25,     3,    27,     1,    29,     3,
     4,    32,    24,    25,    -1,    27,    37,    29,    -1,    40,
    32,    30,    -1,     3,     4,    37,    24,    25,    40,    27,
    24,    25,    -1,    27,    32,    29,    -1,    -1,    32,    37,
    -1,    -1,    40,    37,    24,    25,    40,    27,    -1,    29,
    34,    35,    32,    -1,    38,    39,    -1,    37,    -1,    -1,
    40,    13,    14,    15,    16,    17,     1,    -1,    -1,    -1,
     5,    -1,    24,    25,     9,    -1,    11,   184,   185,   186,
   187,   188,   189,    -1,    36,    -1,    -1,    -1,    40,    -1,
    -1,    -1,    -1,    45,    -1,    30,    -1,    -1,    -1,    -1,
   207,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    36
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
#line 56 "parser.y"
{ semantic(1); ;
    break;}
case 2:
#line 57 "parser.y"
{ semantic(2); ;
    break;}
case 3:
#line 58 "parser.y"
{ semantic(3); ;
    break;}
case 4:
#line 59 "parser.y"
{ semantic(4); ;
    break;}
case 5:
#line 60 "parser.y"
{ semantic(5); ;
    break;}
case 6:
#line 61 "parser.y"
{ semantic(6); ;
    break;}
case 7:
#line 62 "parser.y"
{ yyerrok; ReportParserError("function_def"); ;
    break;}
case 8:
#line 63 "parser.y"
{ semantic(7); ;
    break;}
case 9:
#line 66 "parser.y"
{ semantic(7); ;
    break;}
case 10:
#line 67 "parser.y"
{ semantic(7); ;
    break;}
case 12:
#line 69 "parser.y"
{ yyerrok; ReportParserError("type_only_param"); ;
    break;}
case 13:
#line 70 "parser.y"
{ semantic(20); ;
    break;}
case 14:
#line 71 "parser.y"
{ semantic(21); ;
    break;}
case 15:
#line 72 "parser.y"
{ semantic(21); ;
    break;}
case 16:
#line 73 "parser.y"
{ semantic(21); ;
    break;}
case 17:
#line 74 "parser.y"
{ updateFunctionParameter(numType, scalar, currentFunctionName); ;
    break;}
case 18:
#line 75 "parser.y"
{ semantic(8); ;
    break;}
case 19:
#line 76 "parser.y"
{ semantic(9); ;
    break;}
case 20:
#line 77 "parser.y"
{ semantic(10); ;
    break;}
case 21:
#line 78 "parser.y"
{ semantic(11); ;
    break;}
case 22:
#line 79 "parser.y"
{ semantic(12); ;
    break;}
case 23:
#line 80 "parser.y"
{ semantic(13); ;
    break;}
case 24:
#line 81 "parser.y"
{ semantic(14); numType = 1; ;
    break;}
case 25:
#line 82 "parser.y"
{ numType = 2;;
    break;}
case 26:
#line 83 "parser.y"
{ numType = 0;;
    break;}
case 27:
#line 84 "parser.y"
{ updateIdentType(numType, function, identStr); updateReturnType(numType, identStr); 
                                                                                                strncpy(currentFunctionName, identStr, 1000);
                                                                                             ;
    break;}
case 29:
#line 88 "parser.y"
{ yyerrok; ReportParserError("NO_FUNC_NAME");
    break;}
case 30:
#line 90 "parser.y"
{ semantic(17); ;
    break;}
case 31:
#line 91 "parser.y"
{ yyerrok; ReportParserError("formal_param"); ;
    break;}
case 32:
#line 92 "parser.y"
{ semantic(18); ;
    break;}
case 33:
#line 93 "parser.y"
{ semantic(19); ;
    break;}
case 34:
#line 94 "parser.y"
{ semantic(20); ;
    break;}
case 35:
#line 95 "parser.y"
{ semantic(21); ;
    break;}
case 36:
#line 96 "parser.y"
{ yyerrok; ReportParserError("NO_COMMA"); ;
    break;}
case 37:
#line 98 "parser.y"
{ updateIdentType(numType, scalar, identStr); updateFunctionParameter(numType, scalar, currentFunctionName); ;
    break;}
case 38:
#line 99 "parser.y"
{ updateIdentType(numType, array, identStr); updateFunctionParameter(numType, array, currentFunctionName); ;
    break;}
case 40:
#line 101 "parser.y"
{ semantic(23); ;
    break;}
case 41:
#line 102 "parser.y"
{ yyerrok; ReportParserError("compound_st MISSING RBRACE"); ;
    break;}
case 44:
#line 107 "parser.y"
{ semantic(26); ;
    break;}
case 45:
#line 108 "parser.y"
{ semantic(27); ;
    break;}
case 46:
#line 109 "parser.y"
{ semantic(28); ;
    break;}
case 47:
#line 110 "parser.y"
{ semantic(29); ;
    break;}
case 48:
#line 112 "parser.y"
{ semantic(28); ;
    break;}
case 49:
#line 113 "parser.y"
{ yyerrok; ReportParserError("declaration MISSING SEMI"); ;
    break;}
case 50:
#line 114 "parser.y"
{ semantic(29); ;
    break;}
case 51:
#line 115 "parser.y"
{ semantic(30); ;
    break;}
case 52:
#line 116 "parser.y"
{ updateIdentType(numType, scalar, identStr); ;
    break;}
case 53:
#line 117 "parser.y"
{ updateIdentType(numType, array, identStr); ;
    break;}
case 54:
#line 118 "parser.y"
{ updateIdentType(numType, scalar, identStr);
                                                                                                if (getIdentType(identStr) != 1) ReportParserError("type mismatch in initialization"); ;
    break;}
case 55:
#line 120 "parser.y"
{ updateIdentType(numType, scalar, identStr); 
                                                                                                if (getIdentType(identStr) != 2) ReportParserError("type mismatch in initialization"); ;
    break;}
case 56:
#line 122 "parser.y"
{ updateIdentType(numType, array, identStr);;
    break;}
case 57:
#line 123 "parser.y"
{ updateIdentType(numType, array, identStr); 
                                                                                                if (getIdentType(identStr) != 2) ReportParserError("type mismatch in initialization"); ;
    break;}
case 58:
#line 125 "parser.y"
{ yyerrok; ReportParserError("init_declarator"); ;
    break;}
case 59:
#line 126 "parser.y"
{ yyerrok; ReportParserError("init_declarator"); ;
    break;}
case 64:
#line 133 "parser.y"
{ yyerrok; ReportParserError("declarator MISSING RBRAKET"); ;
    break;}
case 65:
#line 135 "parser.y"
{ semantic(35); ;
    break;}
case 66:
#line 136 "parser.y"
{ semantic(36); ;
    break;}
case 67:
#line 137 "parser.y"
{ semantic(41); ;
    break;}
case 68:
#line 138 "parser.y"
{ semantic(42); ;
    break;}
case 69:
#line 139 "parser.y"
{ semantic(43); ;
    break;}
case 70:
#line 140 "parser.y"
{ semantic(44); ;
    break;}
case 71:
#line 141 "parser.y"
{ semantic(45); ;
    break;}
case 72:
#line 143 "parser.y"
{ semantic(46); ;
    break;}
case 73:
#line 144 "parser.y"
{ semantic(46); ;
    break;}
case 74:
#line 145 "parser.y"
{ yyerrok; ReportParserError("expression_st MISSING SEMI"); ;
    break;}
case 75:
#line 146 "parser.y"
{ yyerrok; ReportParserError("cannot assign to invalid lvalue");;
    break;}
case 76:
#line 148 "parser.y"
{ semantic(49); ;
    break;}
case 77:
#line 149 "parser.y"
{ semantic(50); ;
    break;}
case 78:
#line 150 "parser.y"
{ yyerrok; ReportParserError("if_st MISSING RPAREN"); ;
    break;}
case 79:
#line 151 "parser.y"
{ yyerrok; ReportParserError("if_st MISSING LPAREN"); ;
    break;}
case 80:
#line 152 "parser.y"
{ semantic(51); ;
    break;}
case 81:
#line 153 "parser.y"
{ yyerrok; ReportParserError("while_st MISSING RPAREN"); ;
    break;}
case 82:
#line 154 "parser.y"
{ yyerrok; ReportParserError("while_st MISSING LPAREN"); ;
    break;}
case 83:
#line 155 "parser.y"
{ semantic(52); ;
    break;}
case 84:
#line 156 "parser.y"
{ semantic(53); ;
    break;}
case 86:
#line 159 "parser.y"
{ semantic(55); ;
    break;}
case 87:
#line 160 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_ASSIGNMENT_EXP"); ;
    break;}
case 94:
#line 169 "parser.y"
{ semantic(61); ;
    break;}
case 95:
#line 170 "parser.y"
{ semantic(62); ;
    break;}
case 96:
#line 171 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_LOGICAL_OR_EXP");;
    break;}
case 97:
#line 172 "parser.y"
{ semantic(63); ;
    break;}
case 98:
#line 173 "parser.y"
{ semantic(64); ;
    break;}
case 99:
#line 174 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_LOGICAL_AND_EXP");;
    break;}
case 100:
#line 175 "parser.y"
{ semantic(65); ;
    break;}
case 101:
#line 176 "parser.y"
{ semantic(66); ;
    break;}
case 102:
#line 177 "parser.y"
{ semantic(67); ;
    break;}
case 103:
#line 178 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TEQUAL_EXP");;
    break;}
case 104:
#line 179 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TNOTEQU_EXP");;
    break;}
case 105:
#line 181 "parser.y"
{ semantic(68); ;
    break;}
case 106:
#line 182 "parser.y"
{ semantic(69); ;
    break;}
case 107:
#line 183 "parser.y"
{ semantic(70); ;
    break;}
case 108:
#line 184 "parser.y"
{ semantic(71); ;
    break;}
case 109:
#line 185 "parser.y"
{ semantic(72); ;
    break;}
case 110:
#line 186 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TGREAT_EXP");;
    break;}
case 111:
#line 187 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TELSE_EXP");;
    break;}
case 112:
#line 188 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TGREATE_EXP");;
    break;}
case 113:
#line 189 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TLESSE_EXP");;
    break;}
case 114:
#line 191 "parser.y"
{ semantic(73); ;
    break;}
case 115:
#line 192 "parser.y"
{ semantic(74); ;
    break;}
case 116:
#line 193 "parser.y"
{ semantic(75); ;
    break;}
case 117:
#line 194 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TADD_EXP");;
    break;}
case 118:
#line 195 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TSUB_EXP");;
    break;}
case 119:
#line 197 "parser.y"
{ semantic(76); ;
    break;}
case 120:
#line 198 "parser.y"
{ semantic(77); ;
    break;}
case 121:
#line 199 "parser.y"
{ semantic(78); ;
    break;}
case 122:
#line 200 "parser.y"
{ semantic(79); ;
    break;}
case 123:
#line 201 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TMUL_EXP"); ;
    break;}
case 124:
#line 202 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TDIV_EXP"); ;
    break;}
case 125:
#line 203 "parser.y"
{ yyerrok; ReportParserError("NO_RIGHT_TMOD_EXP"); ;
    break;}
case 127:
#line 206 "parser.y"
{ if (getIdentType(identStr) != 1) ReportParserError("type mismatch in assignment"); ;
    break;}
case 128:
#line 207 "parser.y"
{ if (getIdentType(identStr) != 2) ReportParserError("type mismatch in assignment"); ;
    break;}
case 129:
#line 209 "parser.y"
{ semantic(80); ;
    break;}
case 130:
#line 210 "parser.y"
{ semantic(81); ;
    break;}
case 131:
#line 211 "parser.y"
{ semantic(82); ;
    break;}
case 132:
#line 212 "parser.y"
{ semantic(83); ;
    break;}
case 133:
#line 213 "parser.y"
{ semantic(84); ;
    break;}
case 134:
#line 215 "parser.y"
{ semantic(85); ;
    break;}
case 135:
#line 216 "parser.y"
{ semantic(86); ;
    break;}
case 136:
#line 217 "parser.y"
{ semantic(87); ;
    break;}
case 137:
#line 218 "parser.y"
{ semantic(88); ;
    break;}
case 138:
#line 219 "parser.y"
{ semantic(89); ;
    break;}
case 139:
#line 220 "parser.y"
{ yyerrok; ReportParserError("postfix_exp"); ;
    break;}
case 140:
#line 221 "parser.y"
{ yyerrok; ReportParserError("postfix_exp"); ;
    break;}
case 141:
#line 223 "parser.y"
{ semantic(90); ;
    break;}
case 142:
#line 224 "parser.y"
{ semantic(91); ;
    break;}
case 143:
#line 225 "parser.y"
{ semantic(92); ;
    break;}
case 144:
#line 226 "parser.y"
{ semantic(93); ;
    break;}
case 145:
#line 227 "parser.y"
{ semantic(94); ;
    break;}
case 146:
#line 228 "parser.y"
{ if (!checkIdentExists(identStr)) { ReportParserError("invalid identifier"); };
    break;}
case 148:
#line 230 "parser.y"
{ yyerrok; ReportParserError("primary_exp"); ;
    break;}
case 149:
#line 231 "parser.y"
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
#line 232 "parser.y"
  

void semantic(int n)
{
   // printf("reduced rule number = %d\n", n);
}

HTpointer getIdentHash(const char *identifier)
{
   // 해당 identifier의 해시코드 구하기
   int hashValue = divisionMethod(identifier, HASH_TABLE_SIZE);
   // 인식된 identifier의 해시값으로 해시테이블과 심볼테이블에 접근해 identifier가 저장되어있는지 확인
   HTpointer hash_ident = lookup_hash_table(identifier, hashValue);
   bool isExist = false; 	// Hash Table을 읽기 전, false로 초기화

   // hash_ident 값이 NULL이라면, 해당 identifier가 해시테이블에 저장된 적이 없다는 뜻

   // lookup_sym_table 함수를 통해 심볼테이블의 hash_ident.index 번째 인덱스에 identifier가 저장되어있는지 확인 후 bool 값 return
   // isExist가 false라면 연결된 다음 identifier를 hash_ident에 저장 후 다시 반복
   while (hash_ident != NULL && !isExist) {	// 현재 가리키는 위치에 문자가 있고 아직 identifier가 발견되지 않은 경우
      isExist = lookup_sym_table(identifier, hash_ident->index);  // 새로운 함수를 사용하여 비교
      if (!isExist) {
         hash_ident = hash_ident->next;  // linked list의 다음 identifier로 이동
      }
   }
   return hash_ident;
}

int getIdentType(const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);
   struct Ident sym_ident = sym_table[hash_ident->index];  
   dataType identType = sym_ident.ident_type;
   
   if (identType == int_scalar_variable || identType == int_array_variable)
      return 1;
   else if (identType == float_scalar_variable || identType == float_array_variable)
      return 2;
   else
      return 0;
}

int checkIdentExists(const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);
   if (hash_ident == NULL) {
      return 0;
   }

   struct Ident sym_ident = sym_table[hash_ident->index];   
   if (sym_ident.ident_type == NULL || sym_ident.ident_type == none) {
      return 0;
   }
   return 1;
}

dataType classifyDataType(int numType, dataType variableType, int is_param) {
    dataType type = none;

    if (numType == 1) { // int
        if (variableType == scalar) {
            type = is_param ? int_scalar_parameter : int_scalar_variable;
        } else {
            type = is_param ? int_array_parameter : int_array_variable;
        }
    } else if (numType == 2) { // float
        if (variableType == scalar) {
            type = is_param ? float_scalar_parameter : float_scalar_variable;
        } else {
            type = is_param ? float_array_parameter : float_array_variable;
        }
    }

    if (variableType == function) {
        type = function;
    }
    return type;
}

void updateIdentType(int numType, dataType variableType, const char *identifier) 
{
    printf("-------------------------updateIdentType-------------------------\n");
    printf("identifier: %s\n", identifier);

    // 자료형 구분
    dataType identType = classifyDataType(numType, variableType, 0);

    // sym_table에서 identifier 정보 가져오기
    HTpointer hash_ident = getIdentHash(identifier); 
    struct Ident sym_ident = sym_table[hash_ident->index];     

    // identifier의 type 정보가 NULL이거나 none이라면 identifier의 type 정보를 업데이트
    // 그 외라면 이미 선언된 identifier를 재선언하고 있는 것이므로 에러 발생
    if (sym_ident.ident_type == NULL || sym_ident.ident_type == none) {
        sym_ident.ident_type = identType;
        sym_table[hash_ident->index] = sym_ident;
        printf("sym_ident.ident_type: %s\n", dataTypesChar[sym_ident.ident_type]);
    } 
    else {
        if (sym_ident.linenumber != lineNumber) {
            ReportParserError("Already declared");
        }
    }
    printf("updateIdentType complete\n");
}

void updateReturnType(int returnType, const char *identifier)
{
   printf("-------------------------updateReturnType-------------------------\n");
   
   // sym_table에서 identifier 정보 가져오기
   HTpointer hash_ident = getIdentHash(identifier);    

   struct Ident sym_ident = sym_table[hash_ident->index];
   
   // identifier의 type이 function일 경우에만 return값 정보 업데이트
   // 그 외에 경우에는 return 값이 존재하지 않으므로 none으로 업데이트
   if (sym_ident.ident_type == function) {	
      sym_ident.return_type = returnType;	
      printf("sym_ident.ident_type: %s\n", dataTypesChar[sym_ident.ident_type]);
      sym_table[hash_ident->index] = sym_ident;
   } 
   else {
      sym_ident.return_type = none;
      sym_table[hash_ident->index] = sym_ident;
   }
   printf("updateReturnType complete\n");
   invoked_func_args = (dataType*)malloc(0);
}

void updateFunctionParameter(int type, dataType variableType, const char *function_name)
{
   printf("-------------------------updateFunctionParameter-------------------------\n");
   HTpointer hash_ident = getIdentHash(function_name);    

   // 자료형 구분
   dataType paramType = classifyDataType(type, variableType, 1);
   printf("paramtype: %s, function_name: %s\n", dataTypesChar[paramType], function_name);
   struct Ident sym_ident = sym_table[hash_ident->index];   
   
   // function_name type이 function일 경우에만 파라미터 타입 정보 업데이트
   if (sym_ident.ident_type == function) {	
      sym_ident.param_count++;
      sym_ident.param = (dataType*)realloc(sym_ident.param, (sym_ident.param_count)*sizeof(dataType));
      sym_ident.param[sym_ident.param_count-1] = paramType;
      
      sym_table[hash_ident->index] = sym_ident;
      printf("updateFunctionParameter complete\n");
   }
}

void updateInvokedFuncArgs(dataType argument_type){
   printf("-------------------------updateInvokedFuncArgs-------------------------\n");
   if(invoked_func_args == NULL){
      printf("invoked_func_args is NULL \n");
      return;
   }
   // invoked_func_args에 인수 타입 추가해주기
   invoked_func_args = (dataType*)realloc(invoked_func_args, (++invoked_func_args_cnt)*sizeof(dataType));
   invoked_func_args[invoked_func_args_cnt-1] = argument_type;
   
   printf("updateInvokedFuncArgs complete\n");
}

// 함수 정의와 일치하는 호출인지 확인하는 함수
void isIllegalInvoke(const char *function_name){
   printf("-------------------------isIllegalInvoke-------------------------\n");
   // 함수 identifier 정보 가져오기
   HTpointer hash_ident = getIdentHash(function_name);    
   struct Ident sym_ident = sym_table[hash_ident->index];

   // function_name의 type이 function이 아니거나 파라미터 개수가 맞지 않으면 에러 발생
   if (sym_ident.ident_type != function || sym_ident.param_count != invoked_func_args_cnt) {
      ReportParserError("Invalid function call.");
      free(invoked_func_args);
      return;
   }
   // 파라미터 타입 배열을 돌면서 일치하지 않는 파라미터 타입이 있다면 에러 발생
   for(int i=0; i<invoked_func_args_cnt; i++){
      if(sym_ident.param[i] != invoked_func_args[i]){
         ReportParserError("Invalid function call.");
         free(invoked_func_args);
         return;
      }
   }
   free(invoked_func_args);
}