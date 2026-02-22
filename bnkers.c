#include <stdio.h>
int max[10][10], alloc[10][10], need[10][10], avail[10], finish[10] = {0};
int p, r; // Number of processes and resources
void fun(); // Function prototype
int main() {
int i, j, flag = 0;
printf("\n\nSIMULATION OF DEADLOCK PREVENTION\n");
// Input number of processes and resources
printf("Enter the number of processes and resources:" );
scanf("%d%d", &amp;p, &amp;r);
// Input allocation matrix

printf("Enter allocation matrix:\n");
for (i = 0; i < p; i++) {
for (j = 0; j <r; j++) {
scanf("%d", &amp;alloc[i][j]);
}
}
// Input maximum matrix
printf(&quot;Enter maximum matrix:\n&quot;);
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
scanf("%d", &amp;max[i][j]);
}
}
// Input available matrix
printf("Enter available matrix:\n");
for (i = 0; i < r; i++) {
scanf("%d", &amp;avail[i]);
}
// Calculate need matrix
for (i = 0; i &lt; p; i++) {
for (j = 0; j &lt; r; j++) {
need[i][j] = max[i][j] - alloc[i][j];
}
}
fun(); // Check for deadlock
// If deadlock occurs, try to prevent it by addressing conditions
for (i = 0; i &lt; p; i++) {
if (finish[i] != 1) { // Process not finished
printf(&quot;\n\nFailing: Mutual Exclusion&quot;);
for (j = 0; j &lt; r; j++) { // Check for mutual exclusion
if (avail[j] &lt; need[i][j]) {
avail[j] = need[i][j];
}
}
fun();
printf(&quot;\nBy allocating required resources to process %d, deadlock is prevented.&quot;, i);
printf(&quot;\n\nFailing: Lack of Preemption&quot;);
for (j = 0; j &lt; r; j++) { // Address preemption
if (avail[j] &lt; need[i][j]) {
avail[j] = need[i][j];
}
alloc[i][j] = 0; // Deallocate resources
}
fun();
printf("\nDeadlock is prevented by allocating needed resources.");

printf("\n\nFailing: Hold and Wait Condition");
for (j = 0; j &lt; r; j++) { // Check hold and wait
if (avail[j] &lt; need[i][j]) {
avail[j] = need[i][j];
}
}
fun();
printf("\nAvoiding any one of the conditions, you can prevent deadlock.");
}
}
return 0;
}
// Function to check for a safe sequence and process completion
void fun() {
int flag, i, j;
while (1) {
flag = 0;
for (i = 0; i < p; i++) {
if (finish[i] == 0) { // Process not yet finished
for (j = 0; j < r; j++) {
if (need[i][j] &gt; avail[j]) {
break; // Resources not available
}
}
if (j == r) { // All resources are available
for (j = 0; j< r; j++) {
avail[j] += alloc[i][j];
}
finish[i] = 1;
flag = 1; // Progress made
}
}
}
if (flag == 0) { // No progress, exit
break;
}
}
}
