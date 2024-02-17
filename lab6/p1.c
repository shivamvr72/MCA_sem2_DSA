#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n *link;
}node;

node *head=NULL, *temp=NULL, *newNode=NULL;

void create();
void insert_at_first();
void insert_at_end();
void insert_at_location(int loc);
void delete_from_first();
void delete_from_end();
void delete_from_location(int loc);
void display();
int count();


int main(){
	int ch=0,n;
	while(1){
		printf("Menu: \n1.Insert At First\n2.Insert At End\n3.Insert At Location\n4.Delete from First\n5.Delete From End\n6.Delete From Location\n7.Display\n8.Exit\n");
		printf("Enter Operation : ");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert_at_first();
					break;
			case 2: insert_at_end();
					break;
			case 3: printf("Enter Location to enter element: ");
					scanf("%d", &n);
					insert_at_location(n);
					break;
			case 4: delete_from_first();
					break;
			case 5: delete_from_end();
					break;
			case 6: printf("Enter Location to delete element: ");
					scanf("%d", &n);
					delete_from_location(n);
					break;
			case 7: display();
					break;
			case 8: exit(0);
			default:
				printf("\nEnter Correct option\n");
		
		}
	}
		return 0;	
}

//O(n)
void create(){
	
	newNode = (node*) calloc(1,sizeof(node));
	if(newNode == NULL){
		printf("Calloc Failed...\n");
		exit(0);
	}
	
	newNode->link = NULL;
	printf("Enter Element : ");
	scanf("%d", &newNode->data);
	
}

// s&t O(1)
void insert_at_first(){
	create();
	/*if(head==NULL){
		head = newNode;
		return;
	}*/
	newNode->link = head;
//	printf("link = %d\n", head->link);
	//printf("head =%d\n", head);
	head = newNode;
}

//s&n O(n)
void insert_at_end(){
	create();
	if(head==NULL){
		head = newNode;
		return;
	}
	temp = head;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link = newNode;
	
	temp=NULL;
}
//s&n O(n)
void insert_at_location(int loc){
	int cnt = count();
	if(head == NULL){
		printf("List is Empty\n");
		return;
	}else if(loc > cnt){
		printf("Enter Location is exeeeds list \n");
		return;
	}else if(loc == 1){
		insert_at_first();
	}else{
		cnt=2;
		temp = head;
		while(temp->link!= NULL && cnt<=loc){
			cnt++;		
			temp = temp->link;
		}
		create();
		newNode->link = temp->link;
		temp->link = newNode;
		temp = NULL;
		
	}
}
//s&t O(1)
void delete_from_first(){
	if(head==NULL){
		printf("List is Empty\n");
		exit(1);
	}
	temp = head;
	head = head->link;
	free(temp);
}
//s&t O(1) & O(n)
void delete_from_end(){
	if(head==NULL){
		printf("list is Empty\n");
		exit(1);
	}
	temp = head;
	node *ptr = head;
	while(temp->link!=NULL){
		ptr = temp;
		temp = temp->link;
	}
	ptr->link = NULL;
	free(temp);
	temp = NULL;
}
//s&t O(n) or O(n^2);
void delete_from_location(int loc){
	int cnt = count();
	if(head==NULL){
		printf("List is Empty\n");
		return;
	}else if(loc>cnt){
		printf("Entered location exeeds list");
		return;
	}else if(loc == 1){
		delete_from_first();
	}else{
		temp=head;
		node *ptr = head;
		cnt =2;
		while(temp->link != NULL && cnt<=loc){
			ptr = temp;
			temp = temp->link;
			cnt++;
		}
		
		ptr->link = temp->link;
		free(temp);
		temp=NULL;
	
	}
	
}
//t O(n)
void display(){
		node *temp;
		if(head==NULL){
			printf("Empty list\n");
			exit(1);
		}
		temp = head;
		while(temp!=NULL){
			printf("%d -> ", temp->data);
			temp = temp->link;
		}
		printf("\n");
		temp = NULL;
}
//t O(n)
int count(){
	int cnt=0;
	node *ptr = head;
	while(ptr->link != NULL){
		ptr=ptr->link;
		cnt++;
	}
	ptr = NULL;
	return cnt;
}








