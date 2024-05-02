#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern yylex();
extern char *yytext;

void main()
{
	enum tnumber tn; // token number
	printf(" Start of Lex\n");
	while  ((tn = yylex()) != TEOF) {
		switch (tn) {
			case TCONST: printf("TCONST %22s\n", yytext); break;
			case TELSE: printf("TELSE %22s\n", yytext); break;
			case TIF: printf("TIF %22s\n", yytext); break;
			case TINT: printf("TINT %22s\n", yytext); break;
			case TRETURN: printf("TRETURN %22s\n", yytext); break;
			case TVOID: printf("TVOID %22s\n", yytext); break;
			case TWHILE: printf("TWHILE %22s\n", yytext); break;
			case TEQUAL: printf("TEQUAL %16s\n", yytext); break;
			case TNOTEQU: printf("TNOTEQU %16s\n", yytext); break;
			case TLESSE: printf("TLESSE %16s\n", yytext); break;
			case TGREATE: printf("TGREATE %16s\n", yytext); break;
			case TAND: printf("TAND %16s\n", yytext); break;
			case TOR: printf("TOR %16s\n", yytext); break;
			case TINC: printf("TINC %16s\n", yytext); break;
			case TDEC: printf("TDEC %16s\n", yytext); break;
			case TADDASSIGN: printf("TADDASSIGN %16s\n", yytext); break;
			case TSUBASSIGN: printf("TSUBASSIGN %16s\n", yytext); break;
			case TDIVASSIGN: printf("TDIVASSIGN %16s\n", yytext); break;
			case TMODASSIGN: printf("TMODASSIGN %16s\n", yytext); break;
			case TIDENT: printf("TIDENT %16s\n", yytext); break;
			case TNUMBER: printf("TNUMBER %16s\n", yytext); break;
			case TINTEGER: printf("TINTEGER %16s\n", yytext); break;
			case TREALNUM: printf("TREALNUM%16s\n", yytext); break;
			case TPLUS: printf("TPLUS%16s\n", yytext); break;
			case TMINUS: printf("TMINUS%16s\n", yytext); break;
			case TDOT: printf("TDOT%16s\n", yytext); break;
			case TCOMA: printf("TCOMA%16s\n", yytext); break;
			case TASSIGN: printf("TASSIGN%22s\n", yytext); break;
            case TSEMICOLON: printf("TSEMICOLON%16s\n", yytext); break;
			case TERROR: break;			
		}
	}
}