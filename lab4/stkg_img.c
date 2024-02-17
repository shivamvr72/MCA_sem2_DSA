#include <stdio.h>
#include "stack_generic.c"

int main(){
	int stk[5];
	int top = -1;
	int data = 10;

	push(&top, stk, 5, &data, 1);
	//pop(&top, stk, 1);
	return 0;
}
