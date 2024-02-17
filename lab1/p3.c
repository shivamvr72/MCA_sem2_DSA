#include <stdio.h>
int main(){
	int n=30;
	int *ptr1 = &n;
	int *ptr2 = ptr1;
	printf("values: \nn=%d, *ptr1%d, *ptr1=%d\n", n, *ptr1, *ptr2); 
	printf("address \n&n=%p, &ptr1= %p, &ptr1=%p\n", &n, &ptr1, &ptr2);
	return 0;
}
