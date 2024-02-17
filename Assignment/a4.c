#include <stdio.h>
#include "generic_stack.c"

void ssort(int *input, int *tmpStack, int *input_top, int *tmpStack_top, int size, int *x, int *y)
{
    if (!isEmpty(*tmpStack_top) && *y < *x)
    {
        *y = *(int *)pop(tmpStack, tmpStack_top, 1);
        push(input, input_top, y, size, 1);
        if (!isEmpty(*tmpStack_top))
            *y = *(int *)peek(tmpStack, tmpStack_top, 1);
        else
            return;
        ssort(input, tmpStack, input_top, tmpStack_top, size, x, y);
    }
}

void sort(int *input, int *tmpStack, int *input_top, int *tmpStack_top, int size)
{
    if (!isEmpty(*input_top))
    {
        int x = *(int *)pop(input, input_top, 1);
        if (!isEmpty(*tmpStack_top))
        {
            int y = *(int *)peek(tmpStack, tmpStack_top, 1);
            ssort(input, tmpStack, input_top, tmpStack_top, size, &x, &y);
            push(tmpStack, tmpStack_top, &x, size, 1);
        }
        else
        {
            push(tmpStack, tmpStack_top, &x, size, 1);
        }
        sort(input, tmpStack, input_top, tmpStack_top, size);
    }
}

int main()
{
    int size;

    printf("Enter the size of stack : ");
    scanf("%d", &size);

    int input[size], tmpStack[size], input_top = -1, tmpStack_top = -1, value;

    printf("Enter the elements of your stack : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &value);
        push(input, &input_top, &value, size, 1);
    }

    sort(input, tmpStack, &input_top, &tmpStack_top, size);

    printf("Sorted stack is as follows : ");
    display(tmpStack, tmpStack_top, 1);
    return 0;
}
