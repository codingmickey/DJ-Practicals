#include <stdio.h>

int s = 0, n = 0, e = 4, b[4];

int Wait(int *s)
{
    return (--*s);
}

int Signal(int *s)
{
    return (++*s);
}

void producer()
{
    int a;

    printf("\nEnter value to Produce : ");
    scanf("%d", &a);

    Wait(&e);
    Wait(&s);

    b[n] = a;

    Signal(&s);
    Signal(&n);

    printf("\nBuffer : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}

void consumer()
{
    Wait(&s);
    for (int i = 1; i < n; i++)
    {
        b[i - 1] = b[i];
    }
    Wait(&n);
    Signal(&s);
    Signal(&e);

    printf("\nBuffer : ");

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main()
{
    int c;
    printf("Hello\n");

    do
    {
        printf("\n1  -->  Produce\n2  -->  Consume\n3  -->  Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            if (e == 0)
            {
                printf("\nBuffer is full\n");
            }
            else
            {
                producer();
            }
            break;
        case 2:
            if (e == 4)
            {
                printf("\nBuffer is empty\n");
            }
            else
            {
                consumer();
            }
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (c != 3);

    return 0;
}