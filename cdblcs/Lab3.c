/**
*       Author : Erman OLÇAY
*       Date   : 17.03.2017
*       Description: Homework 3
*       Parameters : Gauss Jordan Solver wPivoting
*                    See code ongoing comment lines
*                    Change the pre entered Matrices
*                    Request them from user.
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
float determinant(float f[100][100], int x);
float (*FMAT (float A[100][100],float B[100][100],int Row1,int Col1,int Col2))[100];
main()
{   int i,j,k,n;
    //printf("Enter The Dimension of your Square Matrice:");
    //scanf("%d",&n);
    n=4;
    float det,c,A[100][100]={{7,-4,-3,0},{-4,32,-6,-12},{-3,-6,13,-4},{0,-12,-4,16}} ,AI[100][100],I[100][100],B[100][100]={{12},{0},{-20},{32}},C[100][100],ans[100];
/**printf("\nEnter Coefficient Matrice Elements:\n");
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter A[%d,%d]:",i,j);                      //Taking The Values of Matrix A
            scanf("%f",&A[i][j]);
        }}
*/
    det=determinant(A,n);                                       /**Calculate Determinant*/
    if(det==0)
    {
        printf("\n\t\t!!!!!YOUR MATRICE IS SINGULAR DET=%9.2f",det);
        return 0;
    }
    printf("DET(A)= %.2f\n",det);
/*    printf("Enter Right Hand Side Matrix B:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter B[%d]:",i);                                 //Taking The Values of Matrix B
      scanf("%f",&B[i][0]);
    }
*/

     printf("\nAugmented Matrix:\n");///Matrix Augmenter
    for(i=0; i<n; i++)
    {
        for(j=0; j<(2*n)+1; j++)
        {
            C[i][j]=A[i][j];
            if(i+n==j)
            {
                A[i][j]=1;              ///Write Identity Matrix Augmented to the Coefficient matrix
            }

            if(j==2*n)
            {
                A[i][j]=B[i][0];     ///Take B into the augmented matrix
            }

            printf("%8.2f",A[i][j]);
        }
    printf("\n");
    }

float big,temp;                                         //Pývoting
int y,h;
   for(j=0; j<n; j++)
    {
        big= -99;
        for(i=j; i<n; i++)
            if(A[i][j]>big)
            {
                y=i;
                big=A[i][j];
            }
            if(y!=j)
            for(k=0; k<(2*n)+1; k++)
            {
                temp=A[j][k];
                    A[j][k]=A[y][k];
                    A[y][k]=temp;
            }
    }
    printf("Rearrenged\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<2*n+1; j++)
        {
            printf("%8.2f",A[i][j]);
        }
    printf("\n");
    }

    printf("\nCoefficient Matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%8.2f",C[i][j]);
        }
    printf("\n");
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=0; k<(2*n)+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }

            }
            else
                {
                    c=A[i][j];
                    for(k=0; k<(2*n)+1; k++)
                    {
                        A[i][k]/=c;
                    }
                }
        }
    }
    printf("\nSolution Augmented Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<2*n+1; j++)
        {
            AI[i][j]=A[i][j+n];
            printf("%8.2f",A[i][j]);
        }
    printf("\n");
    }
    printf("\nInverse Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {

            printf("%9.3f",AI[i][j]);
        }
    printf("\n");
    }
float (*T)[100]=FMAT(AI,B,n,n,1);
printf("\nSolution:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<1; j++)
        {
            printf("i[%d]=%6.3f",i+1,T[i][j]);
        }
    printf("\n");
    }
}

float (*FMAT (float A[100][100],float B[100][100],int Row1,int Col1,int Col2))[100]//The Matrix Multiplication Part of the program
{
    /** Call this func. as ----->      float (*T)[100]=FMAT(a,b,row_1,col_1,col_2)           */
    float out[100][100]={0};
    float sum;
    int i,j,k;
    sum=0;
        for(i=0;i<Row1;i++)
        {
            for(j=0;j<Col2;j++)
            {
                for(k=0;k<Col1;k++)
                {
				sum += A[i][k] * B[k][j];
				//printf("%9.2f*%9.2f=%9.2f\n",A[i][k],B[k][j],sum);
				}
            out[i][j]=sum;
			sum=0;
			//printf("\n");
            }
        }
	return out;
}

float determinant(float f[100][100], int x)                         /**   Matrice Determinant   */
{
float b[100][100],c[100];
int i,j,k,s, sign =1;
float det = 0;

    if(2==x)
    {
        det =f[0][0]*f[1][1]-f[0][1]*f[1][0];
    }
    else
    {
        for (i=0;i<x;i++,sign*=-1)
        {
            for(j=1;j<x;j++)
            {
                for(s=k=0;k<x;k++)
                {
                    if(i != k)
                    {
                        b[j-1][s] = f[j][k];
                        s++;
                    }
                }
            }

                det += (sign * f[0][i] * determinant(b,x-1));
        }
    }

return det;
}


