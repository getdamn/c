#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int p_rec(const int p_num, int level, const int num, char* const res)
{
	/*	INPUT	(int) p_num : Number to part,
	(int) level : interger to count part number and an condition variable to exit,
	(int) num : Number to be parted,
	(int) res : Pointer of result
	OUTPUT	(void)
	Des: Excute Recursive part of P-Partitioning
	Ex) p_rec(part, 0, num, res);
	*/
	int i, rep; //rep : the number to be repeated
	int sum = 0;
	for (i = 0; i < level; i++) sum += res[i];	//Calculate sum to caculate remain to be parted

	if (level == (p_num - 1))
	{	//if level reach last level
		res[level] = num - sum;
		
		prnt_arr(p_num, res);	//print result of p-part
		return 0;	//when the last level ends, returns 0
	}
	else if (level == 0)	//if level's status is initial(level == 0)
		rep = num + 1;	//rep is num+1 because first element of p-part can be 0 to num
	else
		rep = num - sum + 1;

	for (i = 0; i < rep; i++)
	{
		res[level] = i; //Input a number of occasion
		p_rec(p_num, level + 1, num, res);
	}
	return 0;	//when a level ends, returns 0
}
char* p_part(const int p_num, const int num)
{
	/*	INPUT	(int) p_num : Number to part,
	(int) num : Number to be parted
	OUTPUT (char*) res : Pointer of result
	Des : Excute P-Partioning by Number to part and Number to parted.
	Ex) p_part(part, num);
	*/
	char* const res = (char*)malloc(sizeof(char)*p_num);//result of p_part
	p_rec(p_num, 0, num, res);//short of p_recusive:recursive part of p_part
	return res;	//Please free allocated memory
}

int main(int argc, char *argv[]) {
	
	system("PAUSE");
	return 0;
}