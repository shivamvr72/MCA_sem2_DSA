#include <stdio.h>
#define s 10

void insertAtRear(int *queue, int *front, int *rear, int item)
{
    if (*rear == (s - 1))
    {
        printf("Queue is full !\n");
        return;
    }
    else if (*front == -1)
    {
        *front += 1;
    }

    queue[*rear + 1] = item;
    //*rear += 1;//commented
}

int deleteAtFront(int *queue, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty !\n");
        return 0;
    }
    int i = queue[*front];
    if (*front == *rear)
    {
        *front = *rear = -1;
        return i;
    }
    *front += 1;
    return i;
}

void insertAtFront(int *queue, int *front, int *rear, int item)
{
	if(*front == *rear-1){
		printf("Overflow\n");
	}
	if(*front == -1){
//		printf("if\n");
		*front+=1;
		*rear+=1;
		queue[*front] = item;
	}else if(*front == 0 && *rear<=s-1){
		//printf("El%d\n",*rear);
		*rear+=1;
		//printf("El%d\n",*rear);
		for(int i=*rear; i>=*front; i--){
			*((queue+i)+1) = *(queue+i);
		}			
		queue[*front]=item;
	}else if(*front>=1){
		//printf("i\n");
		*front-=1;
		queue[*front]=item;
	}
	else{
		printf("error!\n");
	}
}
    

int deleteAtRear(int *queue, int *front, int *rear)
{
    if (*rear - 1 < 0)
    {
        printf("Queue is empty !\n");
        return 0;
    }
    int i = queue[*rear];
    if (*front == *rear)
    {
        *front = *rear = -1;
        return i;
    }
    *rear -= 1;
    return i;
}

void display(int *queue, int *front, int *rear)
{
    int temp[s], f = -1, r = -1;kl
    while (*front != -1)
    {
        int t = deleteAtFront(queue, front, rear);
        if (t)
        {
            printf("%d| ", t);
            insertAtRear(temp, &f, &r, t);
        }
    }
    printf("\n");

    while (f != -1)
    {
        int t = deleteAtFront(temp, &f, &r);
        if (t)
            insertAtRear(queue, front, rear, t);
    }
}

int main()
{
    int ch, x, queue[s];
    int front = -1, rear = -1;
    while (1)
    {
       // printf("\n 1.insert at front\n 2.insert at rear\n 3. delete from front \n 4.delete from rear\n 5.display\n 6.exit\n");
        printf("enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        	printf("b : Front = %d Back = %d", front, rear);
        	
            printf("\nenter an element:\n");
            scanf("%d", &x);
            insertAtFront(queue, &front, &rear, x);
//            display(queue, &front, &rear);
            printf("Front = %d Back = %d\n", front, rear);
            break;
        case 2:
        	
            printf("enter an element:");
            scanf("%d", &x);
            printf("b : Front = %d Back = %d\n", front, rear);
            insertAtRear(queue, &front, &rear, x);
            printf("a : Front = %d Back = %d\n", front, rear);
            
            break;
        case 3:
        	
        	printf("b : Front = %d Back = %d\n", front, rear);
            deleteAtFront(queue, &front, &rear);
            printf("a : Front = %d Back = %d\n", front, rear);
            break;

        case 4:
        	printf("b Front = %d Back = %d\n", front, rear);
        	
            deleteAtRear(queue, &front, &rear);
            
            printf("Front = %d Back = %d\n", front, rear);
            break;

        case 5:
            display(queue, &front, &rear);
            break;

        case 6:
            return 0;
        }
    }
    return 0;
}
