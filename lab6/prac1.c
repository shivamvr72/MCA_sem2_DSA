#include <stdio.h>
#include <stdlib.h>



typedef struct{
	int data;
	struct node *link;
}node;

//next node function
node *nextNode(int data, node *nextNode){
	node *temp = (node*)calloc(1,sizeof(node));
	if(temp==NULL){
		exit(1);
	}
	temp->data = data;
	temp->link = NULL;
	
	nextNode->link = temp;
	return temp;	
};

int main(){

	
//	node *head = nextNode(30, nextNode(7, nextNode(2,NULL)));
	node *head = malloc(sizeof(node));
	head->data = 40;
	head->link = NULL;
	
	node *ptr = head;
	
	ptr = nextNode(7, ptr);
	ptr = nextNode(30, ptr);
	ptr = nextNode(40, ptr);
	ptr = nextNode(50, ptr);
	
	ptr=head;
	
	while(ptr!=NULL){
		printf("%d\t", ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	
	
	
	

	return 0;
}
