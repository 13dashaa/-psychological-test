#pragma once
#include "functions.h"
//typedef struct Node
//{
//	struct person cur_person;
//	struct Node* next;
//
//};
struct Node
{
	struct person cur_person;
	struct Node* next;
	struct Node* prev;
};
struct Node* createNode(person value);
void add_el(struct Node** head, person new_person);
void addel(struct Node** head, struct person new_person);
struct Node* get_next_place(struct Node* place, struct person new_person);
void displayList(struct Node* head);
void pop(Node** head);
void file_write(FILE* file, const char* file_name, struct Node* head);