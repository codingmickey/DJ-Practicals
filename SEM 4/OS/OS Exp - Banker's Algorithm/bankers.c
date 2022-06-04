#include <stdio.h>
#include <stdbool.h>
#define process 5
#define resource 4

void isSafe(int processes[], int available[], int max_req[process][resource], int allocated[process][resource])
{
    int remaining_need[process][resource];
    int order[process], index = 0;
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
        {
            remaining_need[i][j] = max_req[i][j] - allocated[i][j];
        }
    }
    bool check[process] = {false, false, false, false, false};
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < process; j++)
        {
            int count = 0;
            if (check[j] == false)
            {
                for (int k = 0; k < resource; k++)
                {
                    if (available[k] >= remaining_need[j][k])
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (count == resource)
                {
                    check[j] = true;
                    for (int l = 0; l < resource; l++)
                    {
                        available[l] += allocated[j][l];
                    }
                    order[index] = j;
                    index++;
                }
            }
            else
            {
                continue;
            }
        }
    }
    if (index == process)
    {
        printf("No deadlock will happen, its safe\nThe order is: \n");
        for (int p = 0; p < process; p++)
        {
            printf("The order is : %d \n", order[p]);
        }
    }
    else
    {
        printf("deadlock will happen, its unsafe\n");
    }
}
int main()
{
    int processes[process] = {0, 1, 2, 3, 4};
    int available[process] = {1, 5, 2, 0};
    int allocated[process][resource] = {{0, 0, 1, 2},
                                        {1, 0, 0, 0},
                                        {1, 3, 5, 4},
                                        {0, 6, 3, 2},
                                        {0, 0, 1, 4}};
    int max_req[process][resource] = {{0, 0, 1, 2},
                                      {1, 7, 5, 0},
                                      {2, 3, 5, 6},
                                      {0, 6, 5, 2},
                                      {0, 6, 5, 6}};
    isSafe(processes, available, max_req, allocated);
}
