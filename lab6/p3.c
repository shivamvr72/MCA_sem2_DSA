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
void sort_insert();
void delete_from_first();
void delete_from_end();
void delete_from_location(int loc);
void display();
int count();
void sort();


int main(){
	int ch=0,n;
	while(1){
		printf("Menu: \n1.Insert At First\n2.Insert At End\n3.Insert At Location\n4.Delete from First\n5.Delete From End\n6.Delete From Location\n7.Sort Insert\n8.Sort\n9.Display\n0.Exit\n");
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
			case 7: sort_insert();
					break;
			case 8: sort();
					break;
			case 9: display();
					break;
			case 0: exit(0);
			default:
				printf("\nEnter Correct option\n");
		
		}
	}
		return 0;	
}

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

void delete_from_first(){
	if(head==NULL){
		printf("List is Empty\n");
		exit(1);
	}
	temp = head;
	head = head->link;
	free(temp);
}

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

void sort_insert(){
	create();
	temp = head;
	node *temp2 = head;
	if(newNode->data <= temp->data){
		newNode->link = head;
		head = newNode;
		temp = NULL;
		return;
	}
	while(temp->link!=NULL && newNode->data > temp->data){
		temp2 = temp;
		temp = temp->link;
	}
	if(newNode->data > temp->data){
		temp->link = newNode;
		temp2= temp = NULL;
		return;
	}
	newNode->link = temp2->link;
	temp2->link = newNode;
	
	temp = temp2 = NULL;
}


void sort(){
	if(head == NULL){
		printf("empty list \n");
		return;
	}	
	temp = head;
	node *pre;
	int t;
	while(temp->link != NULL){
		pre = temp;
		temp = temp->link;
	}
	if(temp->data < pre->data){
		t = temp->data;
		temp->data = pre->data;
		pre->data = t;
	}
	display();
}



