#include <stdio.h>
#include <math.h>
#define pi 3.14

#define f(v0) (v0)*(v0)*(sin((q)*(pi)/180))*(sin((q)*(pi)/180))-2*(g)*(h)
#define fprime(v0) 2*(v0)*(sin((q)*(pi)/180))*(sin((q)*(pi)/180))

#define function(v0) 2*(v0)-(f(v0)/fprime(v0))

#define TRUE 1
#define FALSE 0

double startPoint,endPoint,stepSize,nowLeft,nowRight,h,g,q,epsilon=0.0001,initial,dmin=0.001;
int flag;

double newton(double h,double g, double q,double x0, double epsilon)
{
	double deltax;
	deltax = 2.0 * epsilon;
	flag = FALSE;
	while( !(flag) && fabs(deltax) > epsilon){
	
		if(fabs(fprime(x0)) > dmin)
		{  
			deltax = f(x0)/fprime(x0);
			x0=x0-deltax;
		}
		else
			flag = TRUE;
	}
	return(x0);
	
	
	
	
}

double bisection(double h,double g, double q,double x1, double x2, double epsilon)
{
	double y;
	for(y=(x1+x2)/2.0; fabs(x1-y)>epsilon; y=(x1+x2)/2.0){
		printf("%lf\n",y);
	if(f(x1)*f(y)<=0.0){
		x2=y;
	//	printf("%asdasdlf",x2);
	}
		else {
		x1=y;
	//	printf("\nasdasdas%lf",x1);
	}
	//printf("\n\n\n%lf",y);
	return(y);
}
}

void getValues(){
	printf("\nPlease,Enter an value starting point for interval\t");
	scanf("%lf",&startPoint);
	printf("\nPlease,Enter an value ending point for interval\t");
	scanf("%lf",&endPoint);
	printf("\nPlease,Enter stepsize\t");
	scanf("%lf",&stepSize);
	
	printf("\n Enter h");
	scanf("%lf",&h);
	printf("\n Enter g");
	scanf("%lf",&g);
	printf("\n Enter angle"); // theta
	scanf("%lf",&q);
}
double findRoot(double h,double g, double q, double startPint, double endPoint, double stepSize){
	nowLeft=startPoint;
	nowRight=startPoint+stepSize;
	int control=0;
	while(nowLeft<endPoint){
		if(function(nowLeft)*function(nowRight)<0){
			control=1;
			printf("\nRoot Found %lf  -  %lf",nowLeft,nowRight);
			bisection(h,g,q,nowLeft,nowRight,epsilon);
		}
			initial=bisection(h,g,q,nowLeft,nowRight,epsilon);
		//	printf("\n\n\n%lf",&root);
		nowLeft=nowRight;
		nowRight+=stepSize;
		if(nowRight>endPoint)
			nowRight=endPoint;
	}
	if(control==0)
		printf("\nNo Root Found");
}
int main(){
	getValues();
	findRoot(h,g,q,startPoint,endPoint,stepSize);
	
	
		double root;
	int flag;
	
	double dmin=10e-10; 

	
    root = newton(h,g,q,initial,epsilon);
	if(flag)
		printf("Error\n");
	else
		printf("value of root is %lf\n",root);
}
