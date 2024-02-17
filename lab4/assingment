#include <stdio.h>
#include <stdlib.h>


//stack operatons 
//int top=-1; //top stack varible
int isEmpty(int *top){
	if(*top == -1)
		return 1;
	return 0;
}
int isFull(int *top, int max){
	if(*top == max-1)
		return 1;
	return 0;
}
int pop(int *top, int *stack){
	int poped = stack[*top];
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	*top-=1;
	stack[*top];
	return poped;
}
void push(int *top, int *stack, int size, int data){
	if(isFull(top, size)){
		printf("Stack Overflow\n");
		exit(1);
	}
	*top+=1;
	stack[*top]=data;
}

int peek(int *top, int *stack){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	return *top;
}
void display(int *top, int *stack){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	for(int i=*top; i>=0; i--){
		printf("| %d |\n", *(stack+i));
	}
}

void change(int *top, int *stack, int index, int data){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	stack[index]=data;
}

int peep(int *top, int *stack, int find_i){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	int found = stack[find_i];
	return found;
}

