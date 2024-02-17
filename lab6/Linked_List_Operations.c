#include <stdio.h>
#include <stdlib.h>

//node creartion structe
typedef struct{
	int data;
	struct node *link;
}node;
//pointer variables
node *head=NULL, *newNode=NULL, *temp=NULL;
int countNode=0;
//create function s&t = O(1)
void create(){
	newNode = (node*)calloc(1,sizeof(node));
	if(newNode == NULL){
		printf("Insufficient Memory!\n");
		exit(0);
	}
	countNode++;
	newNode->link = NULL;
	printf("Enter Data of Node : ");
	scanf("%d", &newNode->data);
	
}
//insert at last time & space compexity  s&t = O(n)

//s&t = O(n)
void insertAtLast(){
	create();
	if(head == NULL){
		head = newNode;
		return;
	}
	temp = head;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link = newNode;
	temp = NULL;
}
//s&5 = O(1)
void insertAtFirst(){
	create();
	temp = head;
	newNode->link = temp;
	head = newNode;
	temp = NULL;
}

//inseting at any location s&t O(n)
void insertAtLocation(int index){
	if(head == NULL){
		printf("Linked List Is Empty\n");
		return;
	}else if(index > countNode){
		printf("Index Out of Range\n");
		return;
	}else if(index == 1){
		insertAtFirst();
		return;
	}
	temp = head;
	int cnt = 2;
	while(temp->link != NULL && cnt<=index-1){
		temp = temp->link;
		cnt++;
	}
	create();
	newNode->link = temp->link;
	temp->link = newNode;
	temp=NULL;
}

//delete from location s&t O(1)
void deleteFirst(){
	if(head == NULL){
		printf("Linked list is empty!\n");
		return 0;
	}
	temp = head;
	head = temp->link;
	free(temp);
	temp = NULL;
	countNode--;
}
//s&t O(n)
void deleteLast(){
	if(head == NULL){
		printf("Linked list is empty!\n");
		return 0;
	}
	temp = head;
	node *tempPre = head;
	while(temp->link!=NULL){
		tempPre = temp;
		temp = temp->link;
	}
	free(temp);
	tempPre->link = NULL;
	countNode--;
}

void deleteLocation(int index){
	int cnt = countNode;
	if(head==NULL){
		printf("Linked list is empty!\n");
		return;
	}else if(index > cnt){
		printf("Locations Exeeded!\n");
		return;
	}else if(index == 1){
		deleteFirst();
		return;
	}
	temp = head;
	node *temp2 = head;
	cnt = 2;
	if(temp->link!=NULL && index>=cnt){
		cnt++;
		temp2 = temp;
		temp = temp->link;
	}
	temp2->link=temp->link;
	free(temp);
	temp=NULL;
	countNode--;
}

//displaying s&t O(n)
void display(){
	node *temp;
	if(head==NULL){
		printf("Linked list is empty!\n");
		return;
	}
	temp = head;
	while(temp!=NULL){
		printf("[ %d ]->", temp->data);
		temp = temp->link;
	}
	printf("\n");
	temp = NULL;
}
int main(){
	int op = 0,n=0;
	while(1){
		printf("Linked list Size: %d \n", countNode);
		printf("enter : ");
		scanf("%d", &op);
		switch(op){
			case 1: insertAtFirst();break;
			case 2: insertAtLast();break;
			case 3: printf("loaction: ");scanf("%d", &n);insertAtLocation(n);break;
			case 4: deleteFirst();break;
			case 5: deleteLast();break;
			case 6: printf("loaction: ");scanf("%d", &n);deleteLocation(n);break;
			case 7: display();break;
			case 9: exit(0);
		}
		if(countNode == 0){
			head->data = NULL;		
			break;
		}
	}
	
	//printf("%d\n", head->data);
	return 0;
}
