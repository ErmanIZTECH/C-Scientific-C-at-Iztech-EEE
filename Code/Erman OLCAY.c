#include <math.h>
#include <conio.h>
#include <stdio.h>
float frobnorm(float matrix[5][5]);
int main(int argc,char **argv)
{
    float tot1=0,tot2=0,Res[5][5];
    float B1[5][5]={{255,241,27,106,255},
                    {255,166,0,203,255},
                    {244,55,68,247,255},
                    {183,0,136,255,255},
                    {252,94,0,168,255}  };

     float B2[5][5]={{25,62,88,106,213},
                    {50,111,123,203,255},
                    {77,91,135,173,255},
                    {105,127,173,255,0},
                    {189,202,255,0,0}  };

    float B3[5][5]={{255,145,73,51,0},
                    {255,177,137,93,0},
                    {196,135,102,0,0},
                    {172,156,144,99,81},
                    {159,117,93,67,53}  };
    float B4[5][5]={{255,222,69,207,255},
                    {255,224,68,206,255},
                    {222,67,206,255,246},
                    {223,66,205,255,0},
                    {245,74,172,255,254}  };
    float B5[5][5]={{231,148,50,124,183},
                    {242,79,187,210,150},
                    {155,205,225,113,34},
                    {95,157,245,82,118},
                    {90,105,93,47,255}  };

   float A[5][5]={ {143,   27,     0,14,27},
                    {238,   136,    0,0,138},
                    {169,   166,    53,0,0},
                    {53,    54,     54,0,0},
                    {255,   250,    177,91,0}  };
    int i,j,k;



        for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                {
                    printf("%9.3f",A[i][j]);
                }
            printf("\n");
            }


        for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                {
                    Res[j][i]=A[i][j]-B1[i][j];
                }

            }

tot1=frobnorm(Res);
            printf("FrobNorm A-B1=%9.2f\n",tot1);

              for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                {
                    Res[j][i]=A[i][j]-B1[i][j];
                }

            }

tot2=frobnorm(A);
            printf("FrobNorm=%9.2f\n",tot2);

            printf("FrobNorm=%9.2f\n",tot1-tot2);

}

float frobnorm(float matrix[5][5])
{
    int i,j,k;
    float res=0,sum=0;
    float matT[5][5]={0},prod[5][5]={0};

    for(i=0;i<5;i++)            /**Transpose*/
    {
        for(j=0;j<5;j++)
            {
                matT[j][i]= matrix[i][j];
            }
        //printf("\n");
    }


    for(k=0;k<5;k++)            /**Matrix Multiplication*/
    {
            for(i=0;i<5;i++)
            {
                sum=0;
                for(j=0;j<5;j++)
                {
                    sum = sum + ( matT[k][j] * matrix[j][i] );
                }
                prod[k][i]=sum;

            }
        //printf("\n");
    }

res=0;
                for(j=0;j<5;j++)                /**Sum of diagonals*/
                {
                    res+=prod[j][j];
                }
                //res=fabs(res);
printf("res=%f\n",res);

                res=sqrt(res) ;
    return( res );
}
