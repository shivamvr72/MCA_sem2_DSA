#include <stdio.h>
#include <string.h>
#include "generic_stack.c"

void sort(char *istr, char *mainStack, char *auxStack, int *main_top, int *aux_top, int size)
{
    for (int i = 0; i < size; i++)
    {
        char x = istr[i];

        if (!isEmpty(*main_top))
        {
            char y = *(char *)peek(mainStack, main_top, 2);
            if (x >= y)
                push(mainStack, main_top, &x, size, 2);
            else
            {
                while (!isEmpty(*main_top) && y > x)
                {
                    y = *(char *)pop(mainStack, main_top, 2);
                    push(auxStack, aux_top, &y, size, 2);

                    if (!isEmpty(*main_top))
                        y = *(char *)peek(mainStack, main_top, 2);
                    else
                        break;
                }

                push(mainStack, main_top, &x, size, 2);

                while (!isEmpty(*aux_top))
                {
                    char y = *(char *)pop(auxStack, aux_top, 2);
                    push(mainStack, main_top, &y, size, 2);
                }
            }
        }
        else
        {
            push(mainStack, main_top, &x, size, 2);
        }
    }
}

void reverse(char *mainStack, int *main_top)
{
    if (!isEmpty(*main_top))
    {
        char y = *(char *)pop(mainStack, main_top, 2);
        reverse(mainStack, main_top);
        printf("%c |", y);
    }
}

int main()
{
    int size;
    char istr[50];

    printf("Enter your input string : ");
    scanf("%s", istr);

    size = strlen(istr);

    char mainStack[size], auxStack[size], value;
    int main_top = -1, aux_top = -1;

    sort(istr, mainStack, auxStack, &main_top, &aux_top, size);

    printf("Sorted reverse stack : \n");
    reverse(mainStack, &main_top);
    printf("\n");
    return 0;
}
