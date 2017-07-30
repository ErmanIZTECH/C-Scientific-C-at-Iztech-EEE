#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)  //**argv :Ragged array (birden fazla pointer iceren bir pointer.// Command line arguments
{                                //argc kaç argüman girileceðini
    float sum=0.0;
    int i;
    for(i=1;i<argc;i++)
    {
           sum+= atof(argv[i]);     //atof converts a string to a float atoi converts into integer
    }
    printf("%7.3f",sum);
}
