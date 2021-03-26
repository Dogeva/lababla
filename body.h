#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct store{
	char name[128];
	int cost;
	int year;
}store;

void write_file_bin(store *array, char *argv[],int size);
	store* read_file_bin(store *array, char *argv[], int*size);
	store* add_new_salt(store *array, int size);

void printArray(store *array,int size);
store *deleteArray(store *array, int size);

void change(store *array, int size);

void searchName(store *array, int size);
