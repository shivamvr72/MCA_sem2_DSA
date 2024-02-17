#include <stdio.h>
#include "generic_stack.c"
#define size 10

void copyStk(int *mainStack, int *main_top, int *temp, int *temp_top)
{
    if (!isEmpty(*main_top))
    {
        int y = *(int *)pop(mainStack, main_top, 1);
        copyStk(mainStack, main_top, temp, temp_top);
        push(temp, temp_top, &y, size, 1);
    }
}

void reverse(int *mainStack, int *main_top, int *temp, int *temp_top)
{
    if (!isEmpty(*main_top))
    {
        int y = *(int *)pop(mainStack, main_top, 1);
        push(temp, temp_top, &y, size, 1);
        reverse(mainStack, main_top, temp, temp_top);
    }
    if (isEmpty(*main_top))
    {
        copyStk(temp, temp_top, mainStack, main_top);
    }
}

int main()
{
    int stack[size], top = -1, temp[size], temp_top = -1;
    for (int i = 0; i < 10; i++)
        push(stack, &top, &i, size, 1);

    printf("Original Stack \n");
    display(stack, top, 1);

    printf("\nReversed Stack \n");

    reverse(stack, &top, temp, &temp_top);
    display(stack, top, 1);
    return 0;
}
