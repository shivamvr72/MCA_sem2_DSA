#include <stdio.h>
#include <stdlib.h>
#define max 5

//top varible for top of the stack
int top=-1;
//stack array
int stack[max];

//check stack overflow
int isFull(){
	if(top == max-1)
		return 1;
	return 0;
}
//check undeflow
int isEmpty(){
	if(top == -1)
		return 1;
	return 0;
}
//push opration
int push(int data){
	//overflow check
	if(isFull()){
		printf("Stack Overflow\n");
		exit(1);
	}
	//increment the element
	top++;
	stack[top] = data;
}
//pop operation
int pop(){
	if(isEmpty()){
		printf("stack undeflow\n");
		exit(1);
	}
	int dvalue = stack[top];
	top--;
	return dvalue;
}

//peek of top
int peek(){
	return top;
}
//change: not standar stack operation
int change(int i, int data){
	if(isFull()){
		printf("Stack Overflow\n");
		exit(1);
	}
	stack[i] = data;
}

//peep not standar stack operation extracting data on particular location
int peep(int i){
	if(i<=0 || i>max){
		printf("Index is out of range\n");
		//exit(1);
	}
	return stack[i];
}

//print function for stack as display
int i=0;
int display(){
	while(top != -1){
		printf("|%d|\n", pop());
		i++;
	}
}

int main(){
	push(30);
	push(7);
	push(9);
	push(8);
	for(int i=0; i<=top; i++){
		printf("s: %d\n", stack[i]);
	}
//	change(2, 71);
//	int x = pop();
//	x=pop();
//	pop();	
//	printf("%d\n", x);
	for(int i=0; i<top; i++){
		printf("%d\n", stack[i]);
	}
//	printf("%d\n", peep(10));
	printf("%d\n", peek());
	display();
	return 0;
}
