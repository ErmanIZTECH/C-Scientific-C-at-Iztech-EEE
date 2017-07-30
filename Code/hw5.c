/**
*       Author: Erman OL�AY
*       Purpose: Homework 5
*       Funciton: takes minimum differance and epsilon finds roots using newton method.
*                                                         __dMin ___Epsilon  _____This part Polynomial Coefficients from least to most
*                                       Usage: E:\hw5.exe 10e-30 0.000000001 2 -3.5 -3 3.5 1
*
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double coeff[100]={0};
int power;


double newton(double (*f)(double), double (*fprime)(double), double dMin, double xstart, double epsilon,int *error)
{
    double delta,x1,x0,find=0;
   delta = 2*epsilon;
   //if(xstart==(-4.5000))
   // find=1;

    *error=0;

   while( !(*error) && fabs(delta)>epsilon  )
    {
        if( (fabs(fprime(xstart)))> dMin )
            {
                delta = (f(xstart))/(fprime(xstart));

                if(find==1)
                    printf("%.5lf=%lf-%lf\n",xstart - delta,xstart,delta);

                xstart = xstart - delta;


            }
            else
                *error=1;
    }


    x1=xstart;
    //printf("error=%d\n",*error);
    return (xstart);
}


double f(double x);
double fprime(double x);

int main(int argc, char **argv)
{

	   int error=0,i,j,k=0;
	   double dMin, xstart,epsilon,step;
	   int size;

	dMin =atof(argv[1]);
	xstart=-10;
	step=0.5;
	size= (((fabs(2 * xstart))/step));

	double root[40]={0},Rroot[40]={0};
	epsilon=atof(argv[2]);
power = argc - 4;
printf("\npower=%d\n",power);
for(j=0;j<=power;j++)
    coeff[j]=atof(argv[j+3]);

    int sameOrNot;
	for(i=0; i<=40; i++)
        {
            sameOrNot=0;
            root[i]=newton(f,fprime,dMin,xstart,epsilon,&error);                        /** Finds A Root                            */


           // printf("I have found Root : %lf\n",root[i]);
            for(j=0;j<i;j++)                                                            /** Checks If root has been found before    */
                if(  fabs(root[i]-root[j])<0.1 )                                         /** Checks if the Recently found root is    */
                    sameOrNot=1;                                                        /** 0.1 close to any root found before      */
                if(error==0 && sameOrNot==0){                                                       /** If SameOrNot=False Prints Root          */
                    printf("error : %d\n",error);
                    printf("Root : %lf\n",root[i]);
                    Rroot[k]=root[i];
                    k++;}

            xstart= (xstart+0.5);
          //  printf("Xstart : %lf\n",xstart);
        }
int z;                                                                                  /** This part Prints found Roots to txt     */
FILE * fp;
fp=fopen("2017_HW5_220206059_result.txt", "w+");

for(z=0;z<k;z++)
fprintf(fp,"%s %d %s %lf \n","Root",z+1,"is",Rroot[z]);

fclose(fp);


}

double f(double x)
{double y=0;
    y= (pow(1+exp(x),-1)) -0.5;
    return(y);
}
double fprime(double x)
{double y=0;
y= (-1) * (exp(x)) * (pow(exp(x)+1,-2));
    return(y);
}
/*
double f(double x)
{   int i;
    double y=0;

    for(i=0;i<=power;i++)
        y += coeff[i] * pow(x,i);

return ( y );//x*x + 3.31*x -5.44);
}


double fprime(double x)
{   int i;
    double y=0;

    for(i=0;i<power;i++)
        y += coeff[i+1]*(i+1)*pow(x,i);

return ( y );// 2*x +3.31);
}
//*/