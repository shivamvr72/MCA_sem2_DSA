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
int pop(int *top, char *stack){
	char popped = stack[*top];
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	*top-=1;
	//stack[*top];
	return popped;
}
void push(int *top, char *stack, int size, char data){
	if(isFull(top, size)){
		printf("Stack Overflow\n");
		exit(1);
	}
	*top+=1;
	stack[*top]=data;
}

int peek(int *top, char *stack){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	return *top;
}
void display(int *top, char *stack){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	for(int i=*top; i>=0; i--){
		printf("| %d |\n", *(stack+i)-'0');
	}
}

void change(int *top, char *stack, int index, char data){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	stack[index]=data;
}

int peep(int *top, char *stack, char find_i){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		exit(1);
	}
	char found = stack[find_i];
	return found;
}

