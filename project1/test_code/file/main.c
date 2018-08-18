#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE* fp = ("test.txt", "rt");
	char buf[100];
	fgets(buf, 99, fp);
	fputs(buf, stdout);
	return 0;
}
