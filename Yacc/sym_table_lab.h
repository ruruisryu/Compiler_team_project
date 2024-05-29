#pragma once

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 11
#define MAX_STR_POOL	200

void init_sym_table();
void print_sym_table();
void print_hash_table();

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;
    HTpointer next;
}HTentry;

HTpointer lookup_hash_table(char* sym, int hscode);