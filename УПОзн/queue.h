#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Windows.h"
#define LENGTH 50
#define MAX_WORD 142
struct question
{
	char qu[MAX_WORD];
	char** answers;
};
struct queue_node
{
	question inform;
	queue_node* next;
};
char** memory(int line, int signs);
queue_node* create_queue(FILE* f, const char* file_name, queue_node* head, queue_node** tail, int n);
queue_node* add_element_to_queue(queue_node** tail, queue_node* head, question elem_to_add);
void show_queue(queue_node* head, int n);
void delete_head_of_queue(queue_node** head, int n);
void clear(char** mas, int size);