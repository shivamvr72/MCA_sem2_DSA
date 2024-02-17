#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n *link;
}node;

int count = 0;
node *tail, *head, *newnode, *temp;

void create(){
	newnode = malloc(sizeof(node));
	if(newnode == NULL){
		printf("Failed...\n");
		exit(1);
	}
	newnode->link = NULL;
	printf("Enter Data: ");
	scanf("%d", &newnode->data);
	count++;
}
void insertFirst(){
	create();
	if(tail == NULL){
		head = tail = newnode;
		return;
	}

		newnode->link = head;
		head = newnode;
		tail->link = head;
		// tail = newnode;

	//tail->link = head;
}

void insertLast(){
	create();
	if(tail== NULL){
		head=tail=newnode;
		return;
	}else{
		tail->link = newnode;
		tail = newnode;
	}
	tail->link = head;
}
 void insertLocation(int idx){
	int cnt = count;
	if(idx > cnt || idx <= 0){
		printf("Index out of range\n");
		return;
	}else if(tail == NULL){
		printf("empty\n");
		return;
	}
	if(idx == 1){
		insertFirst();
		return;
	}
	create();
	temp = head; //tail->link
	node *temp2 = NULL;
	cnt = 1;
	do{	
		temp2 = temp;
		temp = temp->link;
		cnt++;
		//printf("cc %d\n", cnt);
	}while(temp != head && cnt<idx-1);
	
	newnode->link = temp->link;
	temp->link = newnode;
 }

void deleteFirst(){
	if(tail==NULL || count==0){
		printf("List is empty\n");
		exit(0);
	}
	temp = head; //tail->link;
	tail->link = head->link;
	head = head->link;
	free(temp);
	temp = NULL;
	count--;
	printf("deleled from front\n");
}
void deleteEnd(){
//	printf("cdb= %d\t", count);
	if(tail==NULL || count == 0){
		printf("link is empty\n");
		exit(0);
	}
	temp = head;
	node *pre = head;
	while(temp != tail){
		pre = temp;
		temp = temp->link;
	}
	tail = pre;
	tail->link = head;
	free(temp);
	temp = NULL;
	count--;
	printf("deleled from end\n");
//	printf("cda= %d\t", count);
}

void deleteLocation(int index){
	if(tail==NULL || count == 0){
		printf("link is empty\n");
		exit(0);
	}else if(count < index){
		printf("Index exceeds\n");
		return;
	}
	if(index == 1){
		deleteFirst();
		return;
	}else if(count == index){
		deleteEnd();
		return;
	}
	int cnt = 1;
	temp = head;
	node *ptr = head;
	do{
		ptr = temp;
		temp = temp->link;
		cnt++;
	}while(temp != tail && cnt<index);
	ptr->link = temp->link;
	free(temp);
	temp = NULL;
	count--;
	printf("deleled from index no %d\n", index);
}


void display(){
	if(tail==NULL || count == 0){
		printf("link is empty\n");
		exit(0);
	}
	printf("->");
	temp = tail->link;
	//printf("->");
	do{
		printf("[ %d ]->", temp->data);
		temp = temp->link;
	}while(temp!=tail->link);
	printf("\n");
}


int main(){
	int ch=0;
	int n=0;
	while(1){
	printf("Menu\n1.Insert First\n2.Insert End\n3.Insert Location\n4.Delete First\n5.Delete End\n6.Delete Location\n7.Display\n8.Exit\nselect: ");
	scanf("%d", &ch);
		switch(ch){
			case 1: insertFirst();break;
			case 2: insertLast();break;
			case 3: printf("enter index: "); scanf("%d", &n); insertLocation(n);break;
			case 4: deleteFirst();break;
			case 5: deleteEnd();break;
			case 6: printf("enter index: "); scanf("%d", &n); deleteLocation(n);break;
			case 7: display();break;
			case 8: exit(0); break;
			default : printf("invalid\n");
		}
	}
	
	
	//printf("%d", tail->data);
	return 0;
}
