#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<float, float>> vect;
    vector<float> TT;
    vector<float> WT;
    int burst = 0, Total = 0;
    int p;
    cout << "Enter no processess: ";
    cin >> p;
    float AT[p], BT[p];
    cout << "Now enter the times in order of->\nAT BT\n";
    for (int i = 0; i < p; i++)
    {
        cin >> AT[i];
        cin >> BT[i];
    }
    int n = sizeof(AT) / sizeof(AT[0]);
    for (int i = 0; i < n; i++)
    {
        vect.push_back(make_pair(AT[i], BT[i]));
    }
    sort(vect.begin(), vect.end());
    int cmpl_T = 0;
    Total = 0;
    for (int i = 0; i < n; i++)
    {
        int tt = 0;
        cmpl_T += vect[i].second;
        tt = cmpl_T - vect[i].first;
        TT.push_back(tt);
        Total += TT[i];
    }
    float Avg_TT = Total / (float)n;
    float total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        int wt = 0;
        if (i == 0)
        {
            wt = TT[i] - vect[i].second;
            WT.push_back(wt);
        }
        else
        {
            wt = TT[i] - vect[i].second;
            WT.push_back(wt);
            total_wt += WT[i];
        }
    }
    float Avg_WT = total_wt / n;
    printf("Process\tWT \tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\n", i + 1, WT[i], TT[i]);
    }
    printf("Average turn around time is : %.2f\n", Avg_TT);
    printf("Average waiting time is : %.2f\n", Avg_WT);
    return 0;
}