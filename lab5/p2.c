#include <stdio.h>
#include <stdlib.h>
#define max 3


int front=-1, rear=-1;
int q[max];

int isfull(){
	if(front==rear+1 || front==0 && rear==max-1)
		return 1;
	return 0;
}
int isEmpty(){
	if(front == -1)
		return 1;
	return 0;
}
void enQ(int data){
	if(isfull()){
		printf("Queue Overflow\n");
		exit(1);
	}
	if(front == -1)
		front = 0;
	if(rear == max-1)
		rear = -1;
	rear+=1;
	q[rear]=data;
}
int dQ(){
	if(isEmpty()){
		printf("Queue Underflow\n");
		exit(1);
	}
	int dq = q[front];
	
	if(front == rear){
		front=rear=-1;
	}else if(front == max-1){
		front = 0;
	}
	front+=1;
	return dq;
}
void display(){
	if(isEmpty()){
		printf("Queue underflow\n");
		exit(1);
	}
	if(front < rear){
		//printf("f<r\n");
		for(int i=front; i<=rear; i++){
			printf("|%d", q[i]);
		}
		//printf("|\n");
	}else if(front > rear){
		//int t = max;
		for(int i=front; i<max; i++){
			printf("|%d", q[i]);
		}
		for(int i=0; i<=rear; i++){
			printf("|%d", q[i]);
		}
	}
		printf("|\n");
}


int main(){
	printf("f=%d, d=%d\n",front, rear);
	enQ(10);
	printf("f=%d, d=%d\n",front, rear);
	enQ(20);
	enQ(30);
	display();
	printf("f=%d, d=%d\n",front, rear);
	printf("dq=%d\n",dQ());
	printf("dq=%d\n",dQ());
	printf("f=%d, d=%d\n",front, rear);
	display();
	enQ(40);
	printf("f=%d, d=%d\n",front, rear);
	//enQ(50);
	display();
	for(int i=0; i<=max-1; i++){
			printf("%d\t", q[i]);
		}
		printf("\n");
	//printf("eq=%d\n",q[0]);
	//printf("dq=%d\n",dQ());
	//printf("dq=%d\n",dQ());
	return 0;
}
