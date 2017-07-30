#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define SIZE 45
    struct students
    {
    int stID;
    char Name[80];
    int BirthYear;
    double GPA;
    };

    struct stack_students
    {
    int count;
    struct students listed[SIZE];
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
        if(s->count > 0)
            {
            s->count--;
            return(s->listed[s->count]);
            }
        else
            {
            printf("Error Failed to pop It is Empty Stack.\n");
            exit(-1);
            }
    };

    void push(struct stack_students *s,struct students *p)
    {
        if( s->count < SIZE)
        {
            s->listed[s->count]=*p;
            s->count++;
        }
        else
        {
            printf("Error Failed to push It is FULL Stack.\n");
            exit(-2);
        }
    }

    void studentlist(struct stack_students *s)
    {
        int i;
               for(i= s->count-1 ; i >= 0  ;i--)
        {
            printf(" %d\n",s->listed[i].stID);
        }
    }



int main(int argc,char **argv)
{
    struct students p;
    struct stack_students stack;


    int i;
    char CASE[10];

    init_stack(&stack);
    int temp1,temp2;

    printf("\n------- Program Options -------\n");
    printf(" \" 1 \" PUSH");
    printf("\n \" 2 \" POP");
    printf("\n \" 3 \" DISPLAY");
    printf("\n \" 4 \" EXIT");
  select:

    printf("\n\nEnter your choice : ");
    scanf("%s",&CASE);
    i=isdigit(CASE);
    int CASE1;
    CASE1=atoi(CASE);
    switch(CASE1)
    {
    case 1:
        {
            printf("\n Enter the element to be PUSHED : ");
            scanf("%d",&p.stID);
            push(&stack,&p);
            break;
        };
    case 2:
        {
            temp1=stack.listed[stack.count - 1].stID;
            pop(&stack);
            printf("\n popped = %d",temp1);
            break;
        };
    case 3:
        {
            studentlist(&stack);
            break;
        };
    case 4:
        {
        exit(1337);
        break;
        }
    default:
    {
        if(CASE[0]=='/')
        {
            temp1=stack.listed[stack.count - 1].stID;
            pop(&stack);
            temp2=stack.listed[stack.count - 1].stID;
            pop(&stack);
            p.stID=temp2/temp1;
            push(&stack,&p);
            studentlist(&stack);
        }
        if(CASE[0]=='*')
        {
            temp1=stack.listed[stack.count - 1].stID;
            pop(&stack);
            temp2=stack.listed[stack.count - 1].stID;
            pop(&stack);
            p.stID=temp2*temp1;
            push(&stack,&p);
            studentlist(&stack);
        }
         if(CASE[0]=='+')
        {
            temp1=stack.listed[stack.count - 1].stID;
            pop(&stack);
            temp2=stack.listed[stack.count - 1].stID;
            pop(&stack);
            p.stID=temp2+temp1;
            push(&stack,&p);
            studentlist(&stack);
        }
         if(CASE[0]=='-')
        {
            temp1=stack.listed[stack.count - 1].stID;
            pop(&stack);
            temp2=stack.listed[stack.count - 1].stID;
            pop(&stack);
            p.stID=temp2-temp1;
            push(&stack,&p);
            studentlist(&stack);
        }



            printf("\n Choice was = %s",CASE);
            break;
    }



    }
goto select;
}
