//NON Preemptive SJF
#include <stdio.h>

struct Process {
    int id;          // Process ID
    int arrivalTime; // Arrival Time
    int burstTime;   // Burst Time
    int waitingTime; // Waiting Time
    int turnaroundTime; // Turnaround Time
};
void main() {
    int n, i, j, currentTime = 0;
    struct Process temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    // Input the process details
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }
    // Sort processes by Arrival Time (then by Burst Time if needed)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime ||
                (processes[i].arrivalTime == processes[j].arrivalTime && processes[i].burstTime > processes[j].burstTime)) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    // Calculate Waiting Time and Turnaround Time
    currentTime = 0;
    for (i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime; // Idle until the process arrives
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
    // Display results
    printf("\nProcess\tAT\tBT\tWT\tTT\n");
    float totalWT = 0, totalTT = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
        totalWT += processes[i].waitingTime;
        totalTT += processes[i].turnaroundTime;
    }
    // Calculate and display averages
    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTT / n);
}
