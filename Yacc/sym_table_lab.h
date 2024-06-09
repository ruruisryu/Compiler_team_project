#pragma once

#include <stdbool.h>

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 11
#define MAX_STR_POOL	200

void init_sym_table();
void print_sym_table();
void print_hash_table();

typedef enum dataType {
	void_return,
	int_scalar_variable,
	float_scalar_variable,
	int_array_variable,
	float_array_variable,
	int_scalar_parameter,
	float_scalar_parameter,
	int_array_parameter,
	float_array_parameter,
	function,
	none,
	scalar,
	array
}dataType;

typedef struct Ident {
    int strpool_idx;
    int len;
    int linenumber;
    dataType ident_type;
	char* function_name;
    dataType return_type;
    dataType* param;
    int param_count;
}Ident;

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;
    HTpointer next;
}HTentry;

struct Ident sym_table[SYM_TABLE_SIZE];
HTpointer HT[HASH_TABLE_SIZE];
char identStr[20];

HTpointer lookup_hash_table(char* sym, int hscode);
bool lookup_sym_table(char* sym, int idx);