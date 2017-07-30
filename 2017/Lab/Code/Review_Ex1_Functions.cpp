#include<stdio.h>
#include<math.h>
#define pi 3

int Vcube(int a);
int Vcylinder(int r,int h);
int Vcone(int r,int h);
int Vsphere(int r);
int Vellipsoid(int a,int b,int d);
int Vtorus(int r,int R);
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
	printf("Volume of the cube is:%d",Vcube(a));
	break;

case 101:
		printf("Cylinder component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("r=");
	scanf("%d",&r);
	printf("h=");
	scanf("%d",&h);
	printf("Volume of the cylinder is:%d",Vcylinder(r,h));
	break;
	case 102:
		printf("Cone component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("r=");
	scanf("%d",&r);
	printf("h=");
	scanf("%d",&h);
	printf("Volume of the cone is:%d",Vcone(r,h));
	break;
	case 103:
		printf("Sphere component is selected.\n");
	//volume calculation
	printf("Please enter the required values\n");
	printf("r=");
	scanf("%d",&r);
	printf("Volume of the sphere is:%d",Vsphere(r));
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
	printf("Volume of the ellipsoid is:%d",Vellipsoid(a,b,d));
	break;
	case 105:
		printf("Torus component is selected.\n");
		printf("Please enter the required values\n");
	//volume calculation
	printf("R=");
	scanf("%d",&R);
	printf("r=");
	scanf("%d",&r);
	printf("Volume of the torus is:%d",Vtorus(R,r));
	break;
default:
	printf("Invalid component code!");

}
}

int Vcube(int a){
	return pow(a,3);
}
int Vcylinder(int r,int h){
	return pi*pow(r,2)*h;
}
int Vcone(int r, int h){
	return (pi*pow(r,2)*h)/3;
}
int Vsphere(int r){
	return (4/3)*pi*pow(r,3);
}
int Vellipsoid(int a,int b,int d){
	return (4/3)*pi*a*b*d;
}
int Vtorus(int r,int R){
	return 2*pow(pi,2)*R*pow(r,2);
}
