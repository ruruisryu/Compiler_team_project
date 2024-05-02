#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtable.h"
#include "HashFunc.h"
#include "tn.h"

// 팀 10 (유서현, 김서현, 이서연)

char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
int sym_table[SYM_TABLE_SIZE][3];  // str_pool index / symbol lenght / type
int hash_value = -1;

int index_start = 0;	// str_pool 인덱스
int symbol_count = 0;	// sym_table 인덱스

typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	HTpointer next;
} HTentry;

HTpointer HT[HASH_TABLE_SIZE];

// 해시테이블에서 찾고자 하는 값 반환
HTpointer lookup_hash_table(int id_index, int hscode) {
	HTpointer entry = HT[hscode];

	while (entry != NULL) {
		// HT에서 찾고자 하는 값 비교
		if (strcmp(str_pool + sym_table[entry->index][0], str_pool + (id_index)) == 0) {
			return entry; // 찾은 항목 반환
		}
		entry = entry->next;
	}
	return NULL; // 항목을 찾지 못한 경우 
}

// 해시테이블에 추가
void add_hash_table(int id_index, int hscode) {
	// 새 항목 생성 및 초기화
	HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
	if (newEntry == NULL) {
		printf("메모리 할당 실패\n");
		exit(1);
	}
	newEntry->index = id_index;
	newEntry->next = NULL;

	// HT에 추가
	if (HT[hscode] == NULL) {
		HT[hscode] = newEntry;
	}
	else {
		newEntry->next = HT[hscode];
		HT[hscode] = newEntry;
	}
}

// 해시테이블 출력
void print_hash_table() {
	printf("\nHash Table\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];

		if (curr == NULL) { // 해시 버킷이 비어 있다면 출력하지 않음
			continue;
		}

		printf("[%d]: ", i);
		while (curr->next != NULL) {
			printf("%d -> ", curr->index);
			curr = curr->next;
		}
		printf("%d\n", curr->index);
	}
}

// 심볼 테이블 초기화
void init_sym_table() {
	for (int i = 0; i < SYM_TABLE_SIZE; i++) {
		sym_table[i][0] = -1;
		sym_table[i][1] = -1;
	}
}

// 심볼테이블에서 찾고자 하는 값 반환
int lookup_sym_table(char *str) {
	for (int i = 0; i < SYM_TABLE_SIZE; i++) {
		if (sym_table[i][0] != -1) {
			if (!strcmp(str_pool + sym_table[i][0], str)) {
				return i;
			}
		}
	}
	return -1;
}

// 심볼테이블 출력
void print_sym_table() {
	printf("\nSymbol Table\n");
	printf("index\tLength\tSymbol\n");
	for (int i = 0; i < SYM_TABLE_SIZE; i++) {
		if (sym_table[i][0] != -1) {
			printf("%d\t%d\t%s\n", sym_table[i][0], sym_table[i][1], str_pool + sym_table[i][0]);
		}
	}
}

int validate_identifier(const char* str) {
	// 문자열이 심볼 테이블에 이미 있는지 확인
	int str_in_table = lookup_sym_table(str);
	if (str_in_table != -1) {
		printf("Error - already exists, symbol table info: index {%d} length {%d} (%s)\n", sym_table[str_in_table][0], sym_table[str_in_table][1], str); // 버퍼 내용 화면에 출력
		return 0;
	}
	if (isdigit(str[0])) {
		printf("Error - start with digit (%s)\n", str);
		return 0;
	}
	if (strlen(str) > MAX_IDENTIFIER_SIZE) {
		printf("Error - identifier is too long (%s)\n", str);
		return 0;
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isalnum((unsigned char)str[i]) && str[i] != '_' && !strchr(separators, str[i])) {
			printf("Error - invalid character (%s)\n", str);
			return 0;
		}
	}
	return 1;
}

// 식별자가 유효한지 체크 후, 유효하다면 식별자를 심볼 테이블과 해시테이블에 기록
int process_symbol(char* identifier, enum tnumber tn) {
	if (!validate_identifier(identifier)) { // 식별자가 유효한지 체크
		return 0;
	}

	// 심볼 테이블 처리
	sym_table[symbol_count][0] = index_start; // 현재 처리 중인 문자열의 시작 인덱스를 심볼 테이블에 기록
	sym_table[symbol_count][1] = (int)strlen(identifier);
	sym_table[symbol_count++][2] = tn;

	// string pool 처리 + index_start 업데이트
	for (int i = 0; i < (int)strlen(identifier); i++) {
		str_pool[index_start++] = identifier[i];
	}
	str_pool[index_start++] = '\0'; // 문자열 종료 표시

	// 해시 테이블 처리
	int hash_value = divisionMethod(identifier, HASH_TABLE_SIZE);

	HTpointer htp = lookup_hash_table(index_start, hash_value);
	if (htp == NULL) {
		add_hash_table(index_start, hash_value);
		printf("%s (Hash: %d)\n", identifier, hash_value); // 버퍼 내용 화면에 출력
	}

	return 1;
}

int check_overflow() {
	if (index_start >= STR_POOL_SIZE) {
		return true;
	}
	return false;
}