/**
*       Author : Erman OLÇAY
*       Date   : 17.03.2017
*       Description: Homework 3
*       Parameters : Gauss Jordan Inverse Matrix
*
*
*
*/
#include<stdio.h>
float detm(float mat[100][100], int dim);
main()
{   int i,j,k,n;
    float det,c,A[100][100]/*   ={{0,3,-1,8},{-1,11,-1,3},{2,-1,10,-1},{10,-1,2,0}}    */;
    float AI[100][100],C[100][100];

    read:
    printf("Enter The Dimension of your Square Matrice:");
    scanf("%d",&n);

    printf("\nEnter Coefficient Matrice Elements:\n");
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter A[%d,%d]:",i,j);                      /*Taking The Values of Matrix A*/
           scanf("%f",&A[i][j]);
        }}

    det=detm(A,n);                                       /**Calculate Determinant*/
    if(det==0)
    {
        printf("\a\n\t\t!!!!!Your Matrix is Singular yet cannot be inverted \n\n\t\t     det(A)= %.2f\n\nReEnter Reasonable, Valid and Invertable Matrix...\n\n",det);
        goto read;
    }
    printf("\ndet(A)= %.2f\n",det);

    for(i=0; i<n; i++)
    {
        for(j=0; j<(2*n)+1; j++)
        {
            C[i][j]=A[i][j];
            if(i+n==j)
            {
                A[i][j]=1;                  ///Write Identity Matrix Augmented to the Coefficient matrix
            }

            if(j==2*n)
            {
            }}}

float big,temp;                                         /**Pivoting!!!!!!!!!!!*/
int y,h;
   for(j=0; j<n; j++)
    {
        big= -999;
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


    printf("\nCoefficient Matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
           printf("%9.2f",C[i][j]);
    printf("\n");
    }


    for(j=0; j<n; j++)                                  /**Inverse matrice Calculator*/
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
                    }}}}

    for(i=0; i<n; i++)
        for(j=0; j<2*n+1; j++)
            AI[i][j]=A[i][j+n];

    printf("\nInverse Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
           printf("%9.3f",AI[i][j]);
    printf("\n");
    }
	
	
}

float detm(float mat[100][100], int dim)                         /**   Matrice Determinant Func.   */
{
float b[100][100],c[100];
int i,j,k,s, sign =1;
float det = 0;

    if(2==dim)
    {
        det =mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    else
    {
        for (i=0;i<dim;i++,sign*=-1)
        {
            for(j=1;j<dim;j++)
            {
                for(s=k=0;k<dim;k++)
                {
                    if(i != k)
                    {
                        b[j-1][s] = mat[j][k];
                        s++;
                    }
                }
            }

                det += (sign * mat[0][i] * detm(b,dim-1));
        }
    }

return det;
}


