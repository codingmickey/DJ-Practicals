#include <stdio.h>
#include <math.h>

int hamming_calculate(int position, int length, int code[])
{
    int count = 0;
    int i, j, k;
    i = position - 1;

    while (i < length)
    {

        for (j = i; j < i + position; j++)
        {
            if (code[j] == 1)
            {
                count++;
            }
        }

        i = i + 2 * position;
    }

    if (count % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void print(int n, int p, int code[])
{
    for (int i = 0; i < n + p; i++)
    {
        printf(" %d \t", code[i]);
    }
    printf("\n");
    int j = 0;

    for (int i = 0; i < n + p; i++)
    {
        if (i == (pow(2, j) - 1))
        {
            printf(" P%d \t", i + 1);
            j++;
        }
        else
        {
            printf(" D%d \t", i + 1);
        }
    }
}

int main()
{
    int n, p;

    printf("Enter the size of hamming code : ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        if (pow(2, i) >= n + i + 1)
        {
            p = i;
            break;
        }
    }

    int code[n + p], input[n];

    printf("Enter the data of hamming code \n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of bit %d : ", i + 1);
        scanf("%d", &input[i]);
        printf("\n");
    }

    int j = 0, k = n - 1;

    for (int i = 0; i < n + p; i++)
    {
        if (i == (pow(2, j) - 1))
        {
            code[i] = 0;
            j++;
        }
        else
        {
            code[i] = input[k];
            k--;
        }
    }

    printf("The Intial Hamming code is :\n");
    print(n, p, code);

    for (int i = 0; i < p; i++)
    {
        int position = pow(2, i);
        int value = hamming_calculate(position, n + p, code);
        code[position - 1] = value;
    }

    printf("\n\nThe Final Hamminag Code is : \n");
    print(n, p, code);

    return 0;
}
