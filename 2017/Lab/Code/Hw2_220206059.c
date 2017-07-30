/**
*       Author : Erman OLÇAY
*       Date   : 12.03.2017
*       Description: Homework2
*       Parameters : Decompose a square matrice
*       to obtain a diagonal and remainder matrice
*       and also takes inverse of the diagonal
*       and does a matrice subraction all by using functions
*/
#include<stdio.h>
void DECMPS(float *diag,float *rem,float *input,int dim);
void INV_DIAGONAL(float *dinv,float *d,int dim);
void SUBS(float *sout,float *a,float *b,int dim);
main()
{
    int dim,i,j;
    float dinv[100][100],diag[100][100],rem[100][100],a[100][100],sout[100][100];
    printf("Enter The Dimension of your Square Matrice:");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("Enter a%d%d:",i,j);                     /*Taking The Values of Matrice A*/
            scanf("%f",&a[i][j]);
        }}
    DECMPS(diag,rem,a,dim);                                 /**DECOMPOSITION Function Calll.*/
    printf("The Diagonal And Remainders of the Matrice\n");
    printf("\nMatrice A:\n");
    for(i=0;i<dim;i++)                                               /*Printing A*/
    {
        for(j=0;j<dim;j++)
        {
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }

    printf("\nDiagonal:\n");                                     /*PRINTING DIAGONAL*/
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("%.2f\t",diag[i][j]);
        }
        printf("\n");
    }
    printf("\nRemainder:\n");

    for(i=0;i<dim;i++)                                          /*PRINTING REMAINDER*/
    {
        for(j=0;j<dim;j++)
        {
            printf("%.2f\t",rem[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    INV_DIAGONAL(dinv,diag,dim);                                /**INVERsE FUNC Call*/
    printf("\nDinverse:\n");

    for(i=0;i<dim;i++)                                         /*Printing The INVERSE*/
    {
        for(j=0;j<dim;j++)
        {
            printf("%.2f\t",dinv[i][j]);
        }
        printf("\n");
    }
    printf("\nSubtraction of two matrices.\n");              /* The Substraction Part */
        int dimen[2][2];
        float m1[100][100],m2[100][100];
    beg:
        for(i=1;i<3;i++)		                            	//Taking the Dimesions
		{
		for(j=1;j<3;j++)
            {
            printf("Enter The Dimensions of the Matrice number %d:\t",i);
            scanf("%d",&dimen[i-1][j-1]);
            }
            printf("\n");
        }
	if(dimen[0][0]!=dimen[1][0] || dimen[0][1]!=dimen[1][1])     //Checks if the Dimensions are appropirate.!!
	{
		printf("Your dimensions are not appropirate\n");
		goto beg;

	}
	for(i=1;i<=dimen[0][0];i++){				                      	//taking 1st Matrix inputs
		for(j=1;j<=dimen[0][1];j++){
		printf("Enter the row #%d values of the 1st matrice :\t",i);
		scanf("%f",&m1[i-1][j-1]);
	}printf("\n");
	}
	for(i=1;i<=dimen[1][0];i++){				                	//taking 2nd Matrix inputs
		for(j=1;j<=dimen[1][1];j++){
		printf("Enter the row #%d values of the 2nd matrice :\t",i);
		scanf("%f",&m2[i-1][j-1]);
	}printf("\n");
	}
    SUBS(sout,m1,m2,dimen[0][0]);                                      /**Substraction Func Call*/
    printf("\Substraction Output:\n");
    for(i=0;i<dimen[0][0];i++)                                 /*Printing the Substraction output sout*/
    {
        for(j=0;j<dimen[0][1];j++)
        {
            printf("%.2f\t",sout[i][j]);
        }
        printf("\n");
    }
return 0;}                                                              /**   END OF MAIN   */

void DECMPS(float *diag,float *rem,float *input,int dim)                /*Decomposse Function*/
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
void INV_DIAGONAL(float *dinv,float *d,int dim)                       /* Inverse Dýagonal Function */
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
void SUBS(float *sout,float *a,float *b,int dim)                          /*Substraction Function*/
{int i,j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            sout[i*100+j]=a[i*100+j]-b[i*100+j];
        }}}


//Imam Hatipler Kapatilsin, Anayasa Degisikligine Hayir. Yasasin Laik, Demokratik Turkiye
