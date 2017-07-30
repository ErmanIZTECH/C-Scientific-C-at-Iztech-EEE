#include<stdio.h>
#define TRUE 1
#define FALSE 0
int find_interval(
                  double (*f)(double), 	/*Function*/
                  double xstart,		/*Start of Search*/
                  double xend,			/*end	of search*/
                  double stepsize,		/*Interval of search*/
                  double *xleft,		/*Pointer to Left  of found interval*/
                  double *xright)		/*Pointer to right of found interval*/
{
    int found_root = TRUE;				/*Inýtialize indicator*/

/*___Initialize interval___*/
    *xleft=xstart;
    *xright= *xleft + stepsize;

/*___Search Interval___*/

	while(*xleft<xend && f(*xleft)*f(*xright)>0.0)
    {
        *xleft = *xright;
        *xright += stepsize;
        if(*xright>xend)    *xright=xend;
    }

/*___Chech if root found___*/
	if(f(*xleft) * f(*xright)> 0.0)
        found_root=FALSE;
    return (found_root);
}

int main(int argc, char **argv)  //**argv :Ragged array (birden fazla pointer iceren bir pointer.// Command line arguments
{                                //argc kaç argüman girileceðini

    double x1,x2;
    double polycubic(double),xstart,xend,stepsize;
    int find_interval(double (*f)(double),double,double,double,double *,double *);
    xstart=-10;
    xend=10;
    stepsize=0.2;

    x2=xstart;

    while(x2<xend)
    {
        if( find_interval(polycubic, xstart,xend,stepsize,&x1,&x2) )
        printf("Root is aproximately = %7.3lf\n",(x1+x2)/(2-(stepsize*0.5)));
         else
        printf("No more interval include root could found.\n");
        xstart=x2;
    }


}

double polycubic(double x)
{
    return((x*x*x) -7*x*x +36 );
}
