#include<stdio.h>
void main() {
int i, n;
int bt[10], wt[10], tt[10], w1 = 0, t1 = 0;
float aw, at;
printf("Enter the number of processes:\n");
scanf("%d",&n);
for (i = 0; i<n; i++) {
printf("Enter the burst time of process %d:", i + 1);
scanf("%d", &bt[i]);
}
// Initialize waiting time and turnaround time for the first process
wt[0] = 0; // First process has no waiting time
tt[0] = bt[0]; // Turnaround time is equal to burst time for the first process
// Calculate waiting time and turnaround time for all processes
for (i = 1; i<n; i++) {
wt[i] = wt[i - 1] + bt[i - 1];
tt[i] = wt[i] + bt[i];
}
// Calculate total waiting time and turnaround time
for (i = 0; i < n; i++) {
w1 += wt[i];
t1 += tt[i];
}
// Calculate average waiting and turnaround times

aw = (float)w1 / n;
at = (float)t1 / n;
// Display results
printf("\nBT\tWT\tTT\n");
for (i = 0; i <n; i++) {
printf("%d\t%d\t%d\n", bt[i], wt[i], tt[i]);
}
printf;("\nAverage Waiting Time: %.2f\n", aw);
printf("Average Turnaround Time: %.2f\n", at);
}
