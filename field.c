#include "body.h"

store* read_file_bin (store *array, char *argv[], int *size){

FILE *f;
	if ((f=fopen(argv[1],"rb")) == NULL){
		return array;
		}
	store salt;
	*size = 0;
	while (!feof(f)){
		fread(&salt, sizeof(store), 1, f);
		*size +=1;
		}
	fseek(f, 0, SEEK_SET);
	*size -=1;
	array = (store * )malloc(*size * sizeof(store));
	for (int i = 0; i < *size; i++){
		fread(&array[i], sizeof(store), 1, f);
		}
	fclose(f);
return array;
}


void write_file_bin (store *array, char *argv[],int size){
FILE *f;

	if ((f=fopen(argv[1],"wb")) == NULL){
		return;
		}
	for (int i=0;i<size; i++){
		fwrite(&array[i], sizeof(store), 1, f);
		}

	fclose(f);
return;
}

store * add_new_salt(store *array, int size){
	if (size==0){
		array = (store*) malloc ((size + 1) * sizeof(store));
		}
	else{
		array = (store*) realloc (array, (size + 1) * sizeof(store));
	}
	printf("Название: ");
	scanf("%s", array[size].name);
	printf("Стоимость(в эдди): ");
	scanf("%d", &array[size].cost);
	printf("Век: ");
	scanf("%d", &array[size].year);
	printf("\n");
return array;
}

void printArray(store *array, int size){

	for (int i = 0; i<size; i++){
		printf("<====Номинант====>\n");
		printf("Номер товара: %d\n",i+1);
		printf("Название: %s\n", array[i].name);
		printf("Стоимость: %d\n", array[i].cost);
		printf("Век: %d\n", array[i].year);
		printf("\n");
	}
return;
}

store * deleteArray(store *array, int size){

	int number = 0;
	printf("=============\n");
	printf("Номер товара: ");
	scanf("%d",&number);


	if (number >size){
	return array;
	}
	for (int i=number-1;i<size-1;i++){
		strcpy(array[i].name, array[i+1].name);
		array[i].cost = array[i+1].cost;
		array[i].year = array[i+1].year;

	}
	array = (store*) realloc (array,(size-1)*sizeof (store));
return array;
}

void change(store *array, int size){
	int number = 0;
		printf("Номер товара: ");
		scanf("%d",&number);

		if (number >size){
	return;
	}
	printf("------------------\n");
	printf("Новое имя: ");
	scanf("%s",array[number-1].name);
	printf("Новая цена:");
	scanf("%d", &array[number-1].cost);
	printf("Новый век:");
	scanf("%d", &array[number-1].year);
	printf("\n");
	printf("=================\n");
return;
}

void searchName(store *array, int size){
	char str[128] ;
	printf("\n");
	printf("Название товара: ");
	scanf("%s",str);

	for (int i=0;i<size;i++){

	if (strcmp(array[i].name,str)==0){
	   printf("<====Товар====>\n");
	   printf("Номер товара %d\n",i+1);
	   printf("Товар %s\n", array[i].name);
	   printf("Стоимость: %d\n", array[i].cost);
	   printf("Год создания: %d\n", array[i].year);
	   printf("\n");
	  }
	}
}
