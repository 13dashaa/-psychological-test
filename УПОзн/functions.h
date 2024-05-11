#pragma once
#include "input_functions.h"
#include "queue.h"
#define FILE_TEMPERAMENT "d:/тест на темперамент.txt"
#define FILE_CHARACTER "d:/тест на характер.txt"
#define N 30
#define RESET   "\033[0m"
#define BLUE     "\033[1;34m"
#define RED   "\033[1;31m"
struct result
{
	int amount_answers;
	char type[N];
};
struct person
{
	char nickname[N];
	int type_test;
	result* results;
};
char** read_file(FILE* file, const char* file_name, int* size);                                               //функция чтения из файла
result* test_answers(queue_node* head, struct result* answers, int size);
void test(FILE* f, const char* file_name, int size, person* temp_struct, result* test_results);
void print_information(int type, person current_person_copy);
void print_result(person current_person_copy);
void sort_result(person* current_person_copy, int type);
person create_copy(person current_person, int type);






//void input(person* list, int index, person temp_struct);
////void temp_test(FILE* f, int size, person* temp_struct, result* temperament_results);
//result* temperament_test_answers(queue_node* head, struct result* temperament_results, int size);
//result* temperament_test_answers(char** text, struct result* temperament_results, int size);
//void clear(char** mas, int size);
//result answer_character[2] = { {0,"Интроверт"}, {0, "Экстроверт"} };
//result temperament_results[4] = { {0,"Сангвиник"}, {0,"Холерик"}, {0,"Флегматик"}, {0,"Меланхолик"} };
////result* temperament_test(FILE* f, struct result* temperament_results);
//result* character_test_answer(queue_node* head, struct result* character_results, int size);
//result* character_test_answer(char** text, struct result* character_results, int size);
//result* character_test(FILE* f, struct result* character_results);
//char* temperament_test(FILE* f, struct result* temperament_results);
//void enter_temperament_result(result* temperament_results);
//void out(person* list, int n);