#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<float, float>> vect;
    vector<pair<float, float>> vect1;
    vector<pair<float, float>>::iterator it;
    vector<float> CT;
    vector<float> TT;
    vector<float> WT;
    int burst = 0, Total = 0;
    int p;
    cout << "Enter no processess: ";
    cin >> p;
    float AT[p], BT[p];
    cout << "AT BT\n";
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
    int cmpl_T = vect[0].first + vect[0].second;
    vect1.push_back(make_pair(vect[0].first, vect[0].second));
    CT.push_back(cmpl_T);
    vect.erase(vect.begin());
    int min = 999;
    int index;
    int Total1 = 0;
    Total = 0;
    while (vect.size() > 0)
    {
        it = vect.begin();
        min = 999;
        for (int i = 0; i < vect.size(); i++)
        {
            if (vect[i].first <= cmpl_T && min > vect[i].second)
            {
                min = vect[i].second;
                index = i;
            }
        }
        if (min == 999)
        {
            for (int i = 0; i < vect.size(); i++)
            {
                if (min > vect[i].second)
                {
                    min = vect[i].second;
                    index = i;
                }
            }
            cmpl_T = vect[index].first + vect[index].second;
        }
        else
        {
            cmpl_T += vect[index].second;
        }
        CT.push_back(cmpl_T);
        int at = vect[index].first;
        int bt = vect[index].second;
        vect1.push_back(make_pair(at, bt));
        vect.erase(it + index);
    }
    for (int i = 0; i < n; i++)
    {
        int tt = CT[i] - vect1[i].first;
        int wt = tt - vect1[i].second;
        TT.push_back(tt);
        WT.push_back(wt);
        Total += TT[i];
        Total1 += WT[i];
    }
    float Avg_TT = Total / (float)n;
    float Avg_WT = Total1 / (float)n;
    printf("Process\t\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < vect1.size(); i++)
    {
        printf("%d\t\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", i + 1, vect1[i].first, vect1[i].second,
               CT[i], TT[i], WT[i]);
    }
    printf("Average waiting time is : %.2f\n", Avg_WT);
    printf("Average turn around time is : %.2f\n", Avg_TT);
    return 0;
}