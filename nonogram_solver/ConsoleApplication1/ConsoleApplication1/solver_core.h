//extern nemo_size;
#ifndef _INC_STDIO
#include <stdio.h>
#endif

#ifndef _INC_STDLIB
#include <stdlib.h>
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef CROSS
#define CROSS -1
#endif

#ifndef FILL
#define FILL 1
#endif

#ifndef EMPTY
#define EMPTY 0
#endif

#ifndef solcore
#define solcore
int nemo_size;
void prnt_arr(const int len, const char* const arr)
{
	int i = 0;
	printf("[");
	for (i = 0; i<len; i++)
	{
		if (arr[i] == FILL) printf("¡á");
		else if (arr[i] == CROSS) printf("¡¿");
		else printf("¡¡");
	}
	printf("]");
	printf("\n");
}
int iea(const char* const arr, const int len, const char emp_char)
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
	for (i = 0; i < len; i++)
		if (arr[i] != emp_char) return FALSE;
	return TRUE;
}
int issub(const char* const case_arr, const char* const comp, const int len, const char emp_char)
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
	for (i = 0; i < len; i++)
		if ((comp[i] != emp_char) & (comp[i] != case_arr[i]))
			return FALSE;
	return TRUE;
}
void dac(const char* const org, char* const res, const char* const parr, const char* const nlist, const int plen, int* const init)//init is initial parr case...
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
	for (i = 0; i < len; i++)
	{
		if ((i % 2) == 0)
		{
			if (((i / 2) == 0) || ((i / 2) == (len - 1) / 2))
			{
				for (j = 0; j < parr[i / 2]; j++)
					arr_case[cnt++] = CROSS;
			}
			else
			{
				for (j = 0; j < (parr[i / 2] + 1); j++)
					arr_case[cnt++] = CROSS;
			}
		}
		else
		{
			for (j = 0; j < (nlist[i / 2]); j++)
				arr_case[cnt++] = FILL;
		}
	}
	//prnt_arr(nemo_size, arr_case);
	if (iea(org, nemo_size, EMPTY) == TRUE) //short of 'is empty string'
	{
		if ((iea(res, nemo_size, EMPTY) == TRUE) && (*init == TRUE))
		{//if result is empty, fill case in result...
			memcpy(res, arr_case, sizeof(char) * nemo_size);
			*init = FALSE;
		}
		else
		{
			for (i = 0; i < nemo_size; i++)
			{
				if (res[i] != arr_case[i])
					res[i] = EMPTY;
			}
		}
	}
	else
	{
		if (issub(arr_case, org, nemo_size, EMPTY) == TRUE)
		{//issub checks is arr is sub
			if ((iea(res, nemo_size, EMPTY) == TRUE) && (*init == TRUE)) {//errror
				memcpy(res, arr_case, sizeof(char) * nemo_size);
				*init = FALSE;
			}
			else
			{
				for (i = 0; i < nemo_size; i++)
				{
					if (res[i] != arr_case[i])
						res[i] = EMPTY;
				}
			}
		}
	}
	free(arr_case);
#if debug_mod == 1
	prnt_arr(nemo_size, res);
#endif
}
int p_rec(const int p_num, int level, const int num, char* const parr, const char* const org, const char* const nlist, char* const res, int* const init)
{
	/*	INPUT	(int) p_num : Number to part,
	(int) level : interger to count part number and an condition variable to exit,
	(int) num : Number to be parted,
	(int) parr : Pointer of p-partition
	(char*)parr:array saves p-parted numbers
	(char*)nlist:array saves number list
	(char*)res: Result of dac..
	OUTPUT	(void)
	Des: Excute Recursive part of P-Partitioning
	Ex) p_rec(part, 0, num, res);
	*/
	int i, rep; //rep : the number to be repeated
	int sum = 0;
	for (i = 0; i < level; i++) sum += parr[i];	//Calculate sum to caculate remain to be parted

	if (level == (p_num - 1))
	{	//if level reach last level
		parr[level] = num - sum;
		dac(org, res, parr, nlist, p_num, init);
		return 0;	//when the last level ends, returns 0
	}
	else if (level == 0)	//if level's status is initial(level == 0)
		rep = num + 1;	//rep is num+1 because first element of p-part can be 0 to num
	else
		rep = num - sum + 1;

	for (i = 0; i < rep; i++)
	{
		parr[level] = i; //Input a number of occasion
		p_rec(p_num, level + 1, num, parr, org, nlist, res, init);
	}
	return 0;	//when a level ends, returns 0
}
char* p_part(const int p_num, const int num, const char* const org, const char* const nlist)
{
	/*	INPUT	(int) p_num : Number to part,
	(int) num : Number to be parted
	OUTPUT (char*) res : Pointer of result
	Des : Excute P-Partioning by Number to part and Number to parted.
	Ex) p_part(part, num);
	*/
	int i = 0;
	char* const parr = (char*)malloc(sizeof(char)*p_num);//result of p_part
	char* res = (char*)malloc(sizeof(char) * nemo_size);
	for (i = 0; i < nemo_size; i++) res[i] = 0;

	int* init = (int*)malloc(sizeof(int));//is first case??
	*init = TRUE;//in p_rec, comp for is first case...
	p_rec(p_num, 0, num, parr, org, nlist, res, init);//short of p_recusive:recursive part of p_part

	free(parr);
	free(init);
	return res;	//Please  free 'res' allocated memory
}
#endif