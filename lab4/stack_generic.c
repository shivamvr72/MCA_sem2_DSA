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
/*int pop(int *top, void *stack, int choice){
	switch(choice){
		case 1:	
				int popped =  stack[*top];
				if(isEmpty(top)){
					printf("Stack Underflow\n");
					return;
				}
				*top-=1;
				stack[*top];
				return popped;
		case 2: char popped = (char*)stack[*top];
				if(isEmpty(top)){
					printf("Stack Underflow\n");
					return;
				}
				*top-=1;
				stack[*top];
				return popped;
}*/
void push(int *top, void *stack, int size, void *data, int choice){
	if(isFull(top, size)){
		printf("Stack Overflow\n");
		return;
	}
	*top+=1;
	switch(choice){
		case 1: int *stk = (int*) stack;
				*(stk+top) = *data;
				break;
		case 2: (char*) stack[*top]=(char*) data;
				break;
}

/*int peek(int *top, void *stack, int choice){
	switch(choice){
		case 1:
			(int*) stack;
			if(isEmpty(top)){
			printf("Stack Underflow\n");
			return;
			}
			return *top;
		case 2:
			(char*) stack;
			if(isEmpty(top)){
			printf("Stack Underflow\n");
			return;
			}
			return *top;
}
void display(int *top, void *stack){
	if(isEmpty(top)){
		printf("Stack Underflow\n");
		return;
	}
	switch(choice){
			case 1:
				for(int i=*top; i>=0; i--){
				printf("| %d |\n", *(stack+i));
				break;
			case 2:
				for(int i=*top; i>=0; i--){
				printf("| %c |\n", *(stack+i));
				break;
	}
}

void change(int *top, void *stack, int index, void data, int choice){
		if(isEmpty(top)){
			printf("Stack Underflow\n");
			return;
		}
		switch(choice){
			case 1: (int*) stack[(index]=(int*)data; break;
			case 2: (char*) stack[index]=(char*)data; break;
		}
}

int peep(int *top, void *stack, void *find_i, int choice){
	switch(choice){
			 if(isEmpty(top)){
				printf("Stack Underflow\n");
				return;
				}
			case 1:	int found = (int*) stack[(int*)find_i];
					return found;
					break;
			case 2: char found = (char*) stack[(char*) find_i];
					return found;
					break;
	}
}*/
		

