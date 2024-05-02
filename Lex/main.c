#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern yylex();
extern init_sym_table();
extern char *yytext;

void main()
{
	enum tnumber tn; // token number
    init_sym_table();
	printf(" Start of Lex\n");
	while  ((tn = yylex()) != TEOF) {
		switch (tn) {
			case TCONST: printf("TCONST %16s\n", yytext); break;
			case TELSE: printf("TELSE %17s\n", yytext); break;
			case TIF: printf("TIF %19s\n", yytext); break;
			case TINT: printf("TINT %18s\n", yytext); break;
			case TRETURN: printf("TRETURN %15s\n", yytext); break;
			case TVOID: printf("TVOID %17s\n", yytext); break;
			case TWHILE: printf("TWHILE %16s\n", yytext); break;
			case TEQUAL: printf("TEQUAL %16s\n", yytext); break;
			case TNOTEQU: printf("TNOTEQU %15s\n", yytext); break;
			case TLESSE: printf("TLESSE %16s\n", yytext); break;
			case TGREATE: printf("TGREATE %15s\n", yytext); break;
			case TAND: printf("TAND %18s\n", yytext); break;
			case TOR: printf("TOR %19s\n", yytext); break;
			case TINC: printf("TINC %18s\n", yytext); break;
			case TDEC: printf("TDEC %18s\n", yytext); break;
			case TADDASSIGN: printf("TADDASSIGN %12s\n", yytext); break;
			case TSUBASSIGN: printf("TSUBASSIGN %12s\n", yytext); break;
			case TDIVASSIGN: printf("TDIVASSIGN %12s\n", yytext); break;
			case TMODASSIGN: printf("TMODASSIGN %12s\n", yytext); break;
			case TIDENT: printf("TIDENT %16s\n", yytext); break;
			case TNUMBER: printf("TNUMBER %15s\n", yytext); break;
			case TINTEGER: printf("TINTEGER %14s\n", yytext); break;
			case TREALNUM: printf("TREALNUM%14s\n", yytext); break;
			case TPLUS: printf("TPLUS%17s\n", yytext); break;
			case TMINUS: printf("TMINUS%16s\n", yytext); break;
			case TFLOAT: printf("TFLOAT%16s\n", yytext); break;
			case TDOT: printf("TDOT%18s\n", yytext); break;
			case TCOMA: printf("TCOMA%17s\n", yytext); break;
			case TASSIGN: printf("TASSIGN%15s\n", yytext); break;
            case TSEMICOLON: printf("TSEMICOLON%12s\n", yytext); break;
			case TERROR: break;			
		}
	}
}