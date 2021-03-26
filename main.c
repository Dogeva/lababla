#include "body.h"



void menu();
int main(int argc, char *argv[]){
	if (argc < 2){
	printf("error");
	return 0;

}

	store * structArray;
int size = 0;
	structArray = read_file_bin(structArray, argv, &size);

int n = 1;
	while (n != 0){
	menu();
	scanf("%d",&n);
	switch(n){
		case(1):
		structArray = add_new_salt(structArray, size);
		size++;
		break;

		case(2):
		printArray(structArray, size);
		break;

		case(3):
		deleteArray(structArray, size);
		size--;
		break;

		case(4):
		change(structArray,size);
		break;

		case (5):
		searchName(structArray,size);
		break;

	default:

	write_file_bin(structArray,argv, size);
	free(structArray);
	  }
     }
}
void menu(){
	printf("=====WELCOME IN THE STORE=====\n");
	printf("\n");
	printf("1.Добавить товар\n");
	printf("2.Просмотреть ассортимент\n");
	printf("3.Продать/удалить товар\n");
	printf("4.Изменить товар\n");
	printf("5.Найти товар по названию\n");
	printf("0.Выйти\n");
	printf("=================\n");
	printf("Выберите пункт с клавиатуры: ");
return;
}
