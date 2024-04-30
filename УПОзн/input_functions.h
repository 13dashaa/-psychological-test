#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Windows.h"
char* enter_str(char* str, int size, FILE* stream);
void enter_int(int* num);
void enter_answer_charct(int* num);
void enter_answer_temp(int* num);
void enter_float(float* num);