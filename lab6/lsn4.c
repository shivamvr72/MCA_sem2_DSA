#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct node *link;
}node;

void insert_End(node *head, int *idata){
	node *temp = head;
	
	head = malloc(sizeof(node));
	if(head == NULL){
		printf("malloc failed\n");
	}{
		head->data = *idata;
		head->link = NULL;
		while(temp->link != NULL){
			temp = temp->link;
		}
		temp->link = head;
		printf("%d\n", temp->data);
	}
	
} 

int main(){
	int data;
	
	printf("enter data : ");
	scanf("%d", &data);
	node *head;
	head = malloc(sizeof(node));
	
	
	if(head == NULL){
		printf("malloc failed\n");
		exit(1);
	}
	insert_End(head, &data);
	printf("%d", head->data);
	
	
	
	

	
	return 0;
}
