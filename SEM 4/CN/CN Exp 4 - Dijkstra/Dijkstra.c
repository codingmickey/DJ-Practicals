#include <stdio.h>
#include <stdbool.h>

#define MIN(x, y) (((x < y) ? x : y))

int main()
{
    int n = 6;
    int cost[6][6] = {
        {0, 7, 42069, 42069, 42069, 3},
        {7, 0, 4, 42069, 42069, 2},
        {42069, 4, 0, 8, 5, 5},
        {42069, 42069, 8, 0, 3, 42069},
        {42069, 42069, 5, 3, 0, 6},
        {3, 2, 5, 42069, 6, 0}};
    int vis[6] = {0, 0, 0, 0, 0, 0};
    int d[6];
    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);
    vis[source] = 1;

    for (int i = 0; i < n; i++)
    {
        d[i] = cost[source][i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d HEREEE %d\n", d[i], vis[i]);
    // }
    for (int i = 0; i < 6; i++)
    {
        int min, check = 1;
        for (int j = 0; j < 6; j++)
        {
            if (vis[j] == 0 && check == 1)
            {
                min = j;
                check = 0;
            }
            if (vis[j] == 0 && d[j] < d[min])
            {
                min = j;
            }
            // printf("%d ", d[j]);
        }
        // printf("\n");
        // printf("ANS: %d\n", min);
        vis[min] = 1;
        for (int j = 0; j < 6; j++)
        {
            // d[j] = (d[j] < d[min] + cost[min][j]) ? d[j] : (d[min] + cost[min][j]);
            d[j] = MIN(d[j], (d[min] + cost[min][j]));
        }
        // for (int j = 0; j < n; j++)
        // {
        //     printf("D%d ", d[j]);
        // }
        // printf("\n");
    }
    printf("\n");
    printf("The shortest path using Dijkstra's algorithm is(wrt node %d): \n", source);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    return 0;
}