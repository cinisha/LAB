//newtop rapshon
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) x*x*x*x -x-10
#define g(x)  4*x*x*x-1

void main(){
	float x1, x2, x3, f1, g1, e;
	int step=1;
	
	up:
	
	printf("\nEnter ine initial guesses:\n");
	scanf("%f", &x1);
	
	printf("Enter  tolerable error:\n");
	scanf("%f", &e);
	
	f1 = f(x1);
	g1 = g(x1);
	
	if(f1<0.0){
		printf("Incorrect Initial Guesses.\n");
		goto up;
	}
	
	printf("\nstep\t\tx1\t\tf(x1)\t\tg(1)\t\tx2\n");
	do{
	
	x2 = x1 - (f1/g1);
	
	printf("%d\t\t%f\t%f\t%f\t%f\n",step,x1,f1,g1,x2);
	
	step=step+1;
	x1=x2;
	f1=f(x1);
	g1=g(x1);
	}while(fabs(f1)>e);
	printf("\nRoot is: %f", x2);
	getch();
}
