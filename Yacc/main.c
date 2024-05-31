#include "tn.h"
#include "sym_table_lab.h"
#include "hash_func.h"
#include <stdio.h>
#include <stdlib.h>

extern int error_cnt;

//lineNumber 관련 변수
int lineNumber = 1;//코드 lineNumber를 담는 변수
int startLineNumber = 0;//주석 처리시 주석 시작 lineNumber를 담는 변수

//error 관련 변수
ERRORtypes err = noerror;//에러 타입을 담는 변수

char str_tokentypes[][16] = {
			"TIDENT",
	"TNUMBER",
	"TCONST",
	"TELSE",
	"TIF",
	"TEIF",
	"TINT",
	"TRETURN",
	"TVOID",
	"TWHILE",
	"TADDASSIGN",
	"TSUBASSIGN",
	"TMULASSIGN",
	"TDIVASSIGN",
	"TMODASSIGN",
	"TOR",
	"TAND",
	"TEQUAL",
	"TNOTEQU",
	"TGREATE",
	"TLESSE",
	"TINC",
	"TDEC",
	"TEOF",
	"TERROR",
	"TCOMMENT",
	"TFNUMBER",
	"TFLOAT",
	"TADD",
	"TSUB",
	"TMUL",
	"TDIV",
	"TMOD",
	"TASSIGN",
	"TNOT",
	"TLESS",
	"TGREAT",
	"TLPAREN",
	"TRPAREN",
	"TCOMMA",
	"TLBRACE",
	"TRBRACE",
	"TLBRACKET",
	"TRBRACKET",
	"TSEMI",
	"LOWER_THAN_ELSE",
};

void PrintHeading()
{
	printf("\n\n");
	printf("-----------        ------------         ------------         ------------ \n");
	printf("Line Number         Token type              Token              ST-index   \n");
	printf("-----------        ------------         ------------         ------------ \n");
	printf("\n");
}

void printToken(enum tokentypes tn)
{
	switch (tn) {
	case TCOMMENT: break;
	case TIDENT:	
	{
		HTpointer htp = lookup_hash_table(yytext, divisionMethod(yytext, HASH_TABLE_SIZE));
		int ST_INDEX = htp != NULL ? htp->index : -1;
		printf("%-20d %-20s %-20s %-20d\n", lineNumber, "TIDENT", yytext, ST_INDEX);

		break;
	}
	case TERROR:	printf("%-20s %-20s\n", "**Error**", error_message);		break;
	default:		printf("%-20d %-20s %-20s\n", lineNumber, str_tokentypes[tn - 258], yytext);  break;
	}
}

//Token 인식하여 Token 및 에러 출력
void main()
{
	printf("start of parser\n");
	enum tokentypes tn;

	init_sym_table();

	PrintHeading();

	//while ((tn = yylex()) != 0) {
	//	printToken(tn);
	//}
	printf("***MiniC parsing begins\n");
	yyparse();
	printf("Parsing ends.***\n\n ");
	printf("%d error(s) detected\n", error_cnt);

	print_sym_table();
	print_hash_table();
	printf("end of parser\n");
}