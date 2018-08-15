#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define TRUE 1
#define FALSE 0

#define CROSS -1
#define FILL 1
#define EMPTY 0

int nemo_size = 10;
void prnt_arr(const int len, const char* const arr)
{
	int i = 0;	//Prints array with numbers
	printf("[");
	for (i = 0; i<len - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d", arr[len - 1]);
	printf("]");
	printf("\n");
}
void dac(char* org, char* res, char* parr, char* nlist, int plen)
{
	//short of 'diff_arr_checker'
	char* arr_case = (char*)malloc(sizeof(char) * nemo_size);//arr_case organizing
	int i, j;
	int cnt = 0;
	int len = 2 * plen - 1; //len for loop
	for(i = 0; i < len; i++) 
	{
		if((i % 2) == 0)//
		{
			for(j = 0; j < parr[i/2]; j++)
				arr_case[cnt++] = CROSS;
		}
		else
		{
			for(j = 0; j < (nlist[i/2]); j++)
				arr_case[cnt++] = FILL;
		}
	}
	
	if(iea(org, nemo_size)  == TRUE) //short of 'is empty string'
	{
		if(iea(res, nemo_size) == TRUE) //if result is empty, fill case in result...
			memcpy(res, arr_case, sizeof(char) * nemo_size);
		else
		{
			for(i = 0; i < nemo_size; i++)
			{
				if(org[i] != arr_case[i])
					res[i] = EMPTY;
			}
		}
	}
	else
	{
		if(iea(res, nemo_size) == TRUE)
		{
			if(issub(arr_case, org, nemo_size) == TRUE)//issub checks is arr is sub.
				memcpy(res, arr_case, sizeof(char) * nemo_size);
		}
		else
		{
			for(i = 0; i < nemo_size; i++)
			{
				if(org[i] != arr_case[i])
					res[i] = EMPTY;
			}
		}
	}
	//TEST CASE
	printf("orgin : ");
	prnt_arr(nemo_size, res);
}
int main(int argc, char *argv[]) {
	char org[] = {0,0,0,0,0,0,0,0,0,0};
	char res[] = {0,0,0,0,0,0,0,0,0,0};
	char parr[] = {1,1,1,1};
	char nlist[] = {1,2,3};
	
	dac(org, res, parr, nlist, 4);
	return 0;
}
