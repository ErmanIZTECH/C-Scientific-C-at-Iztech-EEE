#include<math.h>
#include<stdio.h>
#include<stdlib.h>
double f1(double x);
double f2(double x);
double f3(double x);
double fln(double x);
double simpson(double (*f)(double),double a,double b,int n)
{
    double ans,h;
    double x;
    int i;
    ans=f(a);
    h= (b-a)/n;
    for(i=1;i<=n;i++)
    {
        x= a+(i*h);
        ans = ans + 4*f(x-h/2) + 2*f(x);

    }
    ans = ans-f(b);
    return (h*ans/6);
}
double trapz(double (*f)(double),double a,double b,int n)
{
    double ans,h;
    int i;
    ans = f(a)/2;
    h = (b-a)/n;

    for(i=1; i<=n; i++)
        ans=ans+ f(a+ i*h );
    ans=ans- f(b)/2;

    return(h*ans);
}
int main(int argc,char **argv)
{
    double trapz(double (*)(double),double,double,int);
    double a=0.0,b=2.0,anss,anst,ans;
    int n=10,sel;
    printf("argc=%d\n",argc);
    if( argc>2 )
    {
        a=atof(argv[1]);
        b=atof(argv[2]);
        n=atoi(argv[3]);
        sel=atoi(argv[4]);
    }
    else if(argc==1)
    {
    printf("Enter the function number you want to calculate (1, 2 or 3)?");
    scanf("%d",&sel);
    printf("Enter the starting point?");
    scanf("%lf",&a);
    printf("Enter the end point?");
    scanf("%lf",&b);
    printf("Enter the line width?");
    scanf("%d",&n);
    }
    switch(sel)
    {
        case 1:
            printf("Area of func1 Calculated with Trapezoidal method is=%f",ans=trapz(f1,a,b,n));
        break;
        case 2:
            printf("Area of func2 Calculated with Trapezoidal method is=%f",ans=trapz(f2,a,b,n));
        break;
        case 3:
            printf("Area of func3 Calculated with Trapezoidal method is=%f",ans=trapz(f3,a,b,n));
        break;
        case 4:
            printf("\nArea of Logaritmic Calculated with Trapezoidal method is=%f",anst=trapz(fln,a,b,n));
            printf("\nArea of Logaritmic Calculated with Simpson method is=%f",anss=simpson(fln,a,b,n));
            break;
        default :
            printf("Wrong number\n");
            break;

    }

FILE * fp;
fp=fopen("2017_HW6_220206059_result.txt", "w+");

fprintf(fp,"%s %s %s\n","a\t","b\t","Answer");
fprintf(fp,"%.3f\t%.3f\t%.3f\n",a,b,ans);

fclose(fp);






}
double fln(double x)
{
    double y=0.0;
    y = 8 - log( pow(x,2) - 2*x + 4 );
    return(y);
}

double f1(double x)
{
    double y=0.0;
    y = cos(pow(x,2)) + 2*pow(x,3);
    return(y);
}
double f2(double x)
{
    double y=0.0;
    y = 2/(1+pow(x,2));
    return(y);
}
double f3(double x)
{
    double y=0.0;
    y = x - 3;
    return(y);
}
