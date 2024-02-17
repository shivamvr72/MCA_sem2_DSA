#include <stdio.h>
#include "generic_stack.c"

void sort(int *s1, int *temp, int *s1t, int *tmpt, int size)
{
    while (!isEmpty(*s1t))
    {
        int x = *(int *)pop(s1, s1t, 1);
        if (!isEmpty(*tmpt))
        {
            int y = *(int *)peek(temp, tmpt, 1);
            while (!isEmpty(*tmpt) && y > x)
            {
                y = *(int *)pop(temp, tmpt, 1);
                push(s1, s1t, &y, size, 1);
                if (!isEmpty(*tmpt))
                    y = *(int *)peek(temp, tmpt, 1);
                else
                    break;
            }
            push(temp, tmpt, &x, size, 1);
        }
        else
        {
            push(temp, tmpt, &x, size, 1);
        }
    }
}

int main()
{
    int size;

    printf("Enter the size of stack : ");
    scanf("%d", &size);

    int s1[size], tmpS[size], ps1 = -1, ptmpS = -1, data;

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data);
        push(s1, &ps1, &data, size, 1);
    }

    sort(s1, tmpS, &ps1, &ptmpS, size);

    printf("Sorted stack in ascending order: ");
    display(tmpS, ptmpS, 1);
    return 0;
}
