#include <stdio.h>
int main(){
	int a = 10;
	int *p = &a;
	int **p1 = &p;
	int ***p2 = &p1;
	int ****p3 = &p2;
	int *****p4 = &p3;
	printf("%d\n", *****p4);
	return 0;
}
