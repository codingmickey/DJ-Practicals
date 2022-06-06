#include <stdio.h>

int main()
{

    int n, m;
    printf("Enter the number of orders : ");
    scanf("%d", &n);

    printf("Enter the number of resources : ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];

    printf("Enter the details for orders\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nOrder P%d\nEnter supplied resources : ", i);

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }

        printf("Enter maximum requirements : ");

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter available resources : ");

    for (int j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    int f[n], ans[n], ind = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
    }

    int need[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("\ntThe given sequence is not safe \n");
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nFollowing is SAFE Sequence \n");
        for (int i = 0; i < n - 1; i++)
        {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }

    return 0;
}