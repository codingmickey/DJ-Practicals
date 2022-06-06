#include <stdio.h>

int absolute(int x, int y)
{
    if (x >= y)
    {
        return x - y;
    }
    else
    {
        return y - x;
    }
}

int FCFS(int n, int p, int m[], int ans[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            total += absolute(p, m[i]);
        }
        else
        {
            total += absolute(m[i - 1], m[i]);
        }
        ans[i] = m[i];
    }

    return total;
}

int SSTF(int n, int p, int m[], int ans[])
{
    int total = 0;
    int current, v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            current = p;
        }
        else
        {
            current = ans[i - 1];
        }
        int min = 199, j, x;
        for (j = 0; j < n; j++)
        {
            if (absolute(current, m[j]) <= min && v[j] == 0)
            {
                min = absolute(current, m[j]);
                x = j;
            }
        }
        v[x] = 1;
        total += min;
        ans[i] = m[x];
    }

    return total;
}

int SCAN(int n, int p, int m[], int ans[], int u)
{
    int total = 0;
    int a, x;
    for (int i = 0; i < n; i++)
    {
        if (p < m[i])
        {
            a = x = i;
            break;
        }
    }
    if (u == 0)
    {
        a--;
    }

    for (int i = 0; i < n + 1; i++)
    {
        printf("\na=%d x=%d u=%d\n", a, x, u);
        if (u == 1)
        {
            if (a < n && a >= x)
            {
                ans[i] = m[a];
                a++;
            }
            else if (a == n)
            {
                ans[i] = 199;
                a = a - x;
            }
            else
            {
                ans[i] = m[a];
                a--;
            }
        }
        else
        {
            if (a >= 0 && a < x)
            {
                ans[i] = m[a];
                a--;
            }
            else if (a == -1)
            {
                ans[i] = 0;
                a = x;
            }
            else
            {
                ans[i] = m[a];
                a++;
            }
        }
    }

    if (u == 1)
    {
        total += absolute(199, p) + absolute(199, m[0]);
    }
    else
    {
        total += absolute(0, p) + absolute(0, m[n - 1]);
    }

    return total;
}
int CSCAN(int n, int p, int m[], int ans[], int u)
{
    int total = 0;
    int a, x;
    for (int i = 0; i < n; i++)
    {
        if (p < m[i])
        {
            a = x = i;
            break;
        }
    }
    if (u == 0)
    {
        a--;
    }

    for (int i = 0; i < n + 2; i++)
    {
        printf("\na=%d x=%d u=%d\n", a, x, u);
        if (u == 1)
        {
            if (a < n && a >= x)
            {
                ans[i] = m[a];
                a++;
            }
            else if (a == n)
            {
                ans[i] = 199;
                a = -1;
            }
            else if (a == -1)
            {
                ans[i] = 0;
                a++;
            }
            else
            {
                ans[i] = m[a];
                a++;
            }
        }
        else
        {
            if (a >= 0 && a < x)
            {
                ans[i] = m[a];
                a--;
            }
            else if (a == -1)
            {
                ans[i] = 0;
                a = n;
            }
            else if (a == n)
            {
                ans[i] = 199;
                a--;
            }
            else
            {
                ans[i] = m[a];
                a--;
            }
        }
    }

    if (u == 1)
    {
        total = absolute(199, p) + 199 + absolute(0, m[x - 1]);
    }
    else
    {
        total = absolute(0, p) + 199 + absolute(199, m[x]);
    }

    return total;
}
int LOOK(int n, int p, int m[], int ans[], int u)
{
    int total = 0;
    int a, x;
    for (int i = 0; i < n; i++)
    {
        if (p < m[i])
        {
            a = x = i;
            break;
        }
    }
    if (u == 0)
    {
        a--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\na=%d x=%d u=%d\n", a, x, u);
        if (u == 1)
        {
            if (a < n && a >= x)
            {
                ans[i] = m[a];
                a++;
                if (a == n)
                {
                    a = a - x;
                }
            }
            else
            {
                ans[i] = m[a];
                a--;
            }
        }
        else
        {
            if (a >= 0 && a < x)
            {
                ans[i] = m[a];
                a--;
                if (a == -1)
                {
                    a = x;
                }
            }
            else
            {
                ans[i] = m[a];
                a++;
            }
        }
    }

    if (u == 1)
    {
        total = absolute(m[n - 1], p) + absolute(m[n - 1], m[0]);
    }
    else
    {
        total = absolute(m[0], p) + absolute(m[0], m[n - 1]);
    }

    return total;
}
int CLOOK(int n, int p, int m[], int ans[], int u)
{
    int total = 0;
    int a, x;
    for (int i = 0; i < n; i++)
    {
        if (p < m[i])
        {
            a = x = i;
            break;
        }
    }
    if (u == 0)
    {
        a--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\na=%d x=%d u=%d\n", a, x, u);
        if (u == 1)
        {
            if (a < n && a >= x)
            {
                ans[i] = m[a];
                a++;
                if (a == n)
                {
                    a = 0;
                }
            }
            else
            {
                ans[i] = m[a];
                a++;
            }
        }
        else
        {
            if (a >= 0 && a < x)
            {
                ans[i] = m[a];
                a--;
                if (a == -1)
                {
                    a = n - 1;
                }
            }
            else
            {
                ans[i] = m[a];
                a--;
            }
        }
    }

    if (u == 1)
    {
        total = absolute(m[n - 1], p) + absolute(m[n - 1], m[0]) + absolute(m[0], m[x - 1]);
    }
    else
    {
        total = absolute(m[0], p) + absolute(m[n - 1], m[0]) + absolute(m[n - 1], m[x]);
    }

    return total;
}

void print(int n, int p, int ans[], int total)
{
    printf("\nTrack movements are as follows : \n");
    printf("%d -> %d", p, ans[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" -> %d", ans[i]);
    }

    printf("\nTotal seek time is : %d\n", total);
}

int main()
{

    int n, p;
    printf("\nEnter the number of movements : ");
    scanf("%d", &n);

    int m[n];
    printf("\nEnter %d movements (0 - 199) : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }

    printf("\nEnter the current head location : ");
    scanf("%d", &p);
    // int n=5,p=65;
    // int m[]={25,51,60,132,189};
    int total, ans[n];
    int c;
    do
    {
        printf("\n1  -->  FCFS\n2  -->  SSTF\n3  -->  SCAN\n4  -->  CSCAN\n5  -->  LOOK\n6  -->  CLOOK\n7  -->  EXIT\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        int u;
        switch (c)
        {
        case 1:
            total = FCFS(n, p, m, ans);
            print(n, p, ans, total);
            break;
        case 2:
            total = SSTF(n, p, m, ans);
            print(n, p, ans, total);
            break;
        case 3:
            u = 0;
            total = SCAN(n, p, m, ans, u);
            print(n + 1, p, ans, total);
            break;
        case 4:
            u = 0;
            total = CSCAN(n, p, m, ans, u);
            print(n + 2, p, ans, total);
            break;
        case 5:
            u = 1;
            total = LOOK(n, p, m, ans, u);
            print(n, p, ans, total);
            break;
        case 6:
            u = 1;
            total = CLOOK(n, p, m, ans, u);
            print(n, p, ans, total);
            break;
        case 7:
            printf("\nExiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (c != 7);

    return 0;
}