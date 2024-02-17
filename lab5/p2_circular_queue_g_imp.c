#include <stdio.h>
#include "circular_queue_g.h"
#define max 5

int front=-1, rear=-1;
int q[max];
int main(){
	int n,ch;
	while(1){
		printf("Menu: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Terminate\n");
		printf("Select Option: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("\nEnqueue element : ");
					scanf("%d",&n);
					printf("\n");
					enqueue(&front, &rear, q, max, n);
					break;
			case 2: printf("\nDeleting...\n");
					n=dequeue(&front, &rear, max, q);
					printf("Deleted : %d\n\n", n);
					break;
			case 3: printf("\nDisplaying...\n");
					display(&front, &rear, max, q);
					printf("\n");
					break;
			case 4: printf("\nexit...\n");
					exit(1);
			default : printf("\nkindly select correct option\n\n");
		}	
	}
	return 0;
}
