#include "functions.h"
//#include "queue.h"
#include "list.h"
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	result answer_character[2] = { {0,"introvert"}, {0, "ekstravert"} };
	result temperament_results[4] = { {0,"sangvinic"}, {0,"holeric"}, {0,"flegmatic"}, {0,"melanholic"} };
	int flag;
	do
	{
		int amount;
		printf("enter amount of people\n");
		enter_int(&amount);
		Node* head = NULL;
		system("CLS");
		for (int i = 0; i < amount; i++)
		{
			rewind(stdin);
			person current_person;
			FILE* f = NULL;
			printf("Введите никнейм %d% человека.\n", i + 1);
			enter_str(current_person.nickname, N, stdin);
			printf("Если хотите определить тип темперамента, введите 1. Если же хотите проити тест на характер, введите 2.\n");
			enter_answer_charct(&current_person.type_test);
			system("CLS");
			int size;
			const char* file_name;
			result* test_result;
			if (current_person.type_test == 1)
			{
				size = 4;
				file_name = FILE_TEMPERAMENT;
				test_result = temperament_results;
			}
			else
			{
				size = 2;
				file_name = FILE_CHARACTER;
				test_result = answer_character;
			}
			test(f, file_name, size, &current_person, test_result);
			add_el(&head, current_person);													//äîáàâëåíèå ñòðóêòóðû ÷åëîâåêà â ñïèñîê. Ñïèñîê ñîðòèðóåòñÿ ïî àëôàâèòó
			person current_person_copy = create_copy(current_person, current_person.type_test);
			sort_result(&current_person_copy, current_person.type_test);
			printf("%s%s%s\nРезультат теста не является достоверным на 100 %% и имеет исключительно информативный характер.\nНажмите для продолжения\n", RED, "ВНИМАНИЕ!!!", RESET);
			_getch();
			system("CLS");
			print_result(current_person_copy);												//âûâîä ðåçóëüòàòîâ òåñòèðîâàíèÿ íà ýêðàí				
			printf("\nЕсли хотите узнать расшифровку теста введите 1.\n");
			int sign;
			enter_int(&sign);
			if (sign == 1)
			{
				print_information(current_person.type_test, current_person_copy);			//âûâîä ïîÿñíåíèÿ ðåçóëüòàòà
				_getch();
			}
			system("CLS");
			free(current_person_copy.results);
		}
		FILE* f_res = NULL;
		file_write(f_res, "result", head);												  //çàïèñü â ôàéë
		printf("\nЕсли хотите выполнить программу еще раз, введите 1. Иначе, введите 0.\n");					//çàïðîñ íà ïîâòîðíîå âûïîëíåíèå ïðîãðàìû
		int val2;
		do {
			rewind(stdin);
			val2 = scanf_s("%d", &flag);																		//ïðîâåðêà ââîäà
			if (!val2 || (flag != 0 && flag != 1))
				printf("erorr.\n");
		} while (!val2 || (flag != 0 && flag != 1));
		system("CLS");
		clear_ring(&head);
	} while (flag);
	return 0;
}
