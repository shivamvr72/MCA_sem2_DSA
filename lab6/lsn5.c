#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int data;
	struct node *link;
}node;

int insertAtEnd(node *ptr, int data){
	
	node *temp;
	temp = (node*)malloc(sizeof(node));
	
	temp->data = data;
	temp->link = NULL;
	
	ptr->link = temp;
	
	return temp;
	
	
}


int main(){
	
	node *head;
	head = malloc(sizeof(node));
	
	head->data = 30;
	head->link = NULL;
	
	node *ptr = head;
	
	insertAtEnd(&ptr, 
	
	
	
	return 0;
}
