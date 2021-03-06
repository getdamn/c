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
	for (i = 0; i<len; i++)
	{
		if(arr[i] == FILL) printf("O");
		else if(arr[i] == CROSS) printf("X");
		else printf("_");
	}
	printf("]");
	printf("\n");
}
int iea(char* arr, int len, char emp_char)
{
	/*	DES:	Short of is empty array
				Returns input array is empty or not
		INPUT	(char*)arr:	array to be checked as empty
				(int)len:	length of array
				(char)emp_char:	character recognized as empty
		OUTPUT	(int)TRUE
				(int)FALSE
		Ex) iea(arr, 5, 0); iea(arr, 5, '\0');
	*/
	int i;
	for(i = 0; i < len; i ++)
		if(arr[i] != emp_char) return FALSE;
	return TRUE;
}
int issub(char* case_arr, char* comp, int len, char emp_char) //chk case_arr is sub
{
	/*	DES: Returns TRUE if case_arr is subordinated to comp.
		INPUT	(char*)case_arr:	array to be checked as subordinated
				(char*)comp: 		array to be compared
				(int)len:			length of arraies
				(char)emp_char:		character to be recognized as empty
		OUTPUT	(int)TRUE
				(int)FALSE
		Ex)	issub(arr, arr2, 5, 0); issub(arr, arr2, 5, '0');
	*/
	int i;
	for(i = 0; i < len; i++)
		if((comp[i] !=  emp_char) & (comp[i] != case_arr[i]))
			return FALSE;
	return TRUE;
}
void dac(char* org, char* res, char* parr, char* nlist, int plen)
{
	/*	DES:	Short of Difference array check
				Assign res result of differences of arraies
		INPUT	(char*)org:	Orignal array
				(char*)res: array to be saved as result
				(char*)parr:array saves p-parted numbers
				(char*)nlist:array saves number list
				(int)plen: length of parr
		OUTPUT	(void)
		Ex) dac(org, res, parr, nlist, 5);
	*/
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
	
	if(iea(org, nemo_size, EMPTY)  == TRUE) //short of 'is empty string'
	{
		if(iea(res, nemo_size, EMPTY) == TRUE) //if result is empty, fill case in result...
			memcpy(res, arr_case, sizeof(char) * nemo_size);
		else
		{
			for(i = 0; i < nemo_size; i++)
			{
				if(res[i] != arr_case[i])
					res[i] = EMPTY;
			}
		}
	}
	else
	{
		if(issub(arr_case, org, nemo_size, EMPTY) == TRUE)
		{//issub checks is arr is sub
			if(iea(res, nemo_size, EMPTY) == TRUE)			
				memcpy(res, arr_case, sizeof(char) * nemo_size);
			else
			{
				for(i = 0; i < nemo_size; i++)
				{
					if(res[i] != arr_case[i])
						res[i] = EMPTY;
				}
			}
		}
	}
}
int main(int argc, char *argv[]) {
	char org[] = {1,0,0,0,0,0,0,0,0,0};
	char res[] = {1,-1,1,1,-1,1,1,1,-1,-1};
	char parr[] = {0,1,2,1};
	char nlist[] = {1,2,3};
	
	dac(org, res, parr, nlist, 4);
	return 0;
}
