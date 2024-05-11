#include "list.h"
Node* clear_ring(Node** head) {
    if (*head != NULL)
    {
        Node* current = *head;
        do
        {
            if (current->next == NULL)
            {
                free(current->cur_person.results);
                free(current);
                *head = NULL;
                break;
            }
            if (*head == current)
                (*head) = (*head)->next;
            current->next->prev = current->prev;
            if(current->prev!=NULL)
                current->prev->next = current->next;
            free(current->cur_person.results);
            free(current);
            current = (*head)->next;
        } while (current != NULL);

    }
    return *head;
}
struct Node* createNode(person value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->cur_person = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
Node* get_next_place(Node* place, person new_person)
{
    if (place == NULL || (place->next && strcmp(place->next->cur_person.nickname, new_person.nickname) >= 0) || (!(place->next) && strcmp(place->cur_person.nickname, new_person.nickname) >= 0))
        return NULL;
    while (place->next && strcmp(place->next->cur_person.nickname, new_person.nickname) < 0)
    {
        place = (place->next);
    }
    return place;
}
void add_el(struct Node** head, person new_person) {
    struct Node* newNode = createNode(new_person);
    // Если список пустой или значение нового узла меньше значения головного узла,
    // делаем новый узел головным и устанавливаем его указатель next на предыдущий головной узел
    if (*head == NULL || strcmp(new_person.nickname, (*head)->cur_person.nickname)<0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    // Проходим по списку, пока значение текущего узла меньше значения нового узла
    while (current->next != NULL && strcmp(current->next->cur_person.nickname, new_person.nickname)<0)
    {
        current = current->next;
    }
    // Вставляем новый узел между текущим и следующим узлами
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void displayList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%-10s", current->cur_person.nickname);
        int n = 0;
        if(current->cur_person.type_test==1)
        {
            n = 4;
        }
        else 
        {
            n = 2;
        }
        for (int i = 0; i < n; i++)
        {
            printf("%-10s %-5d", (current->cur_person.results + i)->type, (current->cur_person.results + i)->amount_answers);
        }
        current = current->next;
        printf("\n");
    }
}

void file_write(FILE* file, const char* file_name, struct Node* head)                           //функция записи в файл
{
    fopen_s(&file, file_name, "wt");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        exit(EXIT_FAILURE);
    }
    struct Node* current = head;
    while (current != NULL)
    {
        fprintf(file, "%-10s", current->cur_person.nickname);
        int n = 0;
        if (current->cur_person.type_test == 1)
        {
            n = 4;
        }
        else
        {
            n = 2;
        }
        for (int i = 0; i < n; i++)
        {
            fprintf(file, "%12s %3d%%", (current->cur_person.results + i)->type, (current->cur_person.results + i)->amount_answers);
        }
        current = current->next;
        fprintf(file, "\n");
    }
    fclose(file);
}

//Node* get_next_place(Node* place, person new_person)
//{
//    if (place == NULL || (place->next && strcmp(place->next->cur_person.nickname, new_person.nickname) >= 0) || (!(place->next) && strcmp(place->cur_person.nickname, new_person.nickname) >= 0))
//        return NULL;
//    /*else if (!(place->next) && strcmp(place->cur_person.nickname, new_person.nickname) >= 0)
//        return NULL;*/
//	while (place->next && strcmp(place->next->cur_person.nickname, new_person.nickname) < 0)
//	{
//		place = (place->next);
//	}
//
//	return place;
//}
//void addel(Node** head, person new_person)
//{
//	Node* place = get_next_place(*head, new_person);
//	Node* temp = (Node*)malloc(sizeof(Node));
//	temp->cur_person = new_person;
//    if (place != NULL)
//    {
//        temp->next = place->next;
//        place->next = temp;
//    }
//    else
//    {
//        temp->next = (*head);
//        (*head) = temp;
//    }
//}