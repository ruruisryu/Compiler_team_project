#include <stdio.h>
#include "STMain.h"
#include "HashFunc.h"

char separators[] = " ,;\t\n\r\n";
char str_pool[100];
int sym_table[SYM_TABLE_SIZE][2];
int hash_value = -1;

typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	HTpointer next;
} HTentry;

HTpointer HT[HASH_TABLE_SIZE];

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

print_hash_table() {
	int i;
	printf("\nHash Table\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];
		printf("[%d]: ", i);
		while (curr != NULL) {
			printf("%d -> ", curr->index);
			curr = curr->next;
		}
		printf("NULL");
		printf("\n");
	}
}

void init_sym_table() {
	int i;
	for (i = 0; i < SYM_TABLE_SIZE; i++) {
		sym_table[i][0] = -1;
		sym_table[i][1] = -1;
	}
}

void print_sym_table() {
	int i;
	printf("\nSymbol Table\n");
	printf("index\tLength\tSymbol\n");
	for (i = 0; i < SYM_TABLE_SIZE; i++) {
		if (sym_table[i][0] != -1) {
			printf("%d\t%d\t%s\n", sym_table[i][0], sym_table[i][1], str_pool + sym_table[i][0]);
		}
	}
}


int main() {
	FILE* fp;
	int result;
	int c; // 읽은 문자를 저장할 변수
	int index_start = 0;
	int index_next = 0;
	int index = 0; // 심볼테이블용 변수
	int hash_value = -1;

	init_sym_table();

	result = fopen_s(&fp, "example.txt", "r"); // 파일을 읽기 모드로 열기
	if (result != 0) {
		printf("파일 열기 실패(%d)\n", result);
		return -1;
	}

	while ((c = fgetc(fp)) != EOF) { // 파일 끝까지 문자 읽기
		// 구분자를 만나거나 버퍼 크기 제한에 도달했을 때
		if (strchr(separators, c) != NULL || index_next >= sizeof(str_pool) - 1) {
			if (index_start < index_next) { // 버퍼에 내용이 있을 때만 출력
				str_pool[index_next] = '\0'; // 문자열 종료

				// 문자열의 시작 문자가 숫자인지 체크
				if (str_pool[index_start] >= '0' && str_pool[index_start] <= '9') {
					printf("Error - start with digit (%s)\n", str_pool + index_start); // 에러 출력
					index_next = index_start; // 버퍼 인덱스 초기화
				}
				else {
					sym_table[index][0] = index_start; // 현재 처리 중인 문자열의 시작 인덱스를 심볼 테이블에 기록
					sym_table[index++][1] = (int)strlen(str_pool + index_start); // str_pool의 index_start 위치부터 문자열의 끝까지 길이 계산

					hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);

					HTpointer htp = lookup_hash_table(index_start, hash_value);
					if (htp == NULL) {
						add_hash_table(index_start, hash_value);
						printf("%s (Hash: %d)\n", str_pool + index_start, hash_value); // 버퍼 내용 화면에 출력
					}
					else {
						printf("%s (Already exists, Hash: %d)\n", str_pool + index_start, hash_value); // 버퍼 내용 화면에 출력
					}
					index_start = ++index_next; // 다음 문자열의 시작 인덱스 설정
				}
			}
			if (strchr(separators, c) == NULL) {
				str_pool[index_next++] = (char)c; // 구분자가 아닌 문자를 버퍼에 저장
			}
			continue; // 다음 문자로 이동
		}
		str_pool[index_next++] = (char)c; // 버퍼에 문자 저장
	}

	if (index_start < index_next) { // 마지막 문자열 출력
		str_pool[index_next] = "\0"; // 문자열 종료
		sym_table[index][0] = index_start;
		sym_table[index++][1] = strlen(str_pool + index_start);

		hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);

		HTpointer htp = lookup_hash_table(index_start, hash_value);
		if (htp == NULL) {
			add_hash_table(index_start, hash_value);
			printf("%s (Hash: %d)\n", str_pool + sym_table[index - 1][0], hash_value); // 버퍼 내용 화면에 출력
		}
		else {
			printf("%s (Already exists, Hash: %d)\n", str_pool + sym_table[index - 1][0], hash_value); // 버퍼 내용 화면에 출력
		}
	}

	print_sym_table();
	print_hash_table();

	fclose(fp); // 파일 닫기
	return 0;
}