#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Windows.h"
#include "input_functions.h"
#define FILE_TEMPERAMENT "d:/тест на темперамент.txt"
#define FILE_CHARACTER "d:/тест на характер.txt"
//#include "list.h"
//#include "list.h"
#define N 30
#define LENGTH 50
#define MAX_WORD 142
#define RESET   "\033[0m"
#define BLUE     "\033[1;34m"
#define RED   "\033[1;31m"
struct result
{
	int amount_answers;
	char type[N];
};
//struct person
//{
//	char nickname[N];
//	int type_test;
//	char results[N];
//};
struct person
{
	char nickname[N];
	int type_test;
	result* results;
};
char** read_file(FILE* file, const char* file_name, int* size);                                               //функция чтения из файла
//result answer_character[2] = { {0,"Интроверт"}, {0, "Экстроверт"} };
//result temperament_results[4] = { {0,"Сангвиник"}, {0,"Холерик"}, {0,"Флегматик"}, {0,"Меланхолик"} };
////result* temperament_test(FILE* f, struct result* temperament_results);
void print_information(int type, person current_person_copy);
void clear(char** mas, int size);
void print_result(person current_person_copy);
void sort_result(person* current_person_copy, int type);
person create_copy(person current_person, int type);
void character_test(FILE* f, int size, person* temp_struct, result* answer_character);
void temp_test(FILE* f, int size, person* temp_struct, result* temperament_results);
result* temperament_test_answers(char** text, struct result* temperament_results, int size);
person* memory(int amount);
void input(person* list, int index, person temp_struct);
result* character_test_answer(char** text, struct result* character_results, int size);
//result* character_test(FILE* f, struct result* character_results);
//char* temperament_test(FILE* f, struct result* temperament_results);
//void enter_temperament_result(result* temperament_results);
void out(person* list, int n);