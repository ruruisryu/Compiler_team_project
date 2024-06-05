#include "tn.h"
#include "sym_table_lab.h"
#include "hash_func.h"
#include <stdio.h>
#include <stdlib.h>

// 세미콜론 없을 때 세미콜론 없는 위치의 라인넘버가 아닌 다음 라인 넘버에서 에러가 발생했다고 출력
// 괄호 쌍이 맞지 않는 경우 파서에서 에러로 인식되는 라인 넘버 출력
// identifier에서의 에러 발생시 character 단위로 에러 개수 카운트 ex. $d$ 라는 identifier에서는 에러가 2개 발생
// 함수 내에서 리턴하는 값은 변수만 가능 ex. return 3; -> (x) , return a; -> (o)

/* 추가 구현
함수 이름 선언하지 않았을 경우 오류 처리
파라미터 여러 개 받을 떄 comma(,) 없을 경우 오류 처리
할당문 오른쪽에 값이 없는 경우 오류 처리
같은 지 비교(=, !=)하는 경우 및 대소 비교 (<, >, <=, >=)하는 경우 오른쪽에 값이 없는 경우 오류 처리
*/

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

// Token 인식하여 Token 에러 및 구문 에러 출력
void main()
{
	enum tokentypes tn;
	init_sym_table();

	printf("***MiniC parsing begins\n");
	yyparse();
	printf("Parsing ends.***\n\n ");
	printf("%d error(s) detected\n", error_cnt);

	print_sym_table();
	print_hash_table();

	for (int i = 0; i < SYM_TABLE_SIZE; i++) {
		free(sym_table[i].param);
	}
}