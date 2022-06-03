#include<bits/stdc++.h>
struct times
{
  int art, but, p, rnt, tat, wtt;
};


int main()
{
    int i, j, pro, time, remain, flag = 0, ts;
    struct times a[100];
    float avgwt = 0, avgtt = 0;
    printf("Round Robin Scheduling Algorithm\n");
 printf("Note -\n1. Arrival Time of at least on process should be 0\n2. CPU
should never be idle\n");
 printf("Enter Number Of Processes : ");
 scanf("%d",&pro);
 remain=pro;
 for(i=0;i<pro;i++)
 {
        printf("Enter arrival time and Burst time for Process P%d : ", i);
        scanf("%d%d", &a[i].art, &a[i].but);
        a[i].p = i;
        a[i].rnt = a[i].but;
 }
 sortart(a,pro);
 printf("Enter Time Slice OR Quantum Number : ");
 scanf("%d",&ts);
 printf("\n***************************************\n");
 printf("Gantt Chart\n");
 printf("0");
 for(time=0,i=0;remain!=0;)
 {
        if (a[i].rnt <= ts && a[i].rnt > 0)
        {
            time = time + a[i].rnt;
            printf(" -> [P%d] <- %d", a[i].p, time);
            a[i].rnt = 0;
            flag = 1;
        }
        else if (a[i].rnt > 0)
        {
            a[i].rnt = a[i].rnt - ts;
            time = time + ts;
            printf(" -> [P%d] <- %d", a[i].p, time);
        }
        if (a[i].rnt == 0 && flag == 1)
        {
            remain--;
            a[i].tat = time - a[i].art;
            a[i].wtt = time - a[i].art - a[i].but;
            avgwt = avgwt + time - a[i].art - a[i].but;
            avgtt = avgtt + time - a[i].art;
            flag = 0;
        }
        if (i == pro - 1)
            i = 0;
        else if (a[i + 1].art <= time)
            i++;
        else
            i = 0;
 }
 printf("\n\n");
 printf("***************************************\n");
 printf("Pro\tArTi\tBuTi\tTaTi\tWtTi\n");
 printf("***************************************\n");
 for(i=0;i<pro;i++)
 {
        printf("P%d\t%d\t%d\t%d\t%d\n", a[i].p, a[i].art, a[i].but, a[i].tat, a[i].wtt);
 }
 printf("***************************************\n");
 avgwt = avgwt/pro;
 avgtt = avgtt/pro;
 printf("Average Waiting Time : %.2f\n",avgwt);
 printf("Average Turnaround Time : %.2f\n",avgtt);
 return 0;
}