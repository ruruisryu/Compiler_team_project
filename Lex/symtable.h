#pragma once
#define SYM_TABLE_SIZE 20
#define STR_POOL_SIZE 20
#define HASH_TABLE_SIZE 13
#define MAX_IDENTIFIER_SIZE 15

int validate_identifier(const char* str);
int process_symbol(char* identifier, enum tnumber tn);
int check_overflow();
