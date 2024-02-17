#include <stdio.h>
//include <stdlib.h>
#import "stackg.h"
#define max 5
/*
int top=-1;
int stk[max];
*/

typedef struct {
	int top;
	int stk[max];
}stack;
//stack top = -1;

int main(){
	stack s1,s2;
	stack *ptr = &s1;
	ptr->top = -1;
	
	
//	pop(stk); checked
	printf("stack1\n");
	push(&s1.top , ptr->stk , max, 30);
	push(&s1.top, ptr->stk, max, 71);
	push(&s1.top, ptr->stk, max, 73);
	push(&s1.top, ptr->stk, max, 74);
	push(&s1.top, ptr->stk, max, 75);
//	push(&s1.top, ptr->stk, max, 73);		//checked
	
	display(&s1.top, ptr->stk);
	
	
	
	printf("stack2\n");
	ptr = &s2;
	ptr->top=-1;
		
	push(&s2.top, ptr->stk, max, 71);
	push(&s2.top, ptr->stk, max, 72);
	push(&s2.top, ptr->stk, max, 73);
	display(&s2.top, ptr->stk);
	printf("%d\n", pop(&s2.top, ptr->stk));
	printf("%d\n", peep(&s2.top, ptr->stk, 2));
	printf("%d\n", peek(&s2.top, ptr->stk));
	change(&s2.top, ptr->stk, 3, 74);
	display(&s2.top, ptr->stk);
	
	return 0;
}
