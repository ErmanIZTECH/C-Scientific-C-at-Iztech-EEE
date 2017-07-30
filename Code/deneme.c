#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void f(double x);
int main (int argc,char **argv)
{   double x=0;
    x=atof(argv[1]);
    printf("\nmain %s",argv[1]);
    f(x);
}

void f(double x)
{
    printf("\nfunc %.2f",x);
}
