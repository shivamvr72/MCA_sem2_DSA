#include <stdio.h>
#include "stackg.h"
#define max 5



int main(){
	int s1in[max], s1top=-1, s2temp[max], s2top=-1;
	while(i>0){
		printf("Push a Element : ");
		scanf("%d", &p);
		push(s1top, s1in, max, p);
		i--;
	}
	
	int temp, k;
	
	while(!isEmpty(&s1top)){ //till s1 is empty
		temp = pop(&s1top, s1in); //pop an element
		k = peek(&s2top, s2temp);
			while(!isEmpty(&s2top) && temp < peek){
				int x=
				push();
				pop(&ps2->top, ps2->stk);
			}
			push(&ps2->top, ps2->stk, max, k);
	}
	while(!isEmpty(&ps2->top)){
		peek(&ps2->top, ps2->stk);
		pop(&ps2->top, ps2->stk);
	}
	
	display(&ptr->top, ptr->stk);
	display(&ps2->top, ps2->stk);	
	return 0;
}














	/*while(!isEmpty(&ptr->top)){
		temp = pop(&ptr->top, ptr->stk);
		if(!isEmpty(&ps2->top)){
			int y = peek(&ps2->top, ps2->stk);
			if(temp>y){
				push(&ps2->top, ps2->stk, max, temp);
			}else{
				while(!isEmpty(&ps2->top)&&temp>y){
					y = pop(&ps2->top, ps2->stk);
					push(&ptr->top, ptr->stk, max, y);
				}
				if(isEmpty(&ps2->top)){
					push(&ps2->top, ps2->stk, max, temp);
				}
			}
		}else{
			push(&ps2->top, ps2->stk, max, temp);
		}
		
		
	} */











	//display(&ptr->top, ptr->stk);
	
	
	/*int x, temp = pop(&ptr->top, ptr->stk);
	while(*(&ptr->top)>=0){
		x = pop(&ptr->top, ptr->stk);
		push(&ps2->top, ps2->stk, max, x);
		printf("\n");
		if(temp>x){
			printf("tl : %d\n", temp);
			push(&ps2->top, ps2->stk, max, temp);
			display(&ps2->top, ps2->stk);
			temp=x;
		}else if(temp<x){
			printf("tm: %d\n", temp);
			push(&ptr->top, ptr->stk, max, x);
			display(&ptr->top, ptr->stk);
			temp=x;
		}
	}
	
	display(&ptr->top, ptr->stk);
	//display(&ps2->top, ps2->stk);
	
	*/
