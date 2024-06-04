#include "tn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ERROR_MSG	100
extern void yyerror(char* s);
extern void ReportBracketError();
extern int braceCnt, parenCnt, bracketCnt;

int error_cnt = 0;
char error_message[MAX_ERROR_MSG]; //에러 메세지를 담는 변수 (메인에서 error_message를 출력한다.)

void ReportError(ERRORtypes err)
{
	error_cnt++;
	switch (err) {
	case overst:
		strcpy_s(error_message, MAX_ERROR_MSG, "overflow");
		break;
	case illid_long:
		strcpy_s(error_message, MAX_ERROR_MSG, "too long identifier");
		break;
	case illch:
		sprintf_s(error_message, MAX_ERROR_MSG, "%s illegal character", yytext);//허용되지 않은 문자가 들어올 경우 에러 발생
		break;
	case illid_digit:
		sprintf_s(error_message, MAX_ERROR_MSG, "%s start with digit", yytext);
		break;
	case real_num:
		strcpy_s(error_message, MAX_ERROR_MSG, "real number is not allowed");
		//실수가 들어올 경우 에러 발생. Floating Point 경우는 제외하였음.
	}
	printf("%d: %s\n", lineNumber, error_message); 
}

void ReportParserError(char* message) {
	error_cnt++;
	printf("(line: %d) %s\n", lineNumber - 1, message);
}

void PrintBracketError(char* bracketType, int diff) {
	diff = abs(diff);
	error_cnt += diff;
	printf("%s mismatch : %d\n", bracketType, diff);
}

void ReportBracketError() {
	if (braceCnt != 0) {
		PrintBracketError("BRACE", braceCnt);
	}
	if (parenCnt != 0) {
		PrintBracketError("PAREN", parenCnt);
	}
	if (bracketCnt != 0) {
		PrintBracketError("BRACKET", bracketCnt);
	}
}

void yyerror(char* s) {
	printf("%s\n", s);
}
