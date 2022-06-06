#include <stdio.h>

int search(int fSize, int n, int pageStream[], int frame[], int current)
{
    int check[fSize];
    for (int i = 0; i < fSize; i++)
    {
        check[i] = 0;
    }
    int count = 0;
    for (int i = current; i < n; i++)
    {
        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == pageStream[i])
            {
                check[j] = 1;
                count++;
            }
        }
        if (count == fSize - 1)
        {
            break;
        }
    }

    for (int i = 0; i < fSize; i++)
    {
        if (check[i] == 0)
        {
            return i;
        }
    }

    return 0;
}

int searchLeast(int fSize, int n, int pageStream[], int frame[], int current)
{
    int check[fSize];
    for (int i = 0; i < fSize; i++)
    {
        check[i] = 0;
    }
    int count = 0;
    for (int i = current; i >= 0; i--)
    {
        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == pageStream[i])
            {
                check[j] = 1;
                count++;
            }
        }
        if (count == fSize - 1)
        {
            break;
        }
    }

    for (int i = 0; i < fSize; i++)
    {
        if (check[i] == 0)
        {
            return i;
        }
    }

    return 0;
}

void optimal(int fSize, int n, int pageStream[])
{

    int frame[fSize], pageFaults = 0, i = 0, ind;
    for (int j = 0; j < fSize; j++)
    {
        frame[j] = -1;
    }

    printf("Incoming Stream\t\tFrames\n");
    while (i < n)
    {

        int found = 0;

        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == pageStream[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            ind = search(fSize, n, pageStream, frame, i);
            frame[ind] = pageStream[i];
            pageFaults++;
        }

        printf("%d\t\t\t", pageStream[i]);
        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == -1)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", frame[j]);
            }
        }
        printf("\n");
        i++;
    }

    printf("\nNumber of faults : %d", pageFaults);
    printf("\nNumber of hits : %d", n - pageFaults);
}
void lfu(int fSize, int n, int pageStream[])
{

    int frame[fSize], pageFaults = 0, i = 0, ind;
    for (int j = 0; j < fSize; j++)
    {
        frame[j] = -1;
    }

    printf("Incoming Stream\t\tFrames\n");
    while (i < n)
    {

        int found = 0;

        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == pageStream[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            ind = searchLeast(fSize, n, pageStream, frame, i);
            frame[ind] = pageStream[i];
            pageFaults++;
        }

        printf("%d\t\t\t", pageStream[i]);
        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == -1)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", frame[j]);
            }
        }
        printf("\n");
        i++;
    }

    printf("\nNumber of faults : %d", pageFaults);
    printf("\nNumber of hits : %d", n - pageFaults);
}
void fifo(int fSize, int n, int pageStream[])
{

    int frame[fSize], counter = 0, pageFaults = 0, i = 0;
    for (int j = 0; j < fSize; j++)
    {
        frame[j] = -1;
    }

    printf("Incoming Stream\t\tFrames\n");
    while (i < n)
    {

        int found = 0;

        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == pageStream[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            frame[(counter) % (fSize)] = pageStream[i];
            pageFaults++;
            counter++;
        }

        printf("%d\t\t\t", pageStream[i]);
        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == -1)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", frame[j]);
            }
        }
        printf("\n");
        i++;
    }

    printf("\nNumber of faults : %d", pageFaults);
    printf("\nNumber of hits : %d", n - pageFaults);
}

void lru(int fSize, int n, int pageStream[])
{

    int frame[fSize], check[fSize], pageFaults = 0, i = 0, index = 0, min;
    for (int j = 0; j < fSize; j++)
    {
        frame[j] = -1;
        check[j] = 0;
    }

    printf("Incoming Stream\t\tFrames\n");
    while (i < n)
    {

        int found = 0;

        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == pageStream[i])
            {
                found = 1;
                check[j]++;
                break;
            }
        }
        if (found == 0)
        {
            min = n;
            int s = 0;
            for (int j = 0; j < fSize; j++)
            {
                if (min > check[j])
                {
                    min = check[j];
                    index = j;
                }
                else if (min == check[j])
                {
                    s++;
                }
            }
            if (s > 0)
            {
                index = searchLeast(fSize, n, pageStream, frame, i);
            }
            frame[index] = pageStream[i];
            check[index] = 1;
            pageFaults++;
        }

        printf("%d\t\t\t", pageStream[i]);
        for (int j = 0; j < fSize; j++)
        {
            if (frame[j] == -1)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", frame[j]);
            }
        }
        printf("\n");
        i++;
    }

    printf("\nNumber of faults : %d", pageFaults);
    printf("\nNumber of hits : %d", n - pageFaults);
}

int main()
{

    int fSize, n;

    printf("Enter the frame size : ");
    scanf("%d", &fSize);

    printf("\nEnter the number of entries : ");
    scanf("%d", &n);

    int pageStream[n];
    printf("\nEnter the data of stream : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pageStream[i]);
    }

    int choice;
    printf("1.Fifo\n2.Optimal\n3.Lfu\n4.Lru\n");
    printf("Select Type of Page Replacement Policy : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fifo(fSize, n, pageStream);
        break;
    case 2:
        optimal(fSize, n, pageStream);
        break;
    case 3:
        lfu(fSize, n, pageStream);
        break;
    case 4:
        lru(fSize, n, pageStream);
        break;
    default:
        break;
    }

    return 0;
}