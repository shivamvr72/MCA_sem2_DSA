#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n *link;
}node;
node *head=NULL, *temp=NULL, *nextNode=NULL;

void create();
void push();
void pop();
void display();
void peep();

int main(){
	int ch,n;
	while(1){
		printf("Menu \n1.Push \n2.Pop \n3.Peep \n4.Display \n5.Exit \nSelect Operation : ");
		scanf("%d", &ch);
		switch(ch){
			case 1: push();break;
			case 2: pop();break;
			case 3: printf("Enter index : "); scanf("%d", &n); peep(n);break;
			case 4: display();break;
			case 5: exit(0);
			
			default: printf("\nenter correct operation\n");
		}
	}	
	return 0;
}

void create(){
	nextNode = (node*) malloc(sizeof(node));
	if(nextNode == NULL){
		printf("malloc failed\n");
	}
	printf("Enter Data : ");
	scanf("%d", &nextNode->data);
	nextNode->link = NULL;
}
void push(){
	create();
	nextNode->link = head;
	head = nextNode;
}

void pop(){
	if(head == NULL){
		printf("Empty\n");
	}
	temp = head;
	head = temp->link;
	free(temp);
	temp = NULL;
}
void peep(int item){
	if(head == NULL){
		printf("empty\n");
	}
	int cnt=1;
	temp = head;
	while(temp->link!=NULL && cnt<=item){
		cnt++;
		temp = temp->link;
	}
	printf("%d\n", temp->data);
	temp = NULL;
}
void display(){
	if(head == NULL){
		printf("stack list is empty\n");
		return;
	}
	temp = head;
		while(temp != NULL){
			//printf("|   |\n");
			printf("|_%d_|\n", temp->data);
			temp= temp->link;
		}
		printf("\n");
		temp = NULL;
}
