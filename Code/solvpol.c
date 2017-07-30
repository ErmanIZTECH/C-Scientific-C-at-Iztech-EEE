/**
*       Author      :   Erman OLCAY
*       Date        :   28.03.2016
*       Description :   Polynomial Solver
*       Parameters  :   Finds root of any real root function defined at function "f"
*                       argument values are :"start,stop,tolerance,iteration"
*                       execute program from command line _example.\>solvpol -100   100  0.01 		15
*																			 from    to  tolerance  iteration
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include<time.h>
#include<windows.h>
#define TRUE 1
#define FALSE 0

double coeff[]={0};
int power;
double f(double x);
int find_interval(double (*f)(double),double xstart,double xend,double stepsize,double *xleft,double *xright)
{
    //printf("\nInterval %f,%f\n",xstart,xend);
    int found_root = TRUE;				/*Initialize indicator*/

/*___Initialize interval___*/
    *xleft=xstart;
    *xright= *xleft + stepsize;

/*___Search Interval___*/

	while(*xleft<xend && f(*xleft)*f(*xright)>0.0)
    {
        *xleft = *xright;
        *xright += stepsize;
        if(*xright>xend)
            *xright=xend;
    }

/*___Chech if root found___*/
	if(f(*xleft) * f(*xright) > 0.0)
        found_root=FALSE;
    return (found_root);
}

double bisect(double (*f)(double),double xstart,double xend,double epsilon,int iteration)
{
    //printf("\nBisect %f,%f\n",xstart,xend);
	double midval;
	int it;
    it=iteration;
    midval=(xstart+xend)/2;
            if(fabs(xstart-midval)>epsilon && it!=0)
                if( f(xstart)*f(midval) <=0 )
                {
                    midval=bisect(f,xstart,midval,epsilon,it-1);
                }
                else
                {
                    midval=bisect(f,midval,xend,epsilon,it-1);
                }
return midval;
}

int main(int argc, char **argv)
{
    clock_t tic = clock();
    Sleep(1000);

	power=atoi(argv[1]);
int j;
for(j=0;j<=power;j++)
{
    coeff[j]=atof(argv[j+2]);
}

	int iteration,n,i;
	double stepsize,xstart,xend,x1,x2,epsilon;
	double root[argc];
	//n=atof(argv[1]);
	xstart= -10;//atof(argv[1]);
	xend=10;//atof(argv[2]);
	epsilon=0.00001;//atof(argv[3]);
	iteration=50;//atof(argv[4]);

    stepsize= 0.5;
    //x2=xstart+stepsize;

    i=0;
    while(i<=power)
    {
        if( find_interval(f,xstart,xend,stepsize,&x1,&x2) )
            {
            root[i]=bisect(f,x1,x2,epsilon,iteration);
            printf("\nFound root #%d =%8.4lf \n",1+i,root[i]);
            Sleep(100);
            xstart=root[i]+stepsize;
            //root[i+1]=root[i]+ 10*epsilon;
            i++;
            }
        else
            {
            printf("\nNo more root found.\n\n");
            break;
            }
    }
clock_t toc = clock();
printf("Elapsed time to find all roots = %f seconds\n", (((double)(toc - tic) / CLOCKS_PER_SEC) -1.0 -0.1*power ) );
}

double f(double x)
{   int i;
    double y=0;

    for(i=0;i<=power;i++)
        y += coeff[i]*pow(x,i);

return (y); //coeff[6]*x*x*x*x*x*x +coeff[5]*x*x*x*x*x +coeff[4]*x*x*x*x +coeff[3]*(x*x*x) + coeff[2]*(x*x) +coeff[1]*x +coeff[0] );//( coeff[0]*x*x*x*x +coeff[1]*x +coeff[2] );//( 2*(x*x*x) -3*(x*x) -3*x +2 );//( x*x -4*x +3 );
    //return ( ( (x-2) * (x-2) ) -9 );

	//return ( x*x*x*x -30*(x*x*x) + 325*(x*x)-(1500*x)+2464 );

	//return ( (x*x*x)- 2*(x*x)-(9*x)+18 );
}


