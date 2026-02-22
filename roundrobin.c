#include<stdio.h>
int main() {
int st[10], bt[10], wt[10], tat[10], n, tq;
int i, count = 0, swt = 0, stat = 0, temp, sq = 0;
float awt = 0.0, atat = 0.0;
// Input number of processes
printf("Enter number of processes: ");
scanf("%d", &n);
// Input burst times
printf("Enter burst time for each process:\n");
for (i = 0; i < n; i++) {
printf("Process %d: ", i + 1);
scanf("%d",bt[i]);
st[i] = bt[i]; // Initialize remaining burst time
}
// Input time quantum
printf("Enter time quantum: ");
scanf("%d",&tq);
// Round Robin Scheduling
while (1) {
count = 0;
for (i = 0; i < n; i++) {
temp = tq;
if (st[i] == 0) {
count++;
continue;
}
if (st[i] > tq) {
st[i] -= tq;
} else {
temp = st[i];
st[i] = 0;
}
sq += temp;
tat[i] = sq; // Calculate Turnaround Time
}
if (count == n)
break;
}
// Calculate Waiting Time and Totals

for (i = 0; i <  n; i++) {
wt[i] = tat[i] - bt[i];
swt += wt[i];
stat += tat[i];
}
// Calculate Averages
awt = (float)swt / n;
atat = (float)stat / n;
// Print Results
printf("\nProcess_no Burst_time Wait_time Turnaround_time");
for (i = 0; i < n; i++) {
printf("\n %d %d %d %d", i + 1, bt[i], wt[i], tat[i]);
}
printf("\n\nAverage Wait Time: %.2f&", awt);
printf("\nAverage Turnaround Time: %.2f\n", atat);
return 0;
}
