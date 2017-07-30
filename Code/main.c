//
//  main.c
//  Homework 4
//
//  Created by Kadir Ozgun on 27.03.2017.
//  School ID: 220206010
//  Copyright © 2017 Kadir Ozgun. All rights reserved.
#include <stdio.h>
#include<math.h>
//#include<curses.h>
#include<stdlib.h>
#define maximum 10
#define minvalue 0.0005
void SUBMAT(float out[100][100], float M1[100][100], float M2[100][100],int N, int M);
void MATGEN(float out[100][100], int X, int Y);
void MATGENIDENTITY(float out[100][100], int X, int Y);
void DECMPSMAT(float out1[100][100], float out2[100][100], float M1[100][100],int N, int M);
void INVERSEMAT(float out[100][100],float M1[100][100],int M,int N);
void PRINT(float input[100][100],int M, int N);
void GAUSSIAN(float out[100][100],float augmented[100][100],float identity[100][100],int X, float matright[100][100]);
void PRODUCTMAT(float out[100][100], float M1[100][100], float M2[100][100],int N, int M, int Z, int T);
double BISECT(double (*f)(double),double start,double end,double epsilon,float N, int iteration);
double FUNC(double N);

int main(int argc, char **argv)
{
    int iteration;
    double start,end,epsilon;
    double root;
    iteration = atof(argv[5]);
    float n = atof(argv[1]);
    start = atof(argv[2]);
    end = atof(argv[3]);
    epsilon = atof(argv[4]);
    root = BISECT(FUNC,start,end,epsilon,n,iteration);
    printf("Roots are found and %lf and %lf are the roots.",root,root*(-1));
}

void MATGEN(float out[100][100], int X, int Y)
{
    int i,j;    {
        for(j=0;j<Y;j++)
        {
            scanf("%f",&out[i][j]);
        }
    }
}
void ADDMAT(float out[100][100], float M1[100][100], float M2[100][100],int N, int M)
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            out[i][j]=M1[i][j]+M2[i][j];
        }}
}
void SUBMAT(float out[100][100], float M1[100][100], float M2[100][100],int N, int M)
{
    int c,d;
    for (c = 0; c < M; c++)
    {
        for (d = 0; d < N; d++)
        {
            out[c][d] = M1[c][d] - M2[c][d];
        }
        printf("\n");
    }

}
void PRODUCTMAT(float out[100][100], float M1[100][100], float M2[100][100],int N, int M, int Z, int T)
{
    int i,j,k;
    float sum=0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < T; j++) {
            for (k = 0; k < Z; k++) {
                sum = sum + M1[i][k]*M2[k][j];
            }

            out[i][j] = sum;
            sum = 0;
        }
    }

}
void DECMPSMAT(float out1[100][100], float out2[100][100], float M1[100][100],int N, int M)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(i==j)
                out1[i][j]=0;
            else
                out1[i][j]=M1[i][j];
        }
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(i==j)
                out2[i][j]=M1[i][j];
            else
                out2[i][j]=0;
        }
    }
}
void INVERSEMAT(float out[100][100],float M1[100][100],int M,int N)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for (j=0; j<N; j++)
        {

            if (i==j)
                out[i][j]=(1/M1[i][j]);
        }
    }

}
void PRINT(float input[100][100],int M, int N)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%f ",input[i][j]);
        }
        printf("\n");
    }
}
void MATGENIDENTITY(float out[100][100], int X, int Y)
{int i,j;
    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++)
        {
            if(j==i)
                out[i][j]=1;
            else
                out[i][j]=0;
        }
    }
}

void GAUSSIAN(float out[100][100],float augmented[100][100],float identity[100][100],int X,float matright[100][100])
{int i,j,k;
    float matres[100][100];
    for(i=0;i<X;i++)
    {
        for(j=i;j<X;j++)
        {
            if(augmented[j][i]>augmented[i][i])
            {
                for(k=0;k<X;k++)
                {
                    float temp=augmented[i][k];
                    augmented[i][k]=augmented[j][k];
                    augmented[j][k]=temp;

                    temp=identity[i][k];
                    identity[i][k]=identity[j][k];
                    identity[j][k]=temp;
                }
            }
        }
    }
    for(i=0;i<X;i++)
    {
        float d=augmented[i][i];
        for(j=0;j<X;j++)
        {
            augmented[i][j]=augmented[i][j]/d;
            identity[i][j]=identity[i][j]/d;
        }
        for(k=0;k<X;k++)
        {
            if(k!=i)
            {
                float a=augmented[k][i];
                for(j=0;j<X;j++)
                {
                    augmented[k][j]=augmented[k][j]-(augmented[i][j]*a);
                    identity[k][j]=identity[k][j]-(identity[i][j]*a);

                }
            }
        }
    }
    float t=1;
    int c;
    for (c=0; c<X; c++)
    {
        t*=augmented[c][c];
    }
    if(t!=1)
        printf("Your Matrix is Singular yet cannot be inverted ");
    else
    {
        PRODUCTMAT(matres, identity, matright, X,X,X,1);
        PRINT(matres,X,1);
    }
}
double BISECT(double (*f)(double),double start,double end,double epsilon,float N, int iteration)
{
    double mid;
    mid=(start+end)/2;
    if(fabs(N-FUNC(mid))>epsilon && iteration != 0)
    {
        if ((FUNC(start)-N)*(FUNC(mid)-N)<=0)
            mid = BISECT(FUNC, start, mid, epsilon, N, iteration);
        else
            mid = BISECT(FUNC, mid, end, epsilon, N, iteration);
    }
    return mid;
}

double FUNC(double N)
{
    return N*N;
}
