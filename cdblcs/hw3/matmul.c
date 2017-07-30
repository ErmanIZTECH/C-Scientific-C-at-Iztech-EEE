#include<stdio.h>
float (*MatM(int dim))[100][100];
void main()
{
    int dim=5,i,j;
    float (*T)[100]=MatM(dim), A[100][100];


    printf("Main\n");
     for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("%9.2f",T[i][j]);
        }
        printf("\n");
    }
}

float (*MatM(int dim))[100][100]
{
    float out[100][100];
    int i,j,k=1;
    printf("Function\n");
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            k++;
            out[i][j]=i+j+k;
            printf("%9.2f",out[i][j]);
        }
         printf("\n");
    }
    return out;
}
