#include <stdio.h>
#include <stdlib.h>
#define max 5
//stack 
int size; //size of stack
int stack[max];
int top=-1; //top stack varible

//stack operatons 
int isEmpty(){
	if(top == -1)
		return 1;
	return 0;
}
int isFull(){
	if(top == max-1)
		return 1;
	return 0;
}
int pop(){
	int poped = stack[top];
	if(isEmpty()){
		printf("Stack Undeflow\n");
		exit(1);
	}
	top--;
	stack[top];
	return poped;
}
void push(int data){
	if(isFull()){
		printf("Stack Overflow\n");
		exit(1);
	}
	top++;
	stack[top]=data;
}

int peek(){
	if(isEmpty()){
		printf("Stack Overflow\n");
		exit(1);
	}else if(isFull()){
		printf("Stack Underflow\n");
		exit(1);
	}
	return top;
}
void display(){
	if(isEmpty()){
		printf("Stack Overflow\n");
		exit(1);
	}else if(isFull()){
		printf("Stack Underflow\n");
		exit(1);
	}
	for(int i=top; i>=0; i--){
		printf("| %d |\n", *(stack+i));
	}
}

void change(int index, int data){
	if(isEmpty()){
		printf("Stack Overflow\n");
		exit(1);
	}else if(isFull()){
		printf("Stack Underflow\n");
		exit(1);
	}
	stack[index]=data;
}

int peep(int find_i){
	if(isEmpty()){
		printf("Stack Overflow\n");
		exit(1);
	}else if(isFull()){
		printf("Stack Underflow\n");
		exit(1);
	}
	int found = stack[find_i];
	return found;
}


int main(){
	
	//printf("Enter The Size Of Stack : ");
//	scanf("%d", &size);
	push(30);
	push(87);
	push(72);
	push(71);
	display();
	printf("%d\n", pop());
	change(1, 78);
	display();
	printf("%d\n", peek());
	printf("%d\n",peep(1));
	
	return 0;
}
