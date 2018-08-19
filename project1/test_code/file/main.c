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
		arr_2d = arr_maker(row);
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
	while(!feof(fp))
	{
		fgets(buf, 101, fp);
		
	}
	return 0;
}
