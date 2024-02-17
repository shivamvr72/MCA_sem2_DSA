#include <stdio.h>
#include <stdlib.h>

int isFullQ(int *rear, int size){
	if(*rear == size-1)
		return 1;
	return 0;
}
int isEmptyQ(int *front, int *rear){
	if(*front == *rear+1 || *front == -1)
		return 1;
	return 0;
}
void enqueue(int *front, int *rear, int size, int *queue, int data){
	//printf("eq\n");
	if(isFullQ(rear, size)){
		printf("Overflow...\n");
		exit(1);
	}
	if(*front == -1)
		*front = 0;
	*rear+=1;	
	queue[*rear] = data;
}
int dequeue(int *front, int *rear, int *queue){
	//printf("dq\n");
	if(isEmptyQ(front, rear)){
		printf("Underflow...\n");
		exit(1);
	}
	if(*front == *rear){
		*front=*rear=-1;
	}
	int dq = queue[*front];
	*front+=1;
	return dq;
}
void displayQ(int *front, int *rear, int *queue){
	if(isEmptyQ(front, rear)){
		printf("Underflow...\n");
		exit(1);
	}
	for(int i=*front; i<=*rear; i++){
		printf("| %d ", queue[i]);
	}
	printf("|\n\n");
}



