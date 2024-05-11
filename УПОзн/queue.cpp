o#include "queue.h"


char** memory(int line, int signs)
{
	char** text;
	text = (char**)malloc(line * sizeof(char*));                                             //Ñîçäà¸ì ìàññèâ óêàçàòåëåé
	for (int i = 0; i < line; i++) {                                                         //Êàæäîìó ýëåìåíòó èç ìàññèâà óêàçàòåëåé ïðèñâàèâàåì àäðåñ âûäåëåííîãî ìàññèâà ïàìÿòè

		*(text + i) = (char*)malloc(signs * sizeof(char));
	}
	if (text == NULL)
	{
		printf("error");
		return 0;
	}
	return text;
}
queue_node* add_element_to_queue(queue_node** tail, queue_node* head, question elem_to_add)
{
	if (!head)
	{
		head = (queue_node*)malloc(sizeof(queue_node));
		*tail = (queue_node*)malloc(sizeof(queue_node));
		if (head == NULL)
		{
			printf("error\n");
			return 0;
		}
		head->inform = elem_to_add;
		head->next = NULL;
		*tail = head;
	}
	else
	{
		struct queue_node* temp;
		temp = (queue_node*)malloc(sizeof(queue_node));
		if (temp == NULL)
		{
			printf("error\n");
			return 0;
		}
		temp->inform = elem_to_add;
		temp->next = NULL;
		(*tail)->next = (queue_node*)malloc(sizeof(queue_node));
		(*tail)->next = temp;
		*tail = temp;
	}
	return head;
}
queue_node* create_queue(FILE* f, const char* file_name, queue_node* head, queue_node** tail, int n)
{
	if (fopen_s(&f, file_name, "rt") != 0)
	{
		printf("error.\n");
		return 0;
	}
	while (!feof(f))
	{
		question temp;
		temp.answers = memory(n, MAX_WORD);
		fgets(temp.qu, MAX_WORD, f);
		for (int i = 0; i < n; i++)
		{
			fgets(temp.answers[i], MAX_WORD, f);
		}
		head = add_element_to_queue(tail, head, temp);
	}
	fclose(f);
	return head;
}

void show_queue(queue_node* head, int n)
{
	if (!head)
	{
		printf("OOOps\n");
		return;
	}
	printf("%s", head->inform.qu);
	for (int i = 0; i < n; i++)
	{
		printf("%s", head->inform.answers[i]);
	}
	head = head->next;
}
void clear(char** mas, int size)
{
	for (int i = 0; i < size; i++)
		free(mas[i]);
	free(mas);
}
void delete_head_of_queue(queue_node** head, int n)
{
	if (*head != NULL)
	{
		queue_node* current = *head;
		if (current->next == NULL)
		{
			free(current);
			*head = NULL;
			return;
		}
		current = (*head)->next;
		clear((*head)->inform.answers, n);
		free(*head);
		*head = current;
	}
}
