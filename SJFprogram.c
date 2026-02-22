
#include<stdio.h>
void main(){
	int i,j,n,t;
	int bt[10], wt[10], tt[10], w1=0, t1=0;
	float aw, at;
	printf("Enter number of process:\n");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter the brust time of process %d:", i+1);
		scanf("%d", &bt[i]);
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(bt[i] > bt[j]){
				t= bt[i];
				bt[i]= bt[j];
				bt[j]= t;
			}
		}
	}
	wt[0]= 0;
	tt[0]= bt[0];
	w1= 0;
	t1= tt[0];
	for(i=1; i<n; i++){
		wt[i]= wt[i-1]+bt[i-1];
		tt[i]= wt[i]+bt[i];
		w1 += wt[i];
		t1 += tt[i];
	}
	aw = (float)w1/n;
	at = (float)t1/n;
	printf("\n bt \t wt \t tt \n");
	for(i=0; i<n; i++){
		printf("%d \t %d \t %d \n", bt[i], wt[i], tt[i]);
	}
	printf("\n Average waiting time: %.2f \n",aw);
	printf("\n Average Trunaround time: %.2f \n",at);
}
