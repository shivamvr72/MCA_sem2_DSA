#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node *link;
}node;

int main(){
	node *head=NULL;
	head = (node*) calloc(1,sizeof(node));
	
	
	head->data = 30;
	head->link = NULL;
	node *temp = head;

	head = (node*) calloc(1,sizeof(node));
	

	head->data = 7;
	head->link = NULL;
	temp->link= head; 
	
	printf("%d\n", head->data);
	printf("%d\n", temp->data);
	
	
	
	return 0;
	
}
