#include <stdio.h>
#include  "simple_queue_g.h"
#define max 10
int q[max];
int front=-1,rear=-1;

int main(){
	int n,ch;
	while(1){
		printf("Menu: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Terminate\n");
		printf("Select Option: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("\nEnqueue element : ");
					scanf("%d",&n);
					enqueue(&front, &rear, max, q, n);
					break;
			case 2: printf("\nDeleting...\n");
					n=dequeue(&front, &rear, q);
					printf("%d\n\n", n);
					break;
			case 3: printf("\nDisplaying...\n");
					displayQ(&front, &rear, q);
					break;
			case 4: printf("\nexit...\n");
					exit(1);
			default : printf("\nkindly select correct option\n");
		}	
	}
	//enqueue(&front, &rear, q, 3, 30);
	//enqueue(&front, &rear, q, 3, 70);
	//enqueue(&front, &rear, q, 3, 80);
	//display(&front, &rear, q);
	//printf("%d\n",dequeue(&front, &rear, q));
	//display(&front, &rear, q);
	return 0;
}
