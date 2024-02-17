#include <stdio.h>

//pass by value
void swap1(int x, int y){
	int t;
	t=x;
	x=y;
	y=t;
}
void swap2(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
}
int main(){
	int a=30, b=7;
	printf("before : %d %d \n", a,b);
	swap1(a,b);
	printf("swap1 : %d %d \n", a,b);
	swap2(&a,&b);
	printf("swap2 : %d %d \n", a,b);
	return 0;
}
