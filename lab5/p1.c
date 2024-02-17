#include <stdio.h>
#include <stdlib.h>
#define max 10

int front=-1,rear=-1;
int q[max];

int isFull(){
	if(rear==max-1)
		return 1;
	return 0;
}
int isEmpty(){
	if(front == -1 || front>rear)
		return 1;
	return 0;
}
void enqueue(int data){
	if(isFull()){
		printf("Queue overflow\n");
		exit(1);
	}	
	if(front == -1){
		front+=1;
	}
	rear+=1;
	q[rear]=data;
		
}

int dequeue(){
	int dq = q[front];
	if(isEmpty()){
		printf("Queue underflow\n");
		exit(1);
	}
	if(front == rear){
		front=rear=-1;
	}
	
	front+=1;
	return dq;
}

void display(){
	if(isEmpty()){
		printf("Queue underflow\n");
		exit(1);
	}
//	printf("d%d\n", front);
	for(int i=front; i<=rear ; i++){
		printf("|%d", q[i]);
	}
	printf("|\n");
}

int main(){
	/*
	enqueue(4);
	enqueue(9);
	display();
	printf("dq = %d\n",dequeue());		
	enqueue(7);
	enqueue(2);
	enqueue(5);
	enqueue(9);
	display();
	printf("dq = %d\n",dequeue());	
	enqueue(3);
	enqueue(9);
	display();
	//printf("dq = %d\n",dequeue());
	*/
	// Queue operations 
	int ch,n;
	while(1){
		printf("Menu: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Terminate\n");
		printf("Select Option: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("\nEnqueue : ");
					scanf("%d",&n);
					enqueue(n);
					break;
			case 2: printf("\nDeleting...\n");
					n = dequeue();
					printf("%d\n", n);
					break;
			case 3: printf("\nDisplaying...\n");
					display();
					break;
			case 4: printf("\nexit...\n");
					exit(1);
			default : printf("\nkindly select correct option\n");
		}	
	}
	return 0;
}
