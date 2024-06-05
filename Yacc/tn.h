#pragma once
#ifndef YYSTYPE
#define YYSTYPE int
#endif
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

extern YYSTYPE yylval;

enum errorTypes { noerror, illid_digit, illid_long, illch, real_num, overst };
typedef enum errorTypes ERRORtypes;

extern int lineNumber;
extern int startLineNumber;//�ּ�ó���� ���� lineNumber�� �����ϴ� ����
extern char error_message[];

//lex ���� ����
extern char* yytext;
extern int yyleng;
extern int yylex();

//�ܺ� �Լ� ����
extern void SymbolTable(char*, int);
extern void ReportError(ERRORtypes err);
