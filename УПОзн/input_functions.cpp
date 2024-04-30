#include"input_functions.h"
char* enter_str(char* str, int size, FILE* stream=stdin)
{
    rewind(stdin);
    fgets(str, size, stream);
    for (int j = 0; j < strlen(str) + 1; j++)
    {
        if (str[j] == '\n') {
            str[j] = '\0';
        }
    }
    return str;
}
void enter_int(int* num)
{
    int val;
    do {
        rewind(stdin);
        val = scanf_s("%d", num);
        if (!val)
            printf("Неверный ввод. Повторите попытку. \n");
    } while  (!val);
}
void enter_answer_temp(int* num)
{
    int val;
    do {
        rewind(stdin);
        val = scanf_s("%d", num);
        if (!val ||( *num!=1 && *num!=2 && *num!=3 && *num!=4))
            printf("Неверный ввод. Повторите попытку. \n");
    } while (!val || (*num != 1 && *num != 2 && *num != 3 && *num != 4));
}
void enter_answer_charct(int* num)
{
    int val;
    do {
        rewind(stdin);
        val = scanf_s("%d", num);
        if (!val || (*num != 1 && *num != 2))
            printf("Неверный ввод. Повторите попытку. \n");
    } while (!val || (*num != 1 && *num != 2));
}
void enter_float(float* num)
{
    int val;
    do {
        rewind(stdin);
        val = scanf_s("%f", num);
        if (!val)
            printf("Неверный ввод. Повторите попытку. \n");
    } while (!val);
}