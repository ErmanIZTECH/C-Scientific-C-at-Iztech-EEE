#include<stdio.h>
#include<math.h>
void DECMPS(float *diag,float *rem,float *input,int dim);
void INV_DIAGONAL(float *dinv,float *d,int dim);
int jacob(float a[100][100],float x[100],float b[100],int dim,int maxitt,float conv);
float *SUBS(float *a,float *b,int row,int col);
void ADDMAT (float *addout,float *m1,float *m2,int dim);
float * MMAT (float m1[100][100],float m2[100][100],int row,int col);
main()
{
    int dim,i,j,k,maxitt,output;
    float c,dinv[100][100],diag[100][100],rem[100][100],a[100][100],b[100],x[100],sout[100][100];
    printf("Enter The Number of equations:");
    scanf("%d",&dim);
    printf("Enter Coefficient matrice Elements one by one:\n");
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("Enter a%d%d:",i,j);         /*Taking The Values of Matrice A*/
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter Right Hand Side matrice B:\n");
    for(i=0;i<dim;i++)
    {
        printf("Enter b%d:",i);         /*Taking The Values of Matrice B*/
        scanf("%f",&b[i]);
    }
    printf("Enter The initial values of matrice X:\n");     /**Taking The Inıtial VAlues of x*/
    for(i=0;i<dim;i++)
    {
        printf("Enter x%d:",i);
        scanf("%f",&x[i]);
    }
    printf("\nEnter a Small Constant c That convergance criteria:");       /**Convergence*/
    scanf("%f",&c);

    printf("\nHow many Iterations to calculate:");                      /**Maximum Iterations*/
    scanf("%d",&maxitt);

    output=jacob(a,x,b,dim,maxitt,c);                      /**Call JACOB*/
     DECMPS(diag,rem,a,dim);
    INV_DIAGONAL(dinv,diag,dim);
    printf("output at iteration=%d\n",output);
     printf("D Matrice is:\n");
     for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("%f\t",diag[i][j]);
        }
        printf("\n");
    }
     printf("R Matrice is:\n");
     for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("%f\t",rem[i][j]);
        }
        printf("\n");
    }

return 0;
}
int jacob(float a[100][100],float x[100],float b[100],int dim,int maxitt,float conv)  /**JACOB FUNCTION*/
{
    int i,j,converged,itt=0;
    float xtemp[100],dinv[100][100],diag[100][100],rem[100][100],rms;
    converged=0;
    DECMPS(diag,rem,a,dim);
    INV_DIAGONAL(dinv,diag,dim);
    float sum;
    float sum1,mout[dim];
int q,w,e;
    while(itt<maxitt && converged==0)
    {
        for(i=0;i<dim;i++)
        xtemp[i]=x[i];

        for(i=0;i<dim;i++)
        {
            sum=b[i];
            for(j=0;j<dim;j++)
            {
                sum-= rem[i][j] * xtemp[j];

            }
                x[i]= dinv[i][i] * sum;
                printf("iteration %d ---> x[%d]=%f\n",itt+1,i,x[i]);
   /**             for(q=0;q<dim;q++)
                {
                    sum1+=a[i][q]*x[q];
                }
                mout[i]=sum1;
                mout[i]=mout[i]-b[i];
                printf("mout%d\t%f\t\n",i,mout[i]);
            rms+=mout[i]*mout[i];
            rms=sqrt(rms);
            printf("rms%d=%f",i,rms);
*/

        }
itt++;
printf("\n");


}





    return (itt);
}


void DECMPS(float *diag,float *rem,float *input,int dim)                    /*Decomposse Function*/
{    int i,j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(i==j)
            {
                diag[i*100+j]=input[i*100+j];
                rem[i*100+j]=0;
            }
            if(i!=j)
            {
                diag[i*100+j]=0;
                rem[i*100+j]=input[i*100+j];
            }}}}
void INV_DIAGONAL(float *dinv,float *d,int dim)                         /* Inverse Dýagonal Function */
{    int i,j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(i==j)
            {
                dinv[i*100+j]= 1/d[i*100+j];
            }
            if(i!=j)
            {
                dinv[i*100+j]=0;
            }}}}
float *SUBS(float *a,float *b,int row,int col)                  /*Substraction Function*/
{int i,j;
float *sout;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sout[i*col+j]=a[i*col+j]-b[i*col+j];
        }}
        return (sout);}

float * MMAT (float m1[100][100],float m2[100][100],int row,int col)                  ///////Multiplication Function
	{
	int sum,i,j,k;
	float mout[row][col];
	sum=0;
	printf("\n");
	for ( i = 0 ; i < row ; i++ ){
    for ( j = 0 ; j < col ; j++ ){
    for ( k = 0 ; k < row ; k++ )
        {
            sum+= m1[i][k] * m2[k][j];
            mout[i][j]=sum;
            printf("mm%.2f\t",mout[i][j]);
        }
    printf("\n");}
}

    return (mout);}

void ADDMAT (float *addout,float *m1,float *m2,int dim)                   ////ADDITION Func
{
	int i,j;
	for(i=0;i<dim;i++) //The Matrix Multiplication Part of the program
	{
		for(j=0;j<dim;j++)
		{
            addout[i*100+j]=m1[i*100+j]+m2[i*100+j];
	}}}
