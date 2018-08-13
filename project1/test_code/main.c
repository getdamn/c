#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Testing P-Partioning Algorithm

char* p_part(int part, int num)
{
	/*	INPUT (int) part : Number to part, (int) num : Number to parted 
		OUTPUT (char*) res : Pointer of result
		Des : Excute P-Partioning by Number to part and Number to parted.
		Ex) p_part(part, num);
	*/
	char* res = (char*)malloc(sizeof(char)*n);//result of p_part
	p_rec(part, 0, num, res);//short of p_recusive:recursive part of p_part
}

void p_rec(int part, int level, int num, char* res)
{
	/*	INPUT	(int) part : Same of p_part's meaning,
				(int) level : interger to count part number and an condition variable to exit,
				(int) num : Same of p_part's meaning,
				(int) res : Same of p_part's meaning
		OUTPUT	(void)
		Des: Excute Recursive part of P-Partitioning
		Ex) p_rec(part, 0, num, res);
	*/
	int i, sum, rep;
	for(i = 0; i < layer; i++) sum+= res[i];
	
	if(layer == (num-1))
		prnt_arr(num, res);
	else if(layer == 0)
		rep = num + 1;
	else
		rep = num - sum + 1;
		
	for(i = 0; i < rep; i++)
	{
		p_rec(part, layer+1, num, res);
	}
}
void prnt_arr(int len, char* arr)
{
	int i = 0;
	for(i = 0; i<len; i++)
		printf("%d",arr[i]);
	printf("\n")
}
int main(int argc, char *argv[]) {
	
	fct(0);
	return 0;
}
