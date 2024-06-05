
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
extern void reportParserError(char* message);
HTpointer getIdentHash(const char *identifier);
dataType getIdentType(const char *identifier);
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
dataType currentArgumentType; // 현재 인수의 타입을 저장하기 위한 전역 변수
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



#define	YYFINAL		220
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 100)

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
   169,   176,   178,   180,   185,   190,   192,   193,   195,   197,
   199,   201,   203,   206,   208,   211,   215,   221,   229,   235,
   241,   247,   253,   259,   262,   264,   266,   270,   274,   276,
   278,   280,   282,   284,   286,   288,   292,   296,   298,   302,
   306,   308,   312,   316,   320,   324,   326,   330,   334,   338,
   342,   346,   350,   354,   358,   360,   364,   368,   372,   376,
   378,   382,   386,   390,   394,   398,   402,   404,   406,   408,
   410,   413,   416,   419,   422,   424,   429,   434,   437,   440,
   445,   450,   452,   453,   455,   457,   459,   461,   463,   467,
   469,   471,   475
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
     1,     0,    76,    36,     1,     0,    54,     0,    75,    36,
    94,    40,    95,    41,     0,     3,     0,    27,     0,    75,
    45,    77,    46,     0,    75,    45,    77,     1,     0,     4,
     0,     0,    68,     0,    79,     0,    80,     0,    81,     0,
    82,     0,    83,    47,     0,    47,     0,    83,     1,     0,
    83,     1,    85,     0,     7,    40,    83,    41,    78,     0,
     7,    40,    83,    41,    78,     6,    78,     0,     7,    40,
    83,     1,    78,     0,     7,     1,    83,    41,    78,     0,
    12,    40,    83,    41,    78,     0,    12,    40,    83,     1,
    78,     0,    12,     1,    83,    41,    78,     0,    10,    79,
     0,    84,     0,    86,     0,    94,    85,    84,     0,    94,
    85,     1,     0,    36,     0,    13,     0,    14,     0,    15,
     0,    16,     0,    17,     0,    87,     0,    86,    18,    87,
     0,    86,    18,     1,     0,    88,     0,    87,    19,    88,
     0,    87,    19,     1,     0,    89,     0,    88,    20,    89,
     0,    88,    21,    89,     0,    88,    20,     1,     0,    88,
    21,     1,     0,    90,     0,    89,    39,    90,     0,    89,
    38,    90,     0,    89,    22,    90,     0,    89,    23,    90,
     0,    89,    39,     1,     0,    89,    38,     1,     0,    89,
    22,     1,     0,    89,    23,     1,     0,    91,     0,    90,
    31,    91,     0,    90,    32,    91,     0,    90,    31,     1,
     0,    90,    32,     1,     0,    92,     0,    91,    33,    92,
     0,    91,    34,    92,     0,    91,    35,    92,     0,    91,
    33,     1,     0,    91,    34,     1,     0,    91,    35,     1,
     0,    93,     0,     4,     0,    29,     0,    94,     0,    32,
    93,     0,    37,    93,     0,    24,    93,     0,    25,    93,
     0,    99,     0,    94,    45,    83,    46,     0,    94,    40,
    95,    41,     0,    94,    24,     0,    94,    25,     0,    94,
    45,    83,     1,     0,    94,    40,    95,     1,     0,    96,
     0,     0,    98,     0,    75,     0,     4,     0,    29,     0,
    97,     0,    98,    42,    97,     0,     3,     0,    27,     0,
    40,    83,     1,     0,    40,    83,    41,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    56,    57,    58,    59,    60,    61,    62,    63,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    85,    87,    88,    90,
    91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
   102,   104,   105,   107,   108,   109,   110,   112,   113,   114,
   115,   116,   117,   118,   120,   122,   123,   125,   126,   127,
   128,   130,   131,   133,   134,   136,   137,   138,   139,   140,
   141,   142,   144,   145,   146,   147,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   159,   160,   161,   163,   164,
   165,   166,   167,   168,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   182,   183,   184,   185,   186,
   187,   188,   189,   190,   192,   193,   194,   195,   196,   198,
   199,   200,   201,   202,   203,   204,   206,   207,   208,   210,
   211,   212,   213,   214,   216,   217,   218,   219,   220,   221,
   222,   224,   225,   226,   227,   229,   230,   232,   233,   235,
   239,   240,   241
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
"actual_param","param_type","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    52,    52,    53,    54,    54,
    55,    55,    56,    56,    56,    56,    57,    58,    59,    59,
    60,    60,    61,    62,    62,    62,    63,    63,    63,    64,
    64,    65,    65,    66,    66,    66,    67,    67,    67,    68,
    68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
    73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
    74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
    78,    78,    79,    79,    79,    79,    80,    80,    80,    80,
    81,    81,    81,    82,    83,    84,    84,    84,    85,    85,
    85,    85,    85,    85,    86,    86,    86,    87,    87,    87,
    88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
    89,    89,    89,    89,    90,    90,    90,    90,    90,    91,
    91,    91,    91,    91,    91,    91,    92,    92,    92,    93,
    93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
    94,    95,    95,    96,    97,    97,    97,    98,    98,    99,
    99,    99,    99
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     3,     2,     2,
     3,     3,     1,     3,     3,     3,     1,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
     3,     1,     0,     1,     3,     3,     2,     2,     2,     3,
     3,     1,     0,     1,     2,     1,     1,     3,     3,     1,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
     6,     1,     1,     4,     4,     1,     0,     1,     1,     1,
     1,     1,     2,     1,     2,     3,     5,     7,     5,     5,
     5,     5,     5,     2,     1,     1,     3,     3,     1,     1,
     1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
     2,     2,     2,     2,     1,     4,     4,     2,     2,     4,
     4,     1,     0,     1,     1,     1,     1,     1,     3,     1,
     1,     3,     3
};

static const short yydefact[] = {     0,
     0,    23,    24,    26,    25,     0,     2,     4,     0,    29,
    18,    19,    21,    22,     5,    43,     7,     3,     6,    62,
    63,    60,     0,     0,    50,    52,    53,    20,   150,   128,
     0,     0,     0,     0,     0,   151,   129,     0,     0,     0,
    74,    29,    68,     0,    42,    44,    46,    47,    69,    70,
    71,    72,     0,    85,    86,    95,    98,   101,   106,   115,
   120,   127,   130,   135,    33,     9,    10,    49,    29,    48,
     0,    67,     0,     0,     0,    84,     0,     0,   133,   130,
   134,   131,   132,     0,     0,    41,    40,    45,    75,    73,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    90,    91,    92,    93,    94,   138,   139,
    89,   143,     0,     0,     0,    13,    17,     0,    32,    34,
    51,    58,    54,    55,     0,    66,     0,    59,    56,    57,
     0,     0,     0,     0,   152,   153,    10,    76,    97,    96,
   100,    99,   104,   102,   105,   103,   113,   109,   114,   110,
   112,   108,   111,   107,   118,   116,   119,   117,   124,   121,
   125,   122,   126,   123,    62,   146,    63,   147,   145,     0,
   142,   148,   144,     0,    88,    87,    12,    11,     0,    39,
    37,    38,    31,    30,     0,    29,     0,   143,    65,    64,
     0,     0,     0,     0,     0,     0,   141,   137,     0,   140,
   136,    14,    15,    16,    35,    36,     0,    80,    79,    77,
    83,    82,    81,   149,   137,     0,    78,     0,     0,     0
};

static const short yydefgoto[] = {   218,
     6,     7,     8,     9,    22,    66,   115,   116,    10,    11,
    12,    13,    14,    85,    67,   118,   119,   120,    43,    44,
    45,    46,    15,    24,    25,    26,    27,   127,    48,    49,
    50,    51,    52,    53,    54,   114,    55,    56,    57,    58,
    59,    60,    61,    62,    63,   170,   171,   172,   173,    64
};

static const short yypact[] = {   176,
    -8,-32768,-32768,-32768,-32768,   426,-32768,-32768,    -8,    71,
   127,-32768,-32768,-32768,-32768,   119,-32768,-32768,-32768,    -1,
    50,-32768,    54,     4,-32768,   -17,    61,-32768,-32768,-32768,
     9,   168,    29,   374,   374,-32768,-32768,   374,   374,   409,
-32768,    71,-32768,    19,   119,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    12,-32768,   115,    80,    81,    57,   121,    58,
-32768,-32768,   437,-32768,   127,-32768,    92,-32768,    71,-32768,
    41,   135,     7,   409,   409,-32768,   409,   409,-32768,   415,
-32768,-32768,-32768,    17,    54,-32768,-32768,-32768,   196,-32768,
   198,   215,   233,   242,   260,   274,   292,   301,   319,   333,
   351,   360,   378,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   138,   409,   392,     6,-32768,   100,    21,    95,-32768,
-32768,-32768,-32768,-32768,   418,-32768,    14,-32768,-32768,-32768,
   104,    23,   106,    24,-32768,-32768,-32768,-32768,-32768,    80,
-32768,    81,-32768,    57,-32768,    57,-32768,   121,-32768,   121,
-32768,   121,-32768,   121,-32768,    58,-32768,    58,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    25,
-32768,-32768,   108,    15,-32768,-32768,-32768,-32768,   127,-32768,
   128,-32768,-32768,-32768,   127,    71,   159,   138,-32768,-32768,
   151,   151,   151,   151,   151,   151,-32768,-32768,   138,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    26,-32768,-32768,   158,
-32768,-32768,-32768,-32768,     8,   151,-32768,   179,   182,-32768
};

static const short yypgoto[] = {-32768,
-32768,   178,-32768,-32768,  -115,-32768,-32768,  -162,    -2,-32768,
   -11,-32768,-32768,   186,   101,-32768,-32768,  -107,    20,-32768,
-32768,   162,    89,-32768,   134,  -111,  -113,-32768,  -109,   172,
-32768,-32768,-32768,   -37,   103,   125,-32768,   129,   132,    76,
   -64,    90,   147,   430,    18,    33,-32768,    27,-32768,-32768
};


#define	YYLAST		482


static const short yytable[] = {    28,
   169,   180,    84,   182,    68,   181,   177,   128,   -61,    74,
   129,   187,    89,    42,   189,   200,   202,   135,    71,    86,
    17,   183,   204,   192,   195,   197,   197,    72,    19,    77,
   148,   150,   152,   154,    16,   130,   131,   132,   -27,   133,
   134,   122,    42,    29,   123,    69,   178,   179,    75,   -61,
    70,    80,    80,   117,   -61,    80,    80,   136,    90,   190,
   201,   184,    87,   193,   196,   198,   215,    36,    78,   124,
   180,   203,   182,    20,   181,   174,   169,   205,    95,    96,
    40,   208,   209,   210,   211,   212,   213,   169,   125,   -28,
   101,   102,   103,    65,    97,    98,    73,    21,    92,     2,
    93,    94,    20,     3,    47,     4,   217,   186,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    29,    30,     2,     5,    31,    21,     3,    32,     4,
    33,     2,    91,    47,    -8,     3,   185,     4,   126,   -29,
   165,   166,    34,    35,   191,    36,   194,    37,     5,   199,
    38,    99,   100,    29,    30,    39,     5,    31,    40,   206,
    32,    16,    33,   216,   167,    41,   168,   117,   144,   146,
    29,    30,    72,   117,    34,    35,     1,    36,   219,    37,
     2,   220,    38,    18,     3,   137,     4,    39,   156,   158,
    40,    34,    35,    16,    36,    23,    37,    41,   139,    38,
    29,    30,   121,    76,    39,     5,    88,    40,   104,   105,
   106,   107,   108,   138,    41,   141,   176,    29,    30,   140,
   207,    34,    35,   142,    36,   214,    37,     0,     0,    38,
     0,   111,     0,   143,    39,    29,    30,    40,    34,    35,
     0,    36,   145,    37,    29,    30,    38,   160,   162,   164,
     0,    39,     0,     0,    40,     0,    34,    35,     0,    36,
   147,    37,    29,    30,    38,    34,    35,     0,    36,    39,
    37,     0,    40,    38,   149,     0,    29,    30,    39,     0,
     0,    40,     0,    34,    35,     0,    36,     0,    37,     0,
     0,    38,   151,     0,    29,    30,    39,    34,    35,    40,
    36,   153,    37,    29,    30,    38,     0,     0,     0,     0,
    39,     0,     0,    40,     0,    34,    35,     0,    36,   155,
    37,    29,    30,    38,    34,    35,     0,    36,    39,    37,
     0,    40,    38,   157,     0,    29,    30,    39,     0,     0,
    40,     0,    34,    35,     0,    36,     0,    37,     0,     0,
    38,   159,     0,    29,    30,    39,    34,    35,    40,    36,
   161,    37,    29,    30,    38,     0,     0,     0,     0,    39,
     0,     0,    40,     0,    34,    35,    29,    36,   163,    37,
    29,    30,    38,    34,    35,     0,    36,    39,    37,     0,
    40,    38,   175,     0,    29,    30,    39,    34,    35,    40,
    36,    34,    35,     0,    36,    38,    37,     0,     0,    38,
    39,    29,    30,    40,    39,    34,    35,    40,    36,     0,
    37,     0,     0,    38,     0,    -1,     1,     0,    39,     0,
     2,    40,    34,    35,     3,    36,     4,    37,   109,   110,
    38,   109,   110,     0,     0,    39,     0,     0,    40,   104,
   105,   106,   107,   108,   112,     5,     0,   188,     0,   113,
   109,   110,   113,    79,    81,     0,     0,    82,    83,     0,
     0,     0,   111,     0,     0,     0,   112,     0,     0,     0,
     0,   113
};

static const short yycheck[] = {    11,
   112,   117,    40,   117,     1,   117,     1,     1,     1,     1,
     4,   119,     1,    16,     1,     1,   179,     1,    36,     1,
     1,     1,   185,     1,     1,     1,     1,    45,     9,     1,
    95,    96,    97,    98,    43,    29,    74,    75,    40,    77,
    78,     1,    45,     3,     4,    42,    41,    42,    40,    42,
    47,    34,    35,    65,    47,    38,    39,    41,    47,    46,
    46,    41,    44,    41,    41,    41,    41,    27,    40,    29,
   186,   179,   186,     3,   186,   113,   188,   185,    22,    23,
    40,   191,   192,   193,   194,   195,   196,   199,    71,    40,
    33,    34,    35,    40,    38,    39,    36,    27,    19,     5,
    20,    21,     3,     9,    16,    11,   216,   119,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,     3,     4,     5,    30,     7,    27,     9,    10,    11,
    12,     5,    18,    45,    43,     9,    42,    11,     4,    40,
     3,     4,    24,    25,    41,    27,    41,    29,    30,    42,
    32,    31,    32,     3,     4,    37,    30,     7,    40,     1,
    10,    43,    12,     6,    27,    47,    29,   179,    93,    94,
     3,     4,    45,   185,    24,    25,     1,    27,     0,    29,
     5,     0,    32,     6,     9,    85,    11,    37,    99,   100,
    40,    24,    25,    43,    27,    10,    29,    47,     1,    32,
     3,     4,    69,    32,    37,    30,    45,    40,    13,    14,
    15,    16,    17,    89,    47,     1,   114,     3,     4,    91,
   188,    24,    25,    92,    27,   199,    29,    -1,    -1,    32,
    -1,    36,    -1,     1,    37,     3,     4,    40,    24,    25,
    -1,    27,     1,    29,     3,     4,    32,   101,   102,   103,
    -1,    37,    -1,    -1,    40,    -1,    24,    25,    -1,    27,
     1,    29,     3,     4,    32,    24,    25,    -1,    27,    37,
    29,    -1,    40,    32,     1,    -1,     3,     4,    37,    -1,
    -1,    40,    -1,    24,    25,    -1,    27,    -1,    29,    -1,
    -1,    32,     1,    -1,     3,     4,    37,    24,    25,    40,
    27,     1,    29,     3,     4,    32,    -1,    -1,    -1,    -1,
    37,    -1,    -1,    40,    -1,    24,    25,    -1,    27,     1,
    29,     3,     4,    32,    24,    25,    -1,    27,    37,    29,
    -1,    40,    32,     1,    -1,     3,     4,    37,    -1,    -1,
    40,    -1,    24,    25,    -1,    27,    -1,    29,    -1,    -1,
    32,     1,    -1,     3,     4,    37,    24,    25,    40,    27,
     1,    29,     3,     4,    32,    -1,    -1,    -1,    -1,    37,
    -1,    -1,    40,    -1,    24,    25,     3,    27,     1,    29,
     3,     4,    32,    24,    25,    -1,    27,    37,    29,    -1,
    40,    32,     1,    -1,     3,     4,    37,    24,    25,    40,
    27,    24,    25,    -1,    27,    32,    29,    -1,    -1,    32,
    37,     3,     4,    40,    37,    24,    25,    40,    27,    -1,
    29,    -1,    -1,    32,    -1,     0,     1,    -1,    37,    -1,
     5,    40,    24,    25,     9,    27,    11,    29,    24,    25,
    32,    24,    25,    -1,    -1,    37,    -1,    -1,    40,    13,
    14,    15,    16,    17,    40,    30,    -1,    40,    -1,    45,
    24,    25,    45,    34,    35,    -1,    -1,    38,    39,    -1,
    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
    -1,    45
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

case 7:
#line 62 "parser.y"
{ yyerrok; reportParserError("function_def"); ;
    break;}
case 12:
#line 69 "parser.y"
{ yyerrok; reportParserError("type_only_param"); ;
    break;}
case 17:
#line 74 "parser.y"
{ updateFunctionParameter(numType, scalar, currentFunctionName); ;
    break;}
case 24:
#line 81 "parser.y"
{ numType = 1; ;
    break;}
case 25:
#line 82 "parser.y"
{ numType = 2; ;
    break;}
case 26:
#line 83 "parser.y"
{ numType = 0; ;
    break;}
case 27:
#line 85 "parser.y"
{ updateIdentType(numType, function, 0, identStr); updateReturnType(numType, identStr); 
                                                                                                strncpy(currentFunctionName, identStr, 1000); ;
    break;}
case 29:
#line 88 "parser.y"
{ yyerrok; reportParserError("NO_FUNC_NAME");
    break;}
case 31:
#line 91 "parser.y"
{ yyerrok; reportParserError("formal_param"); ;
    break;}
case 36:
#line 96 "parser.y"
{ yyerrok; reportParserError("NO_COMMA"); ;
    break;}
case 37:
#line 98 "parser.y"
{ updateIdentType(numType, scalar, 1, identStr); updateFunctionParameter(numType, scalar, currentFunctionName); ;
    break;}
case 38:
#line 99 "parser.y"
{ updateIdentType(numType, array, 1, identStr); updateFunctionParameter(numType, array, currentFunctionName); ;
    break;}
case 41:
#line 102 "parser.y"
{ yyerrok; reportParserError("compound_st MISSING RBRACE"); ;
    break;}
case 49:
#line 113 "parser.y"
{ yyerrok; reportParserError("declaration MISSING SEMI"); ;
    break;}
case 52:
#line 116 "parser.y"
{ updateIdentType(numType, scalar, 0, identStr); ;
    break;}
case 53:
#line 117 "parser.y"
{ updateIdentType(numType, array, identStr); ;
    break;}
case 54:
#line 118 "parser.y"
{ updateIdentType(numType, scalar, 0, identStr);
                                                                                                if (getIdentType(identStr) != 1) reportParserError("type mismatch in initialization"); ;
    break;}
case 55:
#line 120 "parser.y"
{ updateIdentType(numType, scalar, 0, identStr); 
                                                                                                if (getIdentType(identStr) != 2) reportParserError("type mismatch in initialization"); ;
    break;}
case 56:
#line 122 "parser.y"
{ updateIdentType(numType, array, 0, identStr);;
    break;}
case 57:
#line 123 "parser.y"
{ updateIdentType(numType, array, 0, identStr); 
                                                                                                if (getIdentType(identStr) != 2) reportParserError("type mismatch in initialization"); ;
    break;}
case 58:
#line 125 "parser.y"
{ yyerrok; reportParserError("init_declarator"); ;
    break;}
case 59:
#line 126 "parser.y"
{ yyerrok; reportParserError("init_declarator"); ;
    break;}
case 65:
#line 134 "parser.y"
{ yyerrok; reportParserError("declarator MISSING BRAKET"); ;
    break;}
case 75:
#line 146 "parser.y"
{ yyerrok; reportParserError("expression_st MISSING SEMI"); ;
    break;}
case 76:
#line 147 "parser.y"
{ yyerrok; reportParserError("cannot assign to invalid lvalue");;
    break;}
case 79:
#line 151 "parser.y"
{ yyerrok; reportParserError("if_st MISSING PAREN"); ;
    break;}
case 80:
#line 152 "parser.y"
{ yyerrok; reportParserError("if_st MISSING PAREN"); ;
    break;}
case 82:
#line 154 "parser.y"
{ yyerrok; reportParserError("while_st MISSING PAREN"); ;
    break;}
case 83:
#line 155 "parser.y"
{ yyerrok; reportParserError("while_st MISSING PAREN"); ;
    break;}
case 88:
#line 161 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_ASSIGNMENT_EXP"); ;
    break;}
case 97:
#line 172 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_LOGICAL_OR_EXP");;
    break;}
case 100:
#line 175 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_LOGICAL_AND_EXP");;
    break;}
case 104:
#line 179 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TEQUAL_EXP");;
    break;}
case 105:
#line 180 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TNOTEQU_EXP");;
    break;}
case 111:
#line 187 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TGREAT_EXP");;
    break;}
case 112:
#line 188 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TELSE_EXP");;
    break;}
case 113:
#line 189 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TGREATE_EXP");;
    break;}
case 114:
#line 190 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TLESSE_EXP");;
    break;}
case 118:
#line 195 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TADD_EXP");;
    break;}
case 119:
#line 196 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TSUB_EXP");;
    break;}
case 124:
#line 202 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TMUL_EXP"); ;
    break;}
case 125:
#line 203 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TDIV_EXP"); ;
    break;}
case 126:
#line 204 "parser.y"
{ yyerrok; reportParserError("NO_RIGHT_TMOD_EXP"); ;
    break;}
case 128:
#line 207 "parser.y"
{ if (getIdentType(identStr) != int_scalar_variable) reportParserError("type mismatch in assignment"); ;
    break;}
case 129:
#line 208 "parser.y"
{ if (getIdentType(identStr) != float_scalar_variable) reportParserError("type mismatch in assignment"); ;
    break;}
case 137:
#line 218 "parser.y"
{ isIllegalInvoke(currentFunctionName); ;
    break;}
case 140:
#line 221 "parser.y"
{ yyerrok; reportParserError("postfix_exp"); ;
    break;}
case 141:
#line 222 "parser.y"
{ yyerrok; reportParserError("postfix_exp"); ;
    break;}
case 145:
#line 227 "parser.y"
{ if (!checkIdentExists(identStr)) reportParserError("identifier does not exists");
                                                                                                updateInvokedFuncArgs(getParamType(identStr));;
    break;}
case 146:
#line 229 "parser.y"
{ updateInvokedFuncArgs(int_scalar_parameter);;
    break;}
case 147:
#line 230 "parser.y"
{ updateInvokedFuncArgs(float_scalar_parameter);;
    break;}
case 150:
#line 235 "parser.y"
{ strcpy_s(currentFunctionName, sizeof(currentFunctionName), identStr);
                                                                                                dataType* invoked_func_args = (dataType*)malloc(0);
                                                                                                invoked_func_args_cnt = 0;
                                                                                                if (!checkIdentExists(identStr)) reportParserError("identifier does not exists"); ;
    break;}
case 152:
#line 240 "parser.y"
{ yyerrok; reportParserError("primary_exp"); ;
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
#line 242 "parser.y"
  
// identifier의 해시테이블 포인터 값을 반환하는 함수
HTpointer getIdentHash(const char *identifier)
{
   // identifier에 해당하는 HTpointer 가져오기
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
   return hash_ident;
}

// identifier의 타입을 반환하는 함수
dataType getIdentType(const char *identifier)
{
   // sym_table에서 identifier 정보 가져오기
   HTpointer hash_ident = getIdentHash(identifier);
   struct Ident sym_ident = sym_table[hash_ident->index];  

   return sym_ident.ident_type;
}

// parameter의 타입을 반환하는 함수
dataType getParamType(const char *identifier)
{
   // sym_table에서 identifier 정보 가져오기
   HTpointer hash_ident = getIdentHash(identifier);
   struct Ident sym_ident = sym_table[hash_ident->index];

   if(sym_ident.ident_type == int_scalar_variable){
      return int_scalar_parameter;
   }
   else if(sym_ident.ident_type == float_scalar_variable){
      return float_scalar_parameter;
   }
   return sym_ident.ident_type;
}

// identifier가 심볼 테이블에 저장되어 있는지 확인하는 함수
int checkIdentExists(const char *identifier)
{
   // sym_table에서 identifier 정보 가져오기
   HTpointer hash_ident = getIdentHash(identifier);
   struct Ident sym_ident = sym_table[hash_ident->index];  
   // ident_type이 NULL이거나 none이라면 선언된 identifier가 아니므로 0 반환 
   if (sym_ident.ident_type == NULL || sym_ident.ident_type == none) {
      return 0;
   }
   return 1;
}

// identifier의 구체적인 타입 값을 구하는 함수
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

// identifier의 타입을 저장하는 함수
void updateIdentType(int numType, dataType variableType, int is_param, const char *identifier) 
{
    // 자료형 구분
    dataType identType = classifyDataType(numType, variableType, is_param);

    // sym_table에서 identifier 정보 가져오기
    HTpointer hash_ident = getIdentHash(identifier); 
    struct Ident sym_ident = sym_table[hash_ident->index];     

    // identifier의 type 정보가 NULL이거나 none이라면 identifier의 type 정보를 업데이트
    // 그 외라면 이미 선언된 identifier를 재선언하고 있는 것이므로 에러 발생
    if (sym_ident.ident_type == NULL || sym_ident.ident_type == none) {
        sym_ident.ident_type = identType;
        sym_table[hash_ident->index] = sym_ident;
    } 
    else {
        if (sym_ident.linenumber != lineNumber) {
            reportParserError("identifier is already declared");
        }
    }
}

// 함수의 리턴 타입을 업데이트하는 함수
void updateReturnType(int returnType, const char *identifier)
{
   // sym_table에서 identifier 정보 가져오기
   HTpointer hash_ident = getIdentHash(identifier);    
   struct Ident sym_ident = sym_table[hash_ident->index];
      
   // identifier의 type 정보가 function일 경우에만 return값 정보 업데이트
   if (sym_ident.ident_type == function) {	
      sym_ident.return_type = returnType;	
      sym_table[hash_ident->index] = sym_ident;
   } 
   else {
      sym_ident.return_type = none;
      sym_table[hash_ident->index] = sym_ident;
   }
}

// 함수의 파라미터 정보를 업데이트하는 함수
void updateFunctionParameter(int type, dataType variableType, const char *function_name)
{
   HTpointer hash_ident = getIdentHash(function_name);    

   // 자료형 구분
   dataType paramType = classifyDataType(type, variableType, 1);
   struct Ident sym_ident = sym_table[hash_ident->index];   
   
   // function_name type이 function일 경우에만 파라미터 타입 정보 업데이트
   if (sym_ident.ident_type == function) {	
      sym_ident.param_count++;
      sym_ident.param = (dataType*)realloc(sym_ident.param, (sym_ident.param_count)*sizeof(dataType));
      sym_ident.param[sym_ident.param_count-1] = paramType;
      
      sym_table[hash_ident->index] = sym_ident;
   }
}

// 함수 호출 시 parameter의 타입을 저장하는 함수
void updateInvokedFuncArgs(dataType argument_type){
   // invoked_func_args가 NULL이라면 malloc로 메모리 할당
   if(invoked_func_args == NULL){
      invoked_func_args = (dataType*)malloc(sizeof(dataType));
      if (invoked_func_args == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          exit(EXIT_FAILURE);
      }
      invoked_func_args_cnt = 1;
   } else {
      invoked_func_args_cnt++;
      dataType* temp = (dataType*)realloc(invoked_func_args, invoked_func_args_cnt * sizeof(dataType));
      if (temp == NULL) {
          fprintf(stderr, "Memory reallocation failed\n");
          free(invoked_func_args);  // 기존 메모리를 해제하여 메모리 누수를 방지
          exit(EXIT_FAILURE);
      }
      invoked_func_args = temp;
   }

   // invoked_func_args 마지막 인덱스에 armument_type 업데이트해주기 
   invoked_func_args[invoked_func_args_cnt-1] = argument_type;
}

// 함수 정의와 일치하는 호출인지 확인하는 함수
void isIllegalInvoke(const char *function_name){
   HTpointer hash_ident = getIdentHash(function_name);    
   struct Ident sym_ident = sym_table[hash_ident->index];

   // function_name의 type 정보가 function이 아니거나 파라미터 개수가 맞지 않으면 에러 발생
   if (sym_ident.ident_type != function || sym_ident.param_count != invoked_func_args_cnt) {
      reportParserError("invalid function call");
      return;
   }

   // 파라미터 타입 배열을 돌면서 일치하지 않는 파라미터 타입이 있다면 에러 발생
   for(int i=0; i<invoked_func_args_cnt; i++){
      if (i >= sym_ident.param_count) {
         printf("Index out of bounds: sym_ident.param[%d] (max %d)\n", i, sym_ident.param_count);
         return;
      }

      if(sym_ident.param[i] != invoked_func_args[i]){
         reportParserError("Invalid function call.");
         return;
      }
   }
}