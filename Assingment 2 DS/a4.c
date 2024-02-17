#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node *head=NULL,*newnode=NULL;

void insertlast(int value){
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
	newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }else{
        node *temp = head;
        while(temp->next!=NULL){
        temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(){
		node *temp=head;
		
		while(temp!=NULL){
		 printf("%d-->",temp->data);
		 temp = temp->next;
		} 
		printf("\n");	
}

void displaymiddle(){
    node *count1,*count2;
    count1 = head;
    count2 = head;

    while(count2!=NULL && count2->next!=NULL){
        count2 = count2->next->next;
        count1=count1->next;
    }
    printf("Middle One Is %d",count1->data);
}

int main(int argc, char* argv[]){
    int count = 0;
    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 1; i < argc; i++){
        count++;
        printf("%d\n", atoi(argv[i]));
        insertlast(atoi(argv[i]));
    }
    printf("\n%d\n",count);
    display();
    displaymiddle();
    return 0;
}
