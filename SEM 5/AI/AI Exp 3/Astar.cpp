#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    int adjMat[n + 3][n + 1];

    // n+1 for h(x)
    // n+2 for g(x)
    for (int i = 0; i < n + 3; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    cout << "Enter the heuristic values for each vertex!\n";
    for (int i = 1; i < n + 1; i++)
    {
        int h;
        cout << "h(" << i << "): ";
        cin >> h;
        adjMat[n + 1][i] = h;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cout << "Vertex1: ";
        cin >> u;
        cout << "Vertex2: ";
        cin >> v;
        cout << "Cost: ";
        cin >> c;
        adjMat[u][v] = c;
        adjMat[v][u] = c;
    }

    vector<int> closedList;
    // Priority queue of pairs with the ascending key of 1st
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> openList;
    bool goalReached = false;

    int startNode, goalNode;
    cout << "Enter the startNode: ";
    cin >> startNode;
    cout << "Enter the goalNode: ";
    cin >> goalNode;

    while (closedList.size() != n && !goalReached)
    {
        if (closedList.empty())
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (adjMat[startNode][j])
                {
                    int gx = adjMat[startNode][j];
                    int hx = adjMat[n + 1][j];
                    adjMat[n + 2][j] = gx;
                    openList.push({})
                }
            }
        }
    }

    cout << "\n  ";
    for (int i = 0; i < n + 2; i++)
        cout << i << " ";
    cout << "\n";

    for (int i = 0; i < n + 2; i++)
    {
        cout << i << " ";
        for (int j = 0; j < n + 1; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
