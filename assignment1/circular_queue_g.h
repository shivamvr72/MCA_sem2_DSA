#include <stdio.h>
#include <stdlib.h>

int isFull(int *front, int *rear, int size){
	if(*front==0 && *rear==size-1 || *front == *rear+1)
		return 1;
	return 0;
}
int isEmpty(int *front){
	if(*front == -1)
		return 1;
	return 0;
}
void enqueue(int *front, int *rear, int *Q, int size, int data){
	if(isFull(front, rear, size)){
		printf("Overflow\n");
		exit(1);
	}
	if(*front == -1)
		*front = 0;
	if(*rear == size-1)
		*rear = -1;
	*rear+=1;
	Q[*rear] = data;
}
int dequeue(int *front, int *rear, int size, int *Q){
	if(isEmpty(front)){
		printf("undeflow\n");
		exit(1);
	}
	int dq = Q[*front];
	if(*front == *rear){
		*front=*rear=-1;
	}else if(*front == size-1){
		*front = 0;
	}
	*front+=1;
	return dq;
}
void display(int *front, int *rear, int size, int *Q){
	if(isEmpty(front)){
		printf("undeflow\n");
		exit(1);
	}
	if(*front<*rear){
		for(int i=*front; i<=*rear ; i++){
			printf("| %d ", Q[i]);
		}
		//printf("\n");
	}else if(*front>*rear){
		for(int i=*front; i<size; i++){
			printf("| %d ", Q[i]);
		}
		for(int i=0; i<=*rear; i++){
			printf("| %d ", Q[i]);
		}
	}
	
	printf("|\n");
}
