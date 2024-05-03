#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "global.h"

extern yylex();
extern init_sym_table();
extern char *yytext;
extern lookup_sym_table(char* str);

void main()
{
	enum tnumber tn; // token number
    init_sym_table(); // 심볼테이블 초기화

	printf(" Start of Lex\n");
	printf("--------------------------------------------------------\n");
	printf("Line Number	Type		  Token		ST index\n");
	printf("--------------------------------------------------------\n");
	while  ((tn = yylex()) != TEOF) {
		switch (tn) {
			case TCONST: printf("%d		", LINE_NUMBER); printf("TCONST %16s\n", yytext); break;
			case TELSE: printf("%d		", LINE_NUMBER); printf("TELSE %17s\n", yytext); break;
			case TIF: printf("%d		", LINE_NUMBER); printf("TIF %19s\n", yytext); break;
			case TINT: printf("%d		", LINE_NUMBER); printf("TINT %18s\n", yytext); break;
			case TRETURN: printf("%d		", LINE_NUMBER); printf("TRETURN %15s\n", yytext); break;
			case TVOID: printf("%d		", LINE_NUMBER); printf("TVOID %17s\n", yytext); break;
			case TWHILE: printf("%d		", LINE_NUMBER); printf("TWHILE %16s\n", yytext); break;
			case TEQUAL: printf("%d		", LINE_NUMBER); printf("TEQUAL %16s\n", yytext); break;
			case TNOTEQU: printf("%d		", LINE_NUMBER); printf("TNOTEQU %15s\n", yytext); break;
			case TLESSE: printf("%d		", LINE_NUMBER);  printf("TLESSE %16s\n", yytext); break;
			case TGREATE: printf("%d		", LINE_NUMBER); printf("TGREATE %15s\n", yytext); break;
			case TAND: printf("%d		", LINE_NUMBER); printf("TAND %18s\n", yytext); break;
			case TOR: printf("%d		", LINE_NUMBER); printf("TOR %19s\n", yytext); break;
			case TINC: printf("%d		", LINE_NUMBER); printf("TINC %18s\n", yytext); break;
			case TDEC: printf("%d		", LINE_NUMBER); printf("TDEC %18s\n", yytext); break;
			case TADDASSIGN: printf("%d		", LINE_NUMBER); printf("TADDASSIGN %12s\n", yytext); break;
			case TSUBASSIGN: printf("%d		", LINE_NUMBER); printf("TSUBASSIGN %12s\n", yytext); break;
			case TDIVASSIGN: printf("%d		", LINE_NUMBER); printf("TDIVASSIGN %12s\n", yytext); break;
			case TMODASSIGN: printf("%d		", LINE_NUMBER); printf("TMODASSIGN %12s\n", yytext); break;
			case TIDENT: printf("%d		", LINE_NUMBER); printf("TIDENT %16s", yytext); printf("		       %d\n", lookup_sym_table(yytext)); break;
			case TNUMBER: printf("%d		", LINE_NUMBER); printf("TNUMBER %15s\n", yytext); break;
			case TINTEGER: printf("%d		", LINE_NUMBER); printf("TINTEGER %14s\n", yytext); break;
			case TREALNUM: printf("%d		", LINE_NUMBER); printf("TREALNUM%15s\n", yytext); break;
			case TPLUS: printf("%d		", LINE_NUMBER); printf("TPLUS%17s\n", yytext); break;
			case TMINUS: printf("%d		", LINE_NUMBER); printf("TMINUS%16s\n", yytext); break;
			case TFLOAT: printf("%d		", LINE_NUMBER); printf("TFLOAT%17s\n", yytext); break;
			case TDOT: printf("%d		", LINE_NUMBER); printf("TDOT%18s\n", yytext); break;
			case TCOMMA: printf("%d		", LINE_NUMBER); printf("TCOMMA%18s\n", yytext); break;
			case TASSIGN: printf("%d		", LINE_NUMBER); printf("TASSIGN%16s\n", yytext); break;
            case TSEMICOLON: printf("%d		", LINE_NUMBER); printf("TSEMICOLON%13s\n", yytext); break;
			case TNEWLINE: LINE_NUMBER++;
			case TERROR: break;			
		}
	}
}