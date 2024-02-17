#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20
//stack 
//int size; //size of stack
char stack[max];
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
	char poped = stack[top];
	if(isEmpty()){
		printf("Stack Undeflow\n");
		exit(1);
	}
	top--;
	stack[top];
	return poped;
}
void push(char data){
	if(isFull()){
		printf("Stack Overflow\n");
		exit(1);
	}
	top++;
	stack[top]=data;
}

int peek(){
	if(isEmpty()){
		printf("Stack underflow\n");
		exit(1);
	}
	return top;
}
void display(){
	if(isEmpty()){
		printf("Stack underflow\n");
		exit(1);
	}
	for(int i=top; i>=0; i--){
		printf("| %c |\n", *(stack+i));
	}
}

void change(int index, char data){
	if(isEmpty()){
		printf("Stack underflow\n");
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
	char found = stack[find_i];
	return found;
}

//finding out lenght of string
/*int len(char *s){
	int count=0;
	while(*s!='\0'){
		count++;
	}
	return count;
}*/
void reverseStr(char *str){
	int i=0;
	while(*(str+i)!='\0'){
		push(*(str+i));
		i++;
	}
	int j=0;
	while(isEmpty()!=1){
		*(str+j)=pop();
		j++;
	}
}

int main(){
	
	char string[max];
	printf("Enter A String to reverse: ");
	scanf("%[^\n]", string);
	
	
	
	//display();
	reverseStr(string);
//	change(3, 's');
//	display();
	printf("%s\n",string);
	return 0;
}
