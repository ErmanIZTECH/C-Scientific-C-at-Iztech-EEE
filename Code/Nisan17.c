#include <stdio.h>
#include <stdlib.h>
int main()
{
    typedef struct {
        char name[40];
        int num;
        float midterm;
        float fin;
            } student;

    student ee204class[100];
    int i,N;
    beg:
    printf("\n how Many People In Class?");
    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        printf("\nName %d:",i+1);
        scanf("%s",ee204class[i].name); //&ee204class[i].name[0]
        printf("\nNumber %d:",i+1);
        scanf("%d",&ee204class[i].num);
        printf("\nMidterm Grade %d:",i+1);
        scanf("%f",&ee204class[i].midterm);
        printf("\nFinal %d:",i+1);
        scanf("%f",&ee204class[i].fin);

    }
    float ort;
    for(i=0;i<N;i++)
    {
        ort= (0.4 * ee204class[i].midterm) + (0.6 * ee204class[i].fin);
        if( ort >50 )
            printf("\n%s Passes the class %f",ee204class[i].name,ort);
        else
            printf("\n%s Failss %f",ee204class[i].name,ort);
    }
    goto beg;
}
