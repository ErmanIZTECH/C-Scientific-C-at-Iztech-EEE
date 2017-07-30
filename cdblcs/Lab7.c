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
    double xi,yi,hi,xend;
    double yeul,yrkt,yexact;
    printf("\nEnter Xinitial:");
    scanf("%lf",&xi);
    printf("\nEnter Yinitial:");
    scanf("%lf",&yi);
    printf("\nEnter h size:");
    scanf("%lf",&hi);
    printf("\nEnter Xend:");
    scanf("%lf",&xend);
    yexact=euler(xi,yi,g,0.00001,xend);
    yeul=euler(xi,yi,g,hi,xend);
    yrkt=runge(xi,yi,g,hi,xend);

    double errEul,errRkt;

        errEul= fabs(errorf(yexact,yeul));
        errRkt= fabs(errorf(yexact,yrkt));

        printf("\ny_exact=%f",yexact);
        printf("\ny_euler=%f",yeul);
        printf("\ny_rkt=%f",yrkt);
        printf("\nError of euler=%f percent and Error of RKT=%f",errEul,errRkt);

return 0;
}

double g(double x,double y)
{
      double g;
      g = 4*x + y -3;

      return(g);
}
