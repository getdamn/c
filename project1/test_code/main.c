#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Testing P-Partioning Algorithm

char* p_part(int p_num, int num)
{
	/*	INPUT	(int) p_num : Number to part, 
				(int) num : Number to be parted
		OUTPUT (char*) res : Pointer of result
		Des : Excute P-Partioning by Number to part and Number to parted.
		Ex) p_part(part, num);
	*/
	char* res = (char*)malloc(sizeof(char)*p_num);//result of p_part
	p_rec(p_num, 0, num, res);//short of p_recusive:recursive part of p_part
}

void p_rec(int part, int level, int num, char* res)
{
	/*	INPUT	(int) part : Number to part,
				(int) level : interger to count part number and an condition variable to exit,
				(int) num : Number to be parted,
				(int) res : Pointer of result
		OUTPUT	(void)
		Des: Excute Recursive part of P-Partitioning
		Ex) p_rec(part, 0, num, res);
	*/
	int i, sum, rep; //rep : the number to be repeated
	for(i = 0; i < level; i++) sum+= res[i];	//Calculate sum to caculate remain to be parted
	
	if(level == (num-1))	//if level reach last level
		prnt_arr(num, res);	//print result of p-part
	else if(level == 0)	//if level's status is initial(level == 0)
		rep = num + 1;	//rep is num+1 because first element of p-part can be 0 to num
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
