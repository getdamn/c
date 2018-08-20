#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int nemo_size;
char** db_ptr_maker(int len)
{ 
	return (char**)malloc(sizeof(char*) * len);
}
char* arr_maker(int len)
{
	return (char*)malloc(sizeof(char) * len);
}
char** arr_2d_maker(int col, int row)
{
	int i;
	char** arr_2d = (char**)malloc(sizeof(char*)*col);
	for(i = 0; i < col; i++)
		arr_2d[i] = arr_maker(row);
	return arr_2d; 
}
void arr_2d_init(char** arr, int col, int row, int init_char)
{
	int i, j;
	for(i = 0; i < col; i++)
	{
		for(j = 0; j < row; j++)
			arr[i][j] = init_char;
	}
}
char* spl_arr(const char* const arr, const int len)
{
	if(len > 100)
	{
		printf("Function:spl_arr Error, Check the parameter, len");
		return NULL;
	}
	int i, buf[100];
	int cnt = 0; 
	int num = 0;
	int NE_len = len - 1;//null exterminated len
	for(i = 0; i < NE_len; i++)
	{
		if(arr[i] == ' ')
		{
			if(i == 0)
			{
				fputs("Fnction,spl_arr Error, Invalid Input",stdout);
				return NULL;
			}
			
			else
			{
				buf[cnt] = num;
				num = 0;
				cnt++;
			}
		}
		else if(i == (NE_len - 1))
		{
			num = (num * 10) + arr[i] - 48;//char to interger
			if((num > 255) && (num < 0))
			{
				fputs("Function spl_arr Error: overflow occured",stdout);
				return NULL;
			}
			buf[cnt] = num;	
			cnt++;
		}
		else
			num = (num * 10) + arr[i] - 48;
	}	
	char* sp_arr = (char*)malloc(sizeof(char)*cnt);//splited arr
	for(i = 0; i < cnt; i++)
		sp_arr[i] = buf[i];
	return sp_arr;//please free later
}
int main(int argc, char *argv[]) {
	FILE* fp = fopen("test.txt","rt");
	if(fp == NULL)
		fputs("FILE open error",stdout);
	
	char buf[100];
	fgets(buf, 101, fp);
	nemo_size = atoi(buf); //Input nemo_size

	char** nemo_table = arr_2d_maker(nemo_size, nemo_size);
	arr_2d_init(nemo_table, nemo_size, nemo_size, 0);
	//nemo_table initialized
	char** col_nlist = db_ptr_maker(nemo_size);
	char** row_nlist = db_ptr_maker(nemo_size);
	//make nlists(numeral hints)
 	int i;
	for(i = 0; i < nemo_size; i++)
	{
		fgets(buf, 101, fp);
		col_nlist[i] = spl_arr(buf, strlen(buf));
	}
	fgets(buf, 101, fp);//Enter
	for(i = 0; i < nemo_size; i++)
	{
		fgets(buf, 101, fp);
		row_nlist[i] = spl_arr(buf, strlen(buf));
	}
	if(!feof(fp))
	{
		printf("Input File Error Please check input file");
		return -1;
	}
	
	
	return 0;
}
