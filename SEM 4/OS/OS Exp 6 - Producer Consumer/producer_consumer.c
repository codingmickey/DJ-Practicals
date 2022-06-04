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
    printf("Enter value to Produce\n");
    scanf("%d", &a);
    Wait(&e);
    Wait(&s);
    b[n] = a;
    Signal(&s);
    Signal(&n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
void consumer()
{
    Wait(&n);
    Wait(&s);
    for (int i = 1; i < n; i++)
    {
        b[i - 1] = b[i];
    }
    Signal(&s);
    Signal(&e);
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
        printf("Enter Choice\n");
        printf("1. Produce \n2. Consume \n3. Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (e == 0)
            {
                printf("Buffer is full\n");
            }
            else
            {
                producer();
            }
            break;
        case 2:
            if (e == 4)
            {
                printf("Buffer is empty\n");
            }
            else
            {
                consumer();
            }
            break;
        case 3:
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (c != 3);
    return 0;
}
