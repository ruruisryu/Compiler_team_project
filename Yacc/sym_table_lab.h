#pragma once

#include <stdbool.h>

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 11
#define MAX_STR_POOL	200
#define MAX_PARAMS_LENGTH 100
#define MAX_RETYPE_LENGTH 100

void init_sym_table();
void print_sym_table();
void print_hash_table();

typedef struct Ident {
    int strpool_idx;
    int len;
    int linenumber;
    int ident_type;
    int return_type;
    int* param;
    int param_count;
};

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