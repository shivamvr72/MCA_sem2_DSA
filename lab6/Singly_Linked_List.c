#include <stdio.h>
#include <stdlib.h>

//node 
typedef struct{
	char data;
	struct node *link;
}node;

//node pointers
node *top=NULL, *temp=NULL, *newNode=NULL;

void create(){
	newNode = (node*) calloc(1,sizeof(node));
	if(newNode == NULL){
		printf("memory insuffiecient\n");
		exit(1);
	}
	newNode->link = NULL;
	printf("Enter Data For Node in char : ");
	scanf(" %c", &newNode->data);
}
void push(){
	create();
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
int main(){
	int op;
	node *p;
	while(1){
		printf("Menu Stack Implementation using Linked List: \n1.PUSH \n2.POP \n3.Display\nSelect : ");
		scanf("%d", &op);

		switch(op){
			case 1: push();break;
			case 2: p=pop; printf("%d\n", p->data); break;
			case 3: display();
			default : printf("Select approprite choice \n");
		}

		return 0;
}
