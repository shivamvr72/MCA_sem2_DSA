#include <stdio.h>
#include "generic_stack.c"
#define size 50

int queue[size], top = -1;

void enqueue(int *queue, int *top, int s, int item)
{
    if (isFull(*top, s))
    {
        printf("Queue is full !\n");
        return;
    }

    push(queue, top, &item, s, 1);
}

int dequeue(int *queue, int *top, int s)
{
    if (isEmpty(*top))
    {
        printf("Queue is empty !\n");
        return 0;
    }
    int temp[size], temp_top = -1, value;
    while (!isEmpty(*top))
    {
        value = *(int *)pop(queue, top, 1);
        push(temp, &temp_top, &value, s, 1);
    }
    int returnValue = *(int *)pop(temp, &temp_top, 1);

    while (!isEmpty(temp_top))
    {
        value = *(int *)pop(temp, &temp_top, 1);
        push(queue, top, &value, s, 1);
    }

    return returnValue;
}

void displayQ(int *queue, int *top, int s)
{
    if (isEmpty(*top))
    {
        printf("Queue is empty !\n");
        return;
    }

    printf("Queue is ");

    int temp[size], temp_top = -1, value;
    while (!isEmpty(*top))
    {
        value = *(int *)pop(queue, top, 1);
        push(temp, &temp_top, &value, s, 1);
    }

    while (!isEmpty(temp_top))
    {
        value = *(int *)pop(temp, &temp_top, 1);
        printf("%d | ", value);
        push(queue, top, &value, s, 1);
    }

    printf("\n");
}

int main()
{
    enqueue(queue, &top, size, 10);
    enqueue(queue, &top, size, 20);
    enqueue(queue, &top, size, 30);
    enqueue(queue, &top, size, 40);
	enqueue(queue, &top, size, 40);
    displayQ(queue, &top, size);

    dequeue(queue, &top, size);

    displayQ(queue, &top, size);
    return 0;
}
