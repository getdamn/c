#ifndef _INC_STDIO
#include <stdio.h>
#endif
#ifndef _INC_STDLIB
#include <stdlib.h>
#endif
#ifndef _fset
#define _fset

char** db_ptr_maker(const int len)
{
	return (char**)malloc(sizeof(char*) * len);
}
char* arr_maker(const int len)
{
	return (char*)malloc(sizeof(char) * len);
}
char** arr_2d_maker(const int col, const int row)
{
	int i;
	char** arr_2d = (char**)malloc(sizeof(char*)*col);
	for (i = 0; i < col; i++)
		arr_2d[i] = arr_maker(row);
	return arr_2d;
}
void arr_2d_init(char** const arr, const int col, const int row, const int init_char)
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
			arr[i][j] = init_char;
	}
}
char* spl_arr(const char* const arr, const int len)
{
	if (len > 100)
	{
		printf("Function:spl_arr Error, Check the parameter, len");
		return NULL;
	}
	int i, buf[100];
	int cnt = 0;
	int num = 0;
	int NE_len = len - 1;//null exterminated len
	for (i = 0; i < NE_len; i++)
	{
		if (arr[i] == ' ')
		{
			if (i == 0)
			{
				fputs("Function spl_arr Error, Invalid Input", stdout);
				return NULL;
			}

			else
			{
				buf[cnt] = num;
				num = 0;
				cnt++;
			}
		}
		else if (i == (NE_len - 1))
		{
			num = (num * 10) + arr[i] - 48;//char to interger
			if ((num > 255) && (num < 0))
			{
				fputs("Function spl_arr Error: overflow occured", stdout);
				return NULL;
			}
			buf[cnt] = num;
			cnt++;
		}
		else
			num = (num * 10) + arr[i] - 48;
	}
	char* sp_arr = (char*)malloc(sizeof(char)*(cnt + 1));//splited arr
	for (i = 0; i < cnt; i++)
		sp_arr[i] = buf[i];
	sp_arr[cnt] = '\0';
	return sp_arr;//please free later
}
void arr_init(const int len, char* const arr, const char init)
{
	int i;
	for (i = 0; i < len; i++) arr[i] = init;
}
#endif