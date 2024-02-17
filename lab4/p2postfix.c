#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack_char.h"
	typedef struct{
		char stk[50];
		int top;
	}stack;
	
int main(){

	int x,y;
	stack s1, s2;
	stack *sptr, *osptr;
	sptr = &s1;
	sptr->top = -1;
	
	
	char px[50],xc,yc;
	
	char *ptrpx = px;
	printf("enter expression : ");
	scanf("%s", px);
	
	int len = strlen(px);
//	push(&sptr->top, sptr->stk, len, '(');
	for(int i=0; i<len ; i++){
		if(isdigit(*(i+ptrpx))){
			push(&sptr->top, sptr->stk, len, *(i+ptrpx));
		}
		else{
			char c = *(i+ptrpx);
			xc = pop(&sptr->top, sptr->stk);
			x = xc - '0';
			yc = pop(&sptr->top, sptr->stk);
			y = yc - '0'; 
			//printf("y=%d\n",y);
			//printf("x=%d\n",x);
			switch(c){
				case '+':
						//printf("+");
						push(&sptr->top, sptr->stk, len, (y+x)+'0');
						//display(&s1.top, s1.stk);
						break;
				case '-':
						//printf("-");
						push(&sptr->top, sptr->stk, len, (y-x)+'0');
						break;
				case '*':
						//printf("*");
						push(&sptr->top, sptr->stk, len, (y*x)+'0');
						break;
				case '/':
						//printf("/");
						push(&sptr->top, sptr->stk, len, (y/x)+'0');
						break;
				case '%':
						//printf("/");
						push(&sptr->top, sptr->stk, len, (y%x)+'0');
						break;
				default : 
						printf("Invalid Postfix!\n");
			}
		}
	}
	
	display(&sptr->top, sptr->stk);
	
	return 0;
}
