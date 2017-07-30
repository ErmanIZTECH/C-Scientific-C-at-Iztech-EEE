#include <stdio.h>

int main() 
{
int m1[100][100],m2[100][100],ans[100][100],dim[2][2]; // Maximum sizes are 100x100
int i,j,k,sum; 
dim:
printf("\n\t\tMultiplication of 2 Matrices\n");
	for(i=1;i<3;i++)			//Taking the Dimesions
		{
		for(j=1;j<3;j++){
		printf("Enter The Dimensions of the Matrice number %d:\t",i);
		scanf("%d",&dim[i-1][j-1]);
		}
	printf("\n");
}
	if(dim[0][1]!=dim[1][0])     //Checks if the Dimensions are appropirate.!!
	{
		printf("Your dimensions are not appropirate\nyou can only multiply MxN matrice with NxB matrice\n");
		goto dim;
	}
	for(i=1;i<=dim[0][0];i++){					//taking Matrix inputs
		for(j=1;j<=dim[0][1];j++){
		printf("Enter the row #%d values of the 1st matrice :\t",i);
		scanf("%d",&m1[i-1][j-1]);

	}printf("\n");
	}
		for(i=1;i<=dim[1][0];i++){
		for(j=1;j<=dim[1][1];j++){
		printf("Enter the row #%d values of the 2nd matrice :\t",i);
		scanf("%d",&m2[i-1][j-1]);

	}printf("\n");
	}
	sum=0;
	printf("\t\tAnswer Matrice\n------------------------------\n");
	
	for(i=0;i<dim[0][0];i++) //The Matrix Multiplication Part of the program
	{
				printf("\t");
		for(j=0;j<dim[1][1];j++)
		{		

			for(k=0;k<dim[0][1];k++)
			{
				sum+= m1[i][k] * m2[k][j];
				
			}
				ans[i][j]=sum;				
				printf("%d\t",ans[i][j]);
				sum=0;
		}
		printf("\n");
	}
	
	return 0;
}

