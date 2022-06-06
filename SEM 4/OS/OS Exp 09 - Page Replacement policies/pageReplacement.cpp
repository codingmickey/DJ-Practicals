#include <iostream>

using namespace std;
int fSize, n;

void answer(int *data, int **ans)
{
    int hit = 0;
    cout << "Answer:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_"
             << " ";
    }
    cout << endl;
    for (int j = 0; j < fSize; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i][fSize] == -1)
        {
            cout << "F ";
        }
        else
        {
            hit++;
            cout << "H ";
        }
    }
    cout << endl
         << "Number of Page Hits: " << hit;
    cout << endl
         << "Number of Page Faults: " << (n - hit);
}
void fifo(int *data, int **ans)
{
    int in = 0, temp = 0, counter = fSize;
    for (int i = 0; i < n; i++)
    {
        if (i < counter)
        {
            for (int j = 0; j < fSize; j++)
            {
                if (j < (i + fSize - counter))
                {
                    ans[i][j] = ans[i - 1][j];
                    if (data[i] == ans[i - 1][j])
                    {
                        temp = 1;
                    }
                }
                else
                    ans[i][j] = 0;
            }
            if (temp == 1)
            {
                ans[i][fSize] = 0;
                counter++;
            }
            else
            {
                ans[i][(i + fSize - counter)] = data[i];
                ans[i][fSize] = -1;
            }
            temp = 0;
        }
        else
        {
            for (int j = 0; j < fSize; j++)
            {
                ans[i][j] = ans[i - 1][j];
                if (data[i] == ans[i - 1][j])
                {
                    temp = 1;
                }
            }
            if (temp == 1)
            {
                ans[i][fSize] = 0;
            }
            else
            {
                ans[i][in] = data[i];
                in = (in + 1) % fSize;
                ans[i][fSize] = -1;
            }
        }
        temp = 0;
    }
    answer(data, ans);
}
void lru(int *data, int **ans)
{
    int in = 0, temp = 0, counter = fSize, key = 0;
    int *q = new int[fSize];
    for (int i = 0; i < n; i++)
    {
        if (i < counter)
        {
            for (int j = 0; j < fSize; j++)
            {
                if (j < (i + fSize - counter))
                {
                    ans[i][j] = ans[i - 1][j];
                    if (data[i] == ans[i - 1][j])
                    {
                        key = j;
                        temp = 1;
                    }
                }
                else
                    ans[i][j] = 0;
            }
            if (temp == 1)
            {
                ans[i][fSize] = 0;
                q[key] = i;
                counter++;
            }
            else
            {
                ans[i][(i + fSize - counter)] = data[i];
                ans[i][fSize] = -1;
                q[(i + fSize - counter)] = i;
            }
            temp = 0;
        }
        else
        {
            for (int j = 0; j < fSize; j++)
            {
                ans[i][j] = ans[i - 1][j];
                if (data[i] == ans[i - 1][j])
                {
                    temp = 1;
                    q[j] = i;
                }
            }
            if (temp == 1)
            {
                ans[i][fSize] = 0;
            }
            else
            {
                in = 0;
                for (int j = 0; j < fSize; j++)
                {
                    if (q[in] > q[j])
                    {
                        in = j;
                    }
                }
                ans[i][in] = data[i];
                q[in] = i;
                ans[i][fSize] = -1;
            }
        }
        temp = 0;
    }
    answer(data, ans);
}
int main()
{
    int choice;
    cout << "Enter Frame Size: ";
    cin >> fSize;
    cout << "Enter Number of Entries: ";
    cin >> n;
    int *data = new int[n];
    cout << "Enter Data: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    int **ans = new int *[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = new int[fSize + 1];
    }
    cout << "Select Type of Page Replacement Policy :" << endl;
    cout << "1.Fifo\n2.LRU\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        fifo(data, ans);
        break;
    case 2:
        lru(data, ans);
        break;
    default:
        break;
    }
    return 0;
}
