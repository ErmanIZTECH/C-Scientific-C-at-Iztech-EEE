/**
*       Author : Erman OLÇAY
*       Date   : 25.03.2017
*       Description: Homework 7
*       Parameters : Euler Diff eqn solver
*
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euler(double x0,double y0,double (*g)(double,double),double h,double xlast)
{
    for( ;x0<= xlast ;x0=x0+h)
    {
        y0 = y0 + h*g(x0,y0);
    }
    return(y0);
}
double errorf(double real,double found)
{
    double error;
    error=((real-found)/real)*100;
    return(error);
}
double runge(double x0,double y0,double (*g)(double,double),double h,double xlast)
{
    double ta,tb,tc,td;
    for(;x0<=xlast;x0=x0+h)
    {
        ta=h*g(x0,y0);
        tb=h*g(x0+h/2.0, y0+ta/2.0);
        tc=h*g(x0+h/2.0, y0+tb/2.0);
        td=h*g(x0+h, y0+tc);
        y0= y0 + (ta +2.0*tb +2.0*tc +td)/6.0;
    }
    return(y0);
}
double g(double x,double y);
int main(int argc, char **argv)
{
    int i,j,k;
    double size,x0[5]={0.1,0.2,0.3,0.4,0.5};
    double exact[5]={-2.21707,-1.91773,-1.6109,-1.3055,-1.0094};
    double y0[5][3];
    double h[3]={0.01,0.001,0.0001};


    for(i=0;i<5; i++){
        for(j=0;j<3;j++)
        {
        y0[i][j]=euler(0,-2.5,g,h[j],x0[i]);
        //printf("%15.6g %15.6g\n",x0[j],y0[j][i]);
        }
    //printf("\n");
    }

    double error[5][3];
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
        error[i][j]= fabs(errorf(exact[i],y0[i][j]));
        }
    }

printf("  x\texact value\teuler result(h=0.01)\teuler result(h=0.001)\teuler result(h=0.0001)");
printf("\n-------------------------------------------------------------------------------------------------");

FILE * fp;
fp=fopen("2017_HW7_220206059_result.txt", "w+");

for(i=0;i<5;i++)
{
printf("\n%.2lf \t  %.4lf       \t\t %.4lf      \t\t %.4lf      \t\t %.4lf",x0[i],exact[i],y0[i][0],y0[i][1],y0[i][2]);
}
fprintf(fp,"  x\texact value\teuler result(h=0.01)\teuler result(h=0.001)\teuler result(h=0.0001)\r");
fprintf(fp,"\n-------------------------------------------------------------------------------------------------\r");

for(i=0;i<5;i++)
{
fprintf(fp,"\n%.2lf \t  %.4lf \t\t %.4lf \t\t %.4lf \t\t %.4lf\r",x0[i],exact[i],y0[i][0],y0[i][1],y0[i][2]);
}

printf("\n\n  x\tpercentage error(h=0.01)\tpercentage error(h=0.001)\tpercentage error(h=0.0001)");
printf("\n-------------------------------------------------------------------------------------------------");

for(i=0;i<5;i++)
{
printf("\n%.2lf \t\t  %.4lf \t\t\t %.4lf \t\t\t %.4lf",x0[i],error[i][0],error[i][1],error[i][2]);
}
printf("\n");
fprintf(fp,"\n\r\n x\tpercentage error(h=0.01)\tpercentage error(h=0.001)\tpercentage error(h=0.0001)\r");
fprintf(fp,"\n-------------------------------------------------------------------------------------------------\r");

for(i=0;i<5;i++)
{
fprintf(fp,"\n%.2lf \t\t  %.4lf \t\t\t %.4lf \t\t\t %.4lf\r",x0[i],error[i][0],error[i][1],error[i][2]);
}

fclose(fp);
return 0;
}

double g(double x,double y)
{
      double g;
      g = exp(cos(x)) - y*sin(x);

      return(g);
}
