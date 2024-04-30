#include "functions.h"
#include "input_functions.h"
#include "struct_results.h"
void clear(char** mas, int size)
{
	for (int i = 0; i < size; i++)
		free(mas[i]);
	free(mas);
}
void print_information(int type,person current_person_copy)
{
	int n;
	if (type == 1)
		n = 4;
	else
		n = 2;
	for (int i = 0; i < n; i++)
	{
		FILE* f_inf = NULL;
		char type[20];
		int size_file = 0;
		if ((current_person_copy.results + i)->amount_answers != 0)
		{
			strcpy_s(type, (current_person_copy.results + i)->type);
			char file_name[30] = "d:/";
			strcat_s(file_name, type);
			strcat_s(file_name, ".txt");
			char** inf = read_file(f_inf, file_name, &size_file);
			printf("%s%s%s", BLUE, (current_person_copy.results + i)->type, RESET);
			for (int j = 0; j < size_file; j++)
			{
				printf("%s\n", *(inf + j));
			}
			printf("\n");
			clear(inf, size_file);
		}
	}
}
person* memory(int amount)
{
	person* list;
	list = (person*)malloc(amount * sizeof(person));                                             //Создаём массив структур
	if (list == NULL)
	{
		printf("Память не выделена\n");
		return 0;
	}
	return list;
}
void input(person* list, int index, person temp_struct)
{
	*(list + index) = temp_struct;
}
void print_result(person current_person_copy)
{
	if (current_person_copy.results->amount_answers == 100)
		printf("%s, Вы на %d %s.\n", current_person_copy.nickname, (current_person_copy.results)->amount_answers, (current_person_copy.results)->type);
	else if (current_person_copy.type_test == 1)
	{
		printf("% s, в Вашем темпераменте сочетаются черты ", current_person_copy.nickname);
		int i = 0;
		for (i; i < 3; i++)
		{
			if ((current_person_copy.results + i)->amount_answers != 0)
				printf("%sа (%2d%%), ", (current_person_copy.results + i)->type, (current_person_copy.results + i)->amount_answers);
		}
		printf("%sа (%2d%%).", (current_person_copy.results + i)->type, (current_person_copy.results + i)->amount_answers);
	}
	else
	{
		if (current_person_copy.results->amount_answers <= 65)
		{
			printf("%s, Вы амбиверт. В Вашем характере сочетаются черты ", current_person_copy.nickname);
			int i = 0;
			for (i; i < 1; i++)
			{
				printf("и %sа (%2d%%), ", (current_person_copy.results + i)->type, (current_person_copy.results + i)->amount_answers);
			}
			printf("и %sа (%2d%%).", (current_person_copy.results + i)->type, (current_person_copy.results + i)->amount_answers);
		}
		else
		{
			printf("%s, Вы %s. (Результат теста: ", current_person_copy.nickname, current_person_copy.results->type);
			int i = 0;
			for (i; i < 1; i++)
			{
				printf("%s (%2d%%), ", (current_person_copy.results + i)->type, (current_person_copy.results + i)->amount_answers);
			}
			printf("%s (%2d%%))", (current_person_copy.results + i)->type, (current_person_copy.results + i)->amount_answers);

		}
	}
}
void sort_result(person* current_person_copy,int type)
{
	int n;
	if (type == 1)
		n = 4;
	else
		n = 2;
	for (int j = n-1; j >= 0; j--) {                                                    //сортировка строки методом "пузырька"
		for (int k = 0; k < j; k++) {
			if (((*current_person_copy).results + k)->amount_answers < ((*current_person_copy).results + k + 1)->amount_answers) {
				result temp;
				temp = *((*current_person_copy).results + k);
				*((*current_person_copy).results + k) = *((*current_person_copy).results + k + 1);
				*((*current_person_copy).results + k + 1) = temp;
			}
		}
	}
}
person create_copy(person current_person, int type)
{
	person current_person_copy;
	strcpy_s(current_person_copy.nickname, current_person.nickname);
	current_person_copy.type_test = current_person.type_test;
	(current_person_copy).results = (result*)malloc(4 * sizeof(result));
	int n;
	if (type == 1)
		n = 4;
	else
		n = 2;
	for (int i = 0; i < n; i++)
	{
		(current_person_copy.results + i)->amount_answers = (current_person.results + i)->amount_answers;
		strcpy_s((current_person_copy.results + i)->type, (current_person.results + i)->type);
	}
	return current_person_copy;
}
char** read_file(FILE* file, const char* file_name, int* size)                                               //функция чтения из файла
{
	char** text;
	text = (char**)malloc(LENGTH * sizeof(char*));                                                          //Создаём массив строк
	if (text == NULL)
	{
		printf("Память не выделена\n");
		return 0;
	}
	if (fopen_s(&file, file_name, "rt") != 0)
	{
		printf("Ошибка при открытии файла.\n");
		return 0;
	}
	char temp_text[MAX_WORD];
	while (!feof(file))
	{
		if (enter_str(temp_text, MAX_WORD, file) != NULL)
		{
			*(text + (*size)) = (char*)malloc(MAX_WORD * sizeof(char));
			strcpy_s(*(text + (*size)), MAX_WORD, temp_text);
			(*size)++;
		}
	}
	fclose(file);
	text = (char**)realloc(text, (*size) * sizeof(char*));
	return text;
}


result* temperament_test_answers(char** text, struct result* temperament_results, int size)
{
	char* result = (char*)malloc(20);
	char str[MAX_WORD];
	int mas[4] = { 0, 0, 0 ,0 };
	for(int j = 0; j < size; j+=5) {
		for (int i = 0; i < 5; i++)
		{
			if (*(text+i+j) != NULL)
				printf("%s\n", *(text + i + j));
		}
		printf("Введите ответ:\n");
		int a;

		enter_answer_temp(&a);
		mas[a - 1]++;
		(temperament_results[a - 1].amount_answers)++;
		system("cls");
	}
	for (int i = 0; i < 4; i++)

		temperament_results[i].amount_answers *= 10;

	return temperament_results;
}
void temp_test(FILE* f, int size, person* temp_struct, result* temperament_results)
{

	char** text = read_file(f, FILE_TEMPERAMENT, &size);
	(*temp_struct).results = (result*)malloc(4 * sizeof(result));
	result* temp_result = (result*)malloc(4 * sizeof(result));
	temp_result = temperament_test_answers(text, temperament_results, size);
	for (int j = 0; j < 4; j++)
	{
		*((*temp_struct).results + j) = *(temp_result + j);
	}

	for (int j = 0; j < 4; j++)
		temperament_results[j].amount_answers = 0;
}
void character_test(FILE* f, int size, person* temp_struct, result* answer_character)
{

	char** text = read_file(f, FILE_CHARACTER, &size);
	(*temp_struct).results = (result*)malloc(2 * sizeof(result));
	result* temp_result = (result*)malloc(2 * sizeof(result));
	temp_result = character_test_answer(text, answer_character, size);
	for (int j = 0; j < 2; j++)
	{
		*((*temp_struct).results + j) = *(temp_result + j);
	}

	for (int j = 0; j < 2; j++)
		answer_character[j].amount_answers = 0;
}
////////result* temperament_test(FILE* f, struct result* temperament_results)
////////{
////////	char* result = (char*)malloc(20);
////////	char str[1000];
////////	fopen_s(&f, "d:/тест на темперамент.txt", "r");
////////	/*if (err == 0)
////////	{
////////		printf("The file 'crt_fopen_s.c' was opened\n");
////////	}
////////	else
////////	{
////////		printf("The file 'crt_fopen_s.c' was not opened\n");
////////	}*/
////////	int mas[4] = { 0, 0, 0 ,0 };
////////	while (!feof(f)) {
////////		// while (fgets(c, 100, f) != NULL)
////////		for (int i = 0; i < 5; i++)
////////		{
////////			if (enter_str(str, 1000, f) != NULL)
////////				printf("%s\n", str);
////////		}
////////		int a;
////////		printf("Введите ответ:\n");
////////		enter_answer_temp(&a);
////////		/*scanf_s("%d", &a);*/
////////		mas[a - 1]++;
////////		(temperament_results[a - 1].amount_answers)++;
////////		system("cls");
////////	}
////////	printf("%d, %d, %d, %d", mas[0], mas[1], mas[2], mas[3]);
////////	printf("\n");
////////	/*int max_answer = 0;
////////	int n = 0;
////////	for (int i = 0; i < 4; i++)
////////	{
////////
////////		if (max_answer < temperament_results[i].amount_answers)
////////		{
////////			max_answer = temperament_results[i].amount_answers;
////////			n = i;
////////			result = temperament_results[i].type;
////////		}
////////	}*/
////////	for (int i = 0; i < 4; i++)
////////
////////		temperament_results[i].amount_answers *= 10;
////////
////////		/*printf((temperament_results + n)->type);*/
////////		/*fscanf_s(f, "%s", c);
////////		printf("%s", c);*/
////////	fclose(f);
////////	return temperament_results;
////////}
result* character_test_answer(char** text, struct result* character_results, int size)
{
	char* result = (char*)malloc(20);
	char str[1000];
	//fopen_s(&f, "d:/тест на характер.txt", "r");
	/*if (err == 0)
	{
		printf("The file 'crt_fopen_s.c' was opened\n");
	}
	else
	{
		printf("The file 'crt_fopen_s.c' was not opened\n");
	}*/
	int mas[2] = { 0, 0};
	for (int j = 0; j < size; j += 3) {
		// while (fgets(c, 100, f) != NULL)
		for (int i = 0; i < 3; i++)
		{
			if (*(text + i + j) != NULL)
				printf("%s\n", *(text + i + j));
		}
		int a;
		printf("Введите ответ:\n");
		enter_answer_charct(&a);
		/*scanf_s("%d", &a);*/
		mas[a - 1]++;
		(character_results[a - 1].amount_answers)++;
		system("cls");
	}
	printf("%d, %d", mas[0], mas[1]);
	printf("\n");
	for (int i = 0; i < 2; i++)
		character_results[i].amount_answers = int(character_results[i].amount_answers*100/15);
	/*int max_answer = 0;
	int n = 0;*/
	
	/*printf((temperament_results + n)->type);*/
	/*fscanf_s(f, "%s", c);
	//printf("%s", c);*/
	//fclose(f);
	return character_results;
}
//void print_questions(char** text, int amount_line_in_question, int size)
//{
//
//		for (int i = 0; i < 5; i++)
//		{
//			if (*(text + i + j) != NULL)
//				printf("%s\n", *(text + i + j));
//		}
//		printf("Введите ответ:\n");
//}
//void out(person* list, int n)
//{
//	printf("Никнейм\t\tРезультат\n");
//	for (int i = 0; i < n; i++)
//	{
//		if ((list + i)->type_test == 1)
//			printf("%-10s %10s %3d %10s %3d %10s %3d %10s %3d\n", list[i].nickname, list[i].results[0].type, list[i].results[0].amount_answers, list[i].results[1].type, list[i].results[1].amount_answers, list[i].results[2].type, list[i].results[2].amount_answers, list[i].results[3].type, list[i].results[3].amount_answers);
//		else
//			printf("%-10s %10s %3d %10s %3d\n", list[i].nickname, list[i].results[0].type, list[i].results[0].amount_answers, list[i].results[1].type, list[i].results[1].amount_answers);
//	}
//}