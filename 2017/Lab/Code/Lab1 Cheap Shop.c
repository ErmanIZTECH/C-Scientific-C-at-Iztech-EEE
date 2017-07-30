
#include <stdio.h>
float FMAT (float out[100][100],float m1[100][100],float m2[100][100],float m3[100][100],int NR[3][2]);
float ADDMAT (float outf[100][100],float m1[100][100],float m2[100][100],int NR[3][2]);
int main()
{
float m1[100][100],m2[100][100],m3[100][100],ans[100][100];
int dim[3][2];
int i,j,k,sum;
beg:
printf("\n\t\tWhich Shop you should go?\n");
	for(i=1;i<4;i++)			//Taking the Dimesions
		{
		for(j=1;j<3;j++){
		printf("Enter The Dimensions of the Matrice number %d:\t",i);
		scanf("%d",&dim[i-1][j-1]);
		}
	printf("\n");
}
	if(dim[0][1]!=dim[1][0] || dim[0][0]!=dim[2][0] || dim[1][1]!=dim[2][1])     //Checks if the Dimensions are appropirate.!!
	{
		printf("Your dimensions are not appropirate\n");
		goto beg;

	}
	for(i=1;i<=dim[0][0];i++){					//taking 1st Matrix inputs
		for(j=1;j<=dim[0][1];j++){
		printf("Enter the row #%d values of the 1st matrice :\t",i);
		scanf("%f",&m1[i-1][j-1]);
	}printf("\n");
	}
	for(i=1;i<=dim[1][0];i++){					//taking 2nd Matrix inputs
		for(j=1;j<=dim[1][1];j++){
		printf("Enter the row #%d values of the 2nd matrice :\t",i);
		scanf("%f",&m2[i-1][j-1]);
	}printf("\n");
	}
		for(i=1;i<=dim[2][0];i++){					//taking 3rd Matrix inputs
		for(j=1;j<=dim[2][1];j++){
		printf("Enter the row #%d values of the 3rd matrice :\t",i);
		scanf("%f",&m3[i-1][j-1]);
	}printf("\n");
	}

float out[100][100],outf[100][100];
float mult[100][100];
float cost[100][100];


FMAT(out,m1,m2,m3,dim);
ADDMAT(outf,out,m3,dim);

	for(i=0;i<dim[0][0];i++)
	{
		for(j=0;j<dim[2][1];j++)
		{
			printf("%f\t",outf[i][j]);
}
printf("\n");
}
int shop,per;
float smallest;

for(i=0;i<dim[0][0];i++)
	{smallest=99999999999;
		for(j=0;j<dim[2][1];j++)
		{
			if(outf[i][j]<smallest)
			{
				smallest=outf[i][j];
				per=i+1;
				shop=j+1;
			}

		}
	printf("For person %d shop%d is cheapest\n",per,shop);
	}
printf("\n");


return 0;
}

float (*FMAT (float A[100][100],float B[100][100],int Row1,int Col1,int Col2))[100]/**The Matrix Multiplication FUNCTION*/
	{
	    /** Call this func. as ----->      float (*T)[100]=FMAT(a,b,row_1,col_1,col_2)           */
	    float sum,out[100][100];
        int i,j,k;
        sum=0;
        for(i=0;i<Row1;i++)
        {
            for(j=0;j<Col2;j++)
            {
                for(k=0;k<Col1;k++)
                {
				sum+= A[i][k] * B[k][j];
                }
            out[i][j]=sum;
			sum=0;
            }
        }
	return out;
}

float ADDMAT (float outf[100][100],float m1[100][100],float m2[100][100],int NR[3][2])
{
	int i,j,k;
	for(i=0;i<NR[2][0];i++) //The Matrix Multiplication Part of the program
	{
		for(j=0;j<NR[2][1];j++)
		{
		outf[i][j]=m1[i][j]+m2[i][j];
	}
}
return (outf[100][100]);
}

