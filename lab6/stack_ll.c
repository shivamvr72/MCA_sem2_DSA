#include <stdio.h>
#include <stdlib.h>

//node 
typedef struct{
	char data;
	struct node *link;
}node;

//node pointers
node *top=NULL, *temp=NULL, *newNode=NULL,*topr=NULL;

void create(){
	newNode = (node*) calloc(1,sizeof(node));
	if(newNode == NULL){
		printf("memory insuffiecient\n");
		exit(1);
	}
	
}
void push(){
	create();
	newNode->link = NULL;
	printf("Enter Data For Node in char : ");
	scanf(" %c", &newNode->data);
	
	temp = top;
	newNode->link = top;
	top = newNode;
	temp = NULL;
}
node *rnode = NULL;
node *pop(){
	if(top==NULL){
		printf("list is empty\n");
	}else{
		rnode = top;
		top = top->link;
		temp = NULL;
	}
	return rnode;
}
void display(){
	temp = top;
	while(temp!=NULL){
		printf("|[ %c ]->|\n", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

/*
//just need to work on this
void pushr(char rs){
	printf("c\n");
	create();
	newNode->link = NULL;
	newNode->data = rs;
	
//	if(top == NULL){
	//	top = newNode;
		//return;
	//}
	temp = top;
	newNode->link = top;
	top = newNode;
	temp = NULL;
	
}
void reverse(){
	node *rs=NULL;
	temp = top;
	while(temp->data){
		rs = pop();
		pushr(rs->data);
		temp = temp->link;
	}
}
*/
int main(){
	int op;
	while(1){
		printf("Menu Stack Implemeted using Linked List \n1.push\n2.pop\n3.display\nSelect : ");
		scanf("%d", &op);
		node *p;
		switch(op){
			case 1: push();break;
			case 2: p = pop(); printf("%c\n", p->data); break;
			case 3: display();break;
			//case 4: reverse();break;
			default: printf("select appropriate option");
		}
	}
	return 0;
}
