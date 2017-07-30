#include <stdio.h>
#include <math.h>
/* The algorithm is x(n+1) = x(n) - f(x(n)) / f'(x(n))
This method fails when the tangent line is parallel to x axis which the derivative is infinite. */
float dmin,epsilon,coefficient[10],foundroot[10];
int polydegree;
float newton(float (*f)(float),float (*fprime)(float),float dmin,float x0,float epsilon,int *error);
float fprime(float (*f)(float), float x0);
float f(float x);
int main(int argc,char *argv[])
{
	dmin=atof(argv[1]);
	epsilon=atof(argv[2]);
	polydegree=(argc-3);
	int i,indicator;
	for(i=0;i<=(argc-3);i++)
	{
		coefficient[i]=atof(argv[i+3]); //coeff0 deðeri benim argv3 deðerim yani x^0 katsayýsý
	}
	float foundroot,x0=5;
	foundroot=newton(f,fprime,dmin,x0,epsilon,&indicator);
	printf("%f",foundroot);
}

float newton(float (*f)(float),float (*fprime)(float),float dmin,float x0,float epsilon,int *error)
{
	float deltax;
	deltax=2.0*epsilon;
	*error=0;
	while(!(*error) && fabs(deltax) > epsilon)
	{
		if(fabs(fprime(x0))>dmin)
		{
			deltax=f(x0)/fprime(x0);
			x0-=deltax;
		}
		else
		{
			*error=1;
		}
	}
	return (x0);
}


float fprime(float x0)
{
    const float delta = 10e-30;
    float x1 = x0 - delta;
    float x2 = x0 + delta;
    float y1 = f(x1);
    float y2 = f(x2);
    return ((y2 - y1) / (x2 - x1));
}

float f(float x)
{
	int i;
	float y=0;
	for(i=0;i<polydegree;i++)
	{
		y+=coefficient[i]*pow(x,i);
	}
	return y;
}

/*argv3 xüzeri 0
argv4 xüzeri 1
argv5 xüzeri 2*/
