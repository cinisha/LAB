#include<stdio.h>
int main() {
int i, j, pno[10], prior[10], bt[10], n, wt[10], tt[10], w1 = 0, t1 = 0, temp;
float aw, at;
// Input number of processes
printf("Enter the number of processes: " );
scanf("%d", &n);
// Input burst time and priority for each process
for (i = 0; i < n; i++) {
printf("The process %d: ", i + 1);
printf("Enter the burst time: ");
scanf("%d", bt[i]);
printf("Enter the priority: ");
scanf("%d", prior[i]);
pno[i] = i + 1; // Process number
}
// Sort processes by priority (lower value = higher priority)
for (i = 0; i < n - 1; i++) {
for (j = i + 1; j < n; j++) {
if (prior[i] >prior[j]) {
// Swap priority
temp = prior[i];
prior[i] = prior[j];
prior[j] = temp;
// Swap burst time
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
// Swap process number
temp = pno[i];
pno[i] = pno[j];
pno[j] = temp;
}
}
}
// Calculate waiting time and turnaround time
wt[0] = 0; // Waiting time for the first process is 0
tt[0] = bt[0]; // Turnaround time for the first process is its burst time
w1 = wt[0];
t1 = tt[0];

for (i = 1; i < n; i++) {
wt[i] = wt[i - 1] + bt[i - 1];
tt[i] = wt[i] + bt[i];
w1 += wt[i];
t1 += tt[i];
}
// Calculate averages
aw = (float)w1 / n;
at = (float)t1 / n;
// Print results
printf("\n Job \t BT \t WT \t TAT \t Priority\n");
for (i = 0; i < n; i++) {
printf( "%d \t %d \t %d \t %d \t %d\n", pno[i], bt[i], wt[i], tt[i], prior[i]);
}
printf("\nAverage Waiting Time: %.2f", aw);
printf("\nAverage Turnaround Time: %.2f\n", at);
return 0;
}
