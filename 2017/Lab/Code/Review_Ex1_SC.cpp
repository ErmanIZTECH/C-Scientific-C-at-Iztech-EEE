#include<stdio.h>
#include<math.h>
#define pi 3
int main(){
	
	int c[ 6 ] = { 100, 101, 102, 103, 104, 105};
	const char* sh[6 ] = { "Cube", "Cylinder", "Cone","Sphere","Ellipsoid","Torus"};
	int i;
	int code, a, r,h,b,d,R, V;
	
	printf( "%s%20s\n", "Component Code", "Component Shape" );
	
	
	for ( i = 0; i < 6; ++i ) {
       printf( "%7u%25s\n", c[ i ],sh[ i ] );
       
}
printf("Select a component using the code:");
scanf("%d",&code);

switch (code){

 case 100:
	printf("Cube component is selected.\n");
	//volume calculation
	printf("Please enter the length of a side of the cube=");
	scanf("%d",&a);
	V=pow(a,3);
	printf("Volume of the cube is:%d",V);
	break;

case 101:
		printf("Cylinder component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("r=");
	scanf("%d",&r);
	printf("h=");
	scanf("%d",&h);
	V=pi*pow(r,2)*h;
	printf("Volume of the cylinder is:%d",V);
	break;
	case 102:
		printf("Cone component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("r=");
	scanf("%d",&r);
	printf("h=");
	scanf("%d",&h);
	V=(pi*pow(r,2)*h)/3;
	printf("Volume of the cone is:%d",V);
	break;
	case 103:
		printf("Sphere component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("r=");
	scanf("%d",&r);
	V=(4/3)*pi*pow(r,3);
	printf("Volume of the sphere is:%d",V);
	break;
	case 104:
		printf("Ellipsoid component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("d=");
	scanf("%d",&d);
	V=(4/3)*pi*a*b*d;
	printf("Volume of the ellipsoid is:%d",V);
	break;
	case 105:
		printf("Torus component is selected.\n");
		printf("Please enter the required values\n");
	//volume calculation
	printf("R=");
	scanf("%d",&R);
	printf("r=");
	scanf("%d",&r);
	V=2*pow(pi,2)*R*pow(r,2);
	printf("Volume of the torus is:%d",V);
	break;
default:
	printf("Invalid component code!");

}
}
