#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noOfPartitions;
    // cout << "Enter the number of patitions: ";
    cin >> noOfPartitions;
    int partitionMemory[noOfPartitions], tempPMemory[noOfPartitions];
    for (int i = 0; i < noOfPartitions; i++)
    {
        // cout << "Partition " << i + 1 << ": ";
        cin >> partitionMemory[i];
        tempPMemory[i] = partitionMemory[i];
    }
    int noOfProcesses;
    // cout << "Enter the number of processes: ";
    cin >> noOfProcesses;
    int processesMemory[noOfProcesses];
    for (int i = 0; i < noOfProcesses; i++)
    {
        // cout << "Partition " << i + 1 << ": ";
        cin >> processesMemory[i];
    }
    string worstFit[noOfPartitions], notAllocatedProcesses;
    for (int i = 0; i < noOfPartitions; i++)
    {
        worstFit[i] = "X";
    }
    for (int i = 0; i < noOfProcesses; i++)
    {
        bool isAlloc = false;
        int maxSize;
        for (int j = 0; j < noOfPartitions; j++)
        {
            if (processesMemory[i] <= partitionMemory[j] && !isAlloc)
            {
                maxSize = j;
                isAlloc = true;
            }
            else if (processesMemory[i] <= partitionMemory[j])
            {
                if (partitionMemory[j] > partitionMemory[maxSize])
                {
                    maxSize = j;
                }
            }
        }
        if (isAlloc)
        {
            partitionMemory[maxSize] -= processesMemory[i];
            if (worstFit[maxSize] == "X")
            {

                worstFit[maxSize] = "P" + to_string(i + 1);
            }
            else
            {
                worstFit[maxSize] += ", P" + to_string(i + 1);
            }
            isAlloc = true;
        }
        else if (!isAlloc && notAllocatedProcesses.empty())
        {
            notAllocatedProcesses = "P" + to_string(i + 1);
        }
        else if (!isAlloc)
        {
            notAllocatedProcesses += ", P" + to_string(i + 1);
        }
    }
    cout << "Partitions\t\tWorst Fit\n";
    for (int i = 0; i < noOfPartitions; i++)
    {
        cout << tempPMemory[i] << "\t\t\t" << worstFit[i] << "\n";
    }
    if (notAllocatedProcesses.empty())
    {
        cout << "There are no unallocated processes!\n";
    }
    else
    {
        cout << "The unallocated processes are: " << notAllocatedProcesses << "\n";
    }

    return 0;
}