#include <stdio.h>
#include <stdlib.h>
#define MAX 45
struct students
{
    int stdID;
    char name[20];
    char surname[20];
    int year;
    double gpa;
};

struct stack_students
{
    int count;
    struct students entries[MAX];
};

void init_stack(struct stack_students *s)
{
    s->count=0;
}

int give_count(struct stack_students *s)
{
    return(s->count);
}

struct students pop(struct stack_students *s)
{
    if(s->count>0)
    {
        s->count--;
    }
    else
    {
        printf("Error!");
        exit(-2);
    }
};

void push(struct stack_students *s, struct students *p)
{
    if(s->count<MAX)
    {
        s->entries[s->count]=*p;
        s->count++;
    }
    else
    {
        printf("Full!");
        exit(-2);
    }
}

void studentlist(struct stack_students stack_students)
{
    int i;
    for(i=0;i<9;i++)
    {
        printf("%d)\t%d\t%s %s\t%d\t%.2lf\n",i+1,stack_students.entries[i].stdID,stack_students.entries[i].name,stack_students.entries[i].surname,stack_students.entries[i].year,stack_students.entries[i].gpa);
    }
}

void stats_on_gpa(struct stack_students stack_students)
{
    double max,min,ave,sum=0;
    max=0;
    int i;
    for(i=0;i<9;i++)
    {
        if(stack_students.entries[i].gpa>max)
        max=stack_students.entries[i].gpa;
    }
    printf("Maximum GPA: %.2lf\n", max);
    min=5;
    for(i=0;i<9;i++)
    {
        if(stack_students.entries[i].gpa<min)
        min=stack_students.entries[i].gpa;
    }
    printf("Minimum GPA: %.2lf\n",min);
    for(i=0;i<9;i++)
    {
        sum=sum+stack_students.entries[i].gpa;
    }
    ave=sum/9;
    printf("Average GPA: %.2lf\n",ave);
}

void performance_list(struct stack_students stack_students)
{
    int i;
    double max=0, min=5, ave, sum=0;
    for(i=0;i<9;i++)
    {
        if(stack_students.entries[i].gpa>max)
        max=stack_students.entries[i].gpa;
    }
    for(i=0;i<9;i++)
    {
        if(stack_students.entries[i].gpa<min)
        min=stack_students.entries[i].gpa;
    }
    for(i=0;i<9;i++)
    {
        sum=sum+stack_students.entries[i].gpa;
    }
    ave=sum/9;
    for(i=0;i<9;i++)
    {
        printf("%s %s ->",stack_students.entries[i].name,stack_students.entries[i].surname);
        if(stack_students.entries[i].gpa==max)
        printf("best\n");
        else if(stack_students.entries[i].gpa>ave)
        printf("succesful\n");
        else if(stack_students.entries[i].gpa==min)
        printf("worst\n");
        else if(stack_students.entries[i].gpa<ave)
        printf("failed\n");
}
}

int main()
{
    struct students p;
    struct stack_students stack;
    FILE *fptr;
    if ((fptr=fopen("students.txt", "r"))==NULL)
    {
        printf("Error!!");
        exit(1);
    }
    init_stack(&stack);
    int i;
    for(i=0;i<9;i++)
    {
        fscanf(fptr, "%d%s%s%d%lf", &p.stdID, p.name, p.surname, &p.year, &p.gpa);
        push(&stack, &p);
    }
    int c;
    printf("Press 1 to see student list\nPress 2 to see the stats\nPress 3 to see the results\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        {
            studentlist(stack);
            break;
        };
    case 2:
        {
            stats_on_gpa(stack);
            break;
        };
    case 3:
        {
            performance_list(stack);
            break;
        };
}
    return 0;
}


