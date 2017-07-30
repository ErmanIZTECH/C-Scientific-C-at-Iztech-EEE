#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x);

double bisect(double (*f)(double),double x1,double x2,double epsilon,int n,int iteration)
{
	double y;
	int it;
    it=iteration;
    printf("%d th iter.\n",it);
    y=(x1+x2)/2;

        if(fabs(n-f(y))>epsilon && it!=0)
            if( (f(x1)-n)*(f(y)-n) <=0 ){
                y=bisect(f,x1,y,epsilon,n,it-1);
            printf("root=%lf\n",y);
            }
            else{
                y=bisect(f,y,x2,epsilon,n,it-1);
            printf("root=%lf\n",y);
            }
return y;
}

int main(int argc, char **argv)
{
	int iteration,n=1,i;
	double x1,x2,epsilon;
	double root[50];

	n=atof(argv[1]);
	x1=atof(argv[2]);
	x2=atof(argv[3]);
	epsilon=atof(argv[4]);
	iteration=atof(argv[5]);

	/*
	printf("Please enter a constant number for equation:");
	scanf("%d",&n);
	printf("\n");
	printf("Please enter the start value:");
	scanf("%lf",&x1);
	printf("\n");
	printf("Please enter the end value:");
	scanf("%lf",&x2);
	printf("\n");
	printf("Please enter the convergence factor:");
	scanf("%lf",&epsilon);
	printf("\n");
	printf("Please enter the iteration number:");
	scanf("%d",&iteration);
	printf("\n");
	*/
    root[0]=x1;
for(i=0;i<2;i++){
    root[i]=bisect(f,root[i],x2,epsilon,n,iteration);
    printf("Found root #%d = %lf\n",i,root[i]);
    root[i]+=epsilon;
}
	//double bisect(double (*f)(double),double x1,double x2,double epsilon,int n,int iteration);
	//double equation(double,n);

}

double f(double x)
{
	return ( (x*x) );
}


