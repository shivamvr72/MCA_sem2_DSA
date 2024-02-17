#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct node *link;
}node;

int main(){
	node *head = NULL;
	head = (node*) calloc(1,sizeof(node)); //casting is optional but its good do it
	
	head->data = 10;
	head->link = NULL;
	
	
	printf("[%d|NULL]->\n", head->data);
	
	return 0;
}
