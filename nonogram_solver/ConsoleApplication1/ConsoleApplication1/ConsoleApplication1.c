#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include"file_setting.h" //for file setting
#include"solver_core.h"

#define TRUE 1
#define FALSE 0

#define CROSS -1
#define FILL 1
#define EMPTY 0

#define debug_mod 1//!!!debug_mod can reduce performance!!!

//File Functions
//solver Function
int nono_solver(char** const nemo_table, const char** const row_nlist, const char** const col_nlist, int* const p_num, int* const num, char* const org, char* res)
{
	int i, j;
	for (i = 0; i < nemo_size; i++)
	{
		*num = 0;
		*p_num = strlen(row_nlist[i]) + 1;
		for (j = 0; j < nemo_size; j++) org[j] = nemo_table[i][j];
		for (j = 0; j < strlen(row_nlist[i]); j++) *num += row_nlist[i][j];
		*num = nemo_size - *num - *p_num + 2;
		res = p_part(*p_num, *num, org, row_nlist[i]);
		for (j = 0; j < nemo_size; j++) nemo_table[i][j] = res[j];
		#if debug_mod == 1
			printf("num:%d, p_num:%d\n", *num, *p_num);
		#endif
	}
	for (i = 0; i < nemo_size; i++)
	{
		*num = 0;
		*p_num = strlen(col_nlist[i]) + 1;
		for (j = 0; j < nemo_size; j++) org[j] = nemo_table[j][i];
		for (j = 0; j < strlen(col_nlist[i]); j++) *num += col_nlist[i][j];
		*num = nemo_size - *num - *p_num + 2;
		res = p_part(*p_num, *num, org, col_nlist[i]);
		for (j = 0; j < nemo_size; j++) nemo_table[j][i] = res[j];
		#if debug_mod == 1
			printf("num:%d, p_num:%d\n", *num, *p_num);
		#endif
	}
	printf("┏");
	for (i = 0; i < nemo_size; i++) printf("　");
	printf("┓\n");
	for (i = 0; i < nemo_size; i++)
	{
		printf("┃");
		for (j = 0; j < nemo_size; j++)
		{
			if (nemo_table[i][j] == 1)
				printf("■");
			else if (nemo_table[i][j] == -1)
				printf("×");
			else
				printf("　");
		}
		printf("┃\n");		
	}
	printf("┗");
	for (i = 0; i < nemo_size; i++) printf("　");
	printf("┛\n");
}
int ist(const char** const table, const char** const pre_table, const int size)//is same table
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			if (table[i][j] != pre_table[i][j])
				return FALSE;
	}
	return TRUE;
}
void table_cpy(char** const des, char** const org, const int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			des[i][j] = org[i][j];
	}
}
int main(int argc, char *argv[]) {
	FILE* fp;
	errno_t err= fopen_s(&fp, "input.txt", "rt");
	if (err == 1)
		fputs("FILE open error", stdout);
	
	char buf[100];
	fgets(buf, 101, fp);
	nemo_size = atoi(buf); //Input nemo_size
	char** nemo_table = arr_2d_maker(nemo_size, nemo_size);
	arr_2d_init(nemo_table, nemo_size, nemo_size, 0);

	char** pre_table = arr_2d_maker(nemo_size, nemo_size);
	arr_2d_init(pre_table, nemo_size, nemo_size, 0);//pre table
	//nemo_table initialized
	char** row_nlist = db_ptr_maker(nemo_size);//horizontal factors
	char** col_nlist = db_ptr_maker(nemo_size);//vertical factors
	//make nlists(numeral hints)

	int i, j;//indexes
	for (i = 0; i < nemo_size; i++)
	{
		fgets(buf, 101, fp);
		row_nlist[i] = spl_arr(buf, strlen(buf));
	}
	fgets(buf, 101, fp);//Enter
	for (i = 0; i < (nemo_size - 1); i++)
	{
		fgets(buf, 101, fp);
		col_nlist[i] = spl_arr(buf, strlen(buf));//Edit
	}
	fgets(buf, 101, fp);
	col_nlist[i] = spl_arr(buf, strlen(buf) + 1);
	if (!feof(fp))
	{
		printf("Input File Error Please check input file");
		return -1;
	}
	printf("File Setting complete\n");

	int* p_num = (int*)malloc(sizeof(int));
	int* num = (int*)malloc(sizeof(int));
	char* org = (char*)malloc(sizeof(char) * nemo_size);
	char* res = (char*)malloc(sizeof(char) * nemo_size);
	do
	{
		#if debug_mod == 0
			system("CLS");
		#endif
		table_cpy(pre_table, nemo_table, nemo_size);
		nono_solver(nemo_table, row_nlist, col_nlist, p_num, num, org, res);
	} while (ist(nemo_table, pre_table, nemo_size) == FALSE);
	
	for (i = 0; i < nemo_size; i++)
	{
		free(nemo_table[i]);
		free(row_nlist[i]);
		free(col_nlist[i]);
	}

	free(nemo_table);
	free(row_nlist);
	free(col_nlist);
	free(p_num);
	free(num);
	free(org);
	free(res);

	fclose(fp);
	system("PAUSE");
	return 0;
}