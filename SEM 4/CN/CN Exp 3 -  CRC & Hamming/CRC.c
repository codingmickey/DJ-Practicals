
#include <stdio.h>

void modulo2Div(int n, int l, int g[], int d[], int code[])
{
    int key[l + n], m, j, k;
    for (int i = 0; i < l; i++)
    {
        m = 0;
        k = key[i];
        for (j = i; j < i + 4; j++)
        {
            if (i == 0)
            {
                if (g[m] == d[m])
                {
                    key[j] = 0;
                }
                else
                {
                    key[j] = 1;
                }
            }
            else if (k == 0)
            {
                if (key[j] == 0)
                {
                    key[j] = 0;
                }
                else
                {
                    key[j] = 1;
                }
            }
            else
            {
                if (key[j] == g[m])
                {
                    key[j] = 0;
                }
                else
                {
                    key[j] = 1;
                }
            }
            m++;
        }
        key[j] = d[i + 4];
    }
    for (int i = 0; i < l; i++)
    {
        code[i] = d[i];
    }
    for (int i = l; i < n + l; i++)
    {
        code[i] = key[i];
    }
}
int main()
{
    int n, error = 0;
    printf("Enter the highest degree of G(x) : ");
    scanf("%d", &n);
    int g[n];
    for (int i = 0; i <= n; i++)
    {
        printf("\nEnter the coefficient of x^%d : ", n - i);
        scanf("%d", &g[i]);
    }
    int l;
    printf("Enter the length of original data : ");
    scanf("%d", &l);
    int d[l + n];
    printf("\nEnter the original data : ");
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &d[i]);
    }
    for (int i = 0; i < n; i++)
    {
        d[l + i] = 0;
    }
    int code[l + n];
    modulo2Div(n, l, g, d, code);
    printf("\nGenerator : ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d", g[i]);
    }
    printf("\n");
    printf("\nData : ");
    for (int i = 0; i < l; i++)
    {
        printf("%d", d[i]);
    }
    printf("\n");
    printf("\nRemainder : ");
    for (int i = l; i < l + n; i++)
    {
        printf("%d", code[i]);
    }
    printf("\n");
    printf("\nCodeword : ");
    for (int i = 0; i < l + n; i++)
    {
        printf("%d", code[i]);
    }
    printf("\n");
    modulo2Div(n, l, g, code, code);
    for (int i = l; i < l + n; i++)
    {
        if (!code[i] == 0)
        {
            error = 1;
        }
    }
    if (error)
    {
        printf("\nError!");
    }
    else
    {
        printf("\nRemainder at receiving side : ");
        for (int i = l; i < l + n; i++)
        {
            printf("%d", code[i]);
        }
        printf("\n");
        printf("\nReceived successfully");
    }
    return 0;
}
