#include <stdio.h>

int divisionMethod(char* key, int tableSize) {
	unsigned int hash_key = 0;
	int c;

	while (c = *key++) {
		hash_key += c;
	}
	return hash_key % tableSize;
}

int midsquareMethod(char* key, int tableSize) {
	int squared;
	int midPart;
	unsigned int hash_key = 0;
	int c;

	while (c = *key++) {
		hash_key += c;
	}
}

int foldingMethod(char* key, int tableSize) {
	int fold = 0;
	unsigned int hash_key = 0;
	int c;

	while (c = *key++) {
		hash_key += c;
	}

	while (hash_key > 0) {
		fold += hash_key % 10000; // 4자리씩 나누어 더함
		hash_key /= 10000;
	}
	return fold % tableSize;
}



