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

	node *current = calloc(1,sizeof(node));
	

	current->data = 7;
	current->link = NULL;
	head->link = current;
	
	current = (node*) calloc(1,sizeof(node));
	current->data = 20;
	current->link = NULL;
	
	head->link->link =current; //this is not working 
	
	
	printf("%d\n", head->data);
	printf("%d\n", current->data);
	
	
	
	return 0;
	
}
