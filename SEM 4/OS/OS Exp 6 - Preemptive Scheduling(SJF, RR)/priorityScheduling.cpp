#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void pro_sort(vector<pair<pair<ll, ll>, pair<ll, ll>>> &p)
{
    for (int i = 0; i < p.size() - 1; i++)
    {
        for (int j = 0; j < p.size() - i - 1; j++)
        {
            if (p[j].second.first > p[j + 1].second.first)
            {
                swap(p[j], p[j + 1]);
            }
        }
    }
}
int main()
{
    ll n, calc = 0;
    cout << "Number of processes: ";
    cin >> n;
    cout << "Process"
         << " "
         << "Priority"
         << " "
         << "AT"
         << " "
         << "BT" << endl;
    vector<pair<pair<ll, ll>, pair<ll, ll>>> process, copy;
    for (int i = 0; i < n; i++)
    {
        int pro, pri, at, bt;
        cin >> pro >> pri >> at >> bt;
        process.push_back({{pro, pri}, {at, bt}});
        calc += bt;
    }
    copy = process;
    pro_sort(copy);
    pro_sort(process);
    unordered_map<ll, ll> ma;
    int flag = 1;
    int t = min(process[1].second.first, process[0].second.first + process[0].second.second);
    process[0].second.second -= (t - process[0].second.first);
    int start = process[0].second.first;
    calc += start;
    vector<pair<ll, ll>> gc;
    gc.push_back({process[0].first.first, t});
    while (t < calc)
    {
        int maxp = INT_MIN, idx;
        for (int i = 0; i < n; i++)
        {
            int pro = process[i].first.first;
            int pri = process[i].first.second;
            int at = process[i].second.first;
            if (ma[pro] != 1 && at <= t)
            {
                if (pri > maxp)
                {
                    maxp = pri;
                    idx = i;
                }
            }
        }
        int pro = process[idx].first.first;
        int pri = process[idx].first.second;
        int at = process[idx].second.first;
        int prev = gc[gc.size() - 1].second;
        gc.push_back({process[idx].first.first, prev + 1});
        process[idx].second.second -= 1;
        t += 1;
        if (process[idx].second.second == 0)
        {
            ma[process[idx].first.first] = 1;
        }
    }
    unordered_map<ll, ll> m;
    vector<ll> ct(n + 1), tat(n + 1), wt(n + 1);
    for (int i = gc.size() - 1; i >= 0; i--)
    {
        if (m[gc[i].first] == 0)
        {
            ct[gc[i].first] = gc[i].second;
            m[gc[i].first] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int pro = process[i].first.first;
        tat[pro] = ct[pro] - process[i].second.first;
        wt[pro] = tat[pro] - copy[i].second.second;
    }
    float avgt = 0, avgw = 0;
    cout << "Process\t\t"
         << "Priority\t"
         << "AT\t"
         << "BT\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t" << endl;
    for (int i = 0; i < n; i++)
    {
        int pro = copy[i].first.first;
        cout << copy[i].first.first << "\t\t" << copy[i].first.second << "\t\t" << copy[i].second.first << "\t" << copy[i].second.second << "\t" << ct[pro] << "\t" << tat[pro] << "\t" << wt[pro] << endl;
        avgt += tat[pro];
        avgw += wt[pro];
    }
    cout << "Average tat: " << avgt * 1.0 / n << endl;
    cout << "Average wt: " << avgw * 1.0 / n << endl;
}