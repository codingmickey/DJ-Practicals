#include <iostream>

struct Process
{
    int no, at, bt, ct, tat, wt;
};

void sortPro(struct Process *program, int start, int end, bool isAt)
{
    if (isAt)
    {
        for (int i = start; i < end; i++)
        {
            for (int j = start; j <= end - i - 1; j++)
            {
                if (program[j].at > program[j + 1].at)
                {
                    struct Process temp = program[j];
                    program[j] = program[j + 1];
                    program[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = start; i < end; i++)
        {
            if (program[i].bt > program[i + 1].bt)
            {
                struct Process temp;
                temp = program[i];
                program[i + 1] = temp;
                program[i] = program[i + 1];
            }
        }
    }
}

int main()
{
    int noOfProcesses;
    printf("Enter the number of processes: ");
    // scanf("%d", &noOfProcesses);
    noOfProcesses = 3;

    int ptime = 0;
    float atat = 0, awt = 0;

    struct Process program[noOfProcesses];

    printf("Enter the arrival times\n");
    for (int i = 0; i < noOfProcesses; i++)
    {
        printf("ARRIVAL Time of %d: ", (i + 1));
        // scanf("%d", &program[i].at);
        program[i].at = 4 - i;
        program[i].no = i;
    }

    printf("Enter the burst times\n");
    for (int i = 0; i < noOfProcesses; i++)
    {
        printf("BURST Time of %d: ", (i + 1));
        // scanf("%d", &program[i].bt);
        program[i].bt = 5 + i;
    }

    for (int i = 0; i < noOfProcesses; i++)
    {
        printf("\nP%d\t%d\t%d\n", (i + 1), program[i].at, program[i].bt);
    }

    sortPro(program, 0, noOfProcesses - 1, true);

    for (int i = 0; i < noOfProcesses; i++)
    {
        printf("P%d\t%d\t%d\n", (i + 1), program[i].at, program[i].bt);
    }

    printf("Order of execution of the Processes are:\n");
    for (int i = 0; i < noOfProcesses; i++)
    {
        if (i == noOfProcesses - 1)
            printf("P%d\n", program[i].no);
        else
            printf("P%d, ", program[i].no);
    }

    int i;
    for (i = 0; i < noOfProcesses; i++)
    {
        if (i == 0 && program[i].at != 0)
        {
            ptime = program[i].at + program[i].bt;
        }
        else
        {
            ptime += program[i].bt;
        }
        program[i].ct = ptime;
        program[i].tat = program[i].ct - program[i].at;
        program[i].wt = program[i].tat - program[i].bt;
        atat += program[i].tat;
        awt += program[i].wt;
    }
    atat /= noOfProcesses;
    awt /= noOfProcesses;

    printf("\nAnalysis Table\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < noOfProcesses; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", program[i].no, program[i].at, program[i].bt, program[i].ct, program[i].tat, program[i].wt);
    }
    printf("Average Turn Around Time = %f\n", atat);
    printf("Average Waiting Time = %f\n", awt);

    return 0;
}
