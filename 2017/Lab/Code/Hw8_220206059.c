/*************************************************************************************/
/*************************************************************************************/
/**																					**/
/**								**** READ ME ****            						**/
/**																					**/
/**         																		**/
/**          Author : Erman OLCAY													**/
/**         Purpose : Given Assignment Number 8										**/
/**  Specifications : Using Structures and Stacks									**/
/**                   Being read from Students.txt File								**/
/**                   That has value parameters										**/
/**                   ID,Name Surname,Birth year,GPA								**/
/**                   Prints The List of read Information							**/
/**                   Calc. GPA's The Maximum & Minimum & Average					**/
/**                   Lists any individual's in the txt Results						**/
/**                        - Above average Success									**/
/**                        - Below average Fails									**/
/**                        - Also Returns The Best & Worst GPAs						**/
/**																					**/
/**                   Edit the SIZE if you need										**/
/**                                 larger than predefined 45						**/
/**																					**/
/*************************************************************************************/
/*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        printf("\n #    ID\tName\t\tBirth\tGPA\n");
        printf("--- ------  ---------------     -----   ----\n");
        for(i=0;i < s->count ;i++)
        {
            printf("(%d) %d  %5.30s\t%d\t%.2lf\n",i+1,s->listed[i].stID,
                                                s->listed[i].Name,
                                                s->listed[i].BirthYear,
                                                s->listed[i].GPA);
        }
    }

    void stats_on_gpa(struct stack_students *s)
    {
        int i;
        printf("\nStats on GPA values:\n");
        printf("---------------------\n");
        double max=0,min=5,ave,sum=0;
        for(i=0;i < s->count; i++)
        {
            if( s->listed[i].GPA > max )
                max = s->listed[i].GPA;
        }
        printf("Maximum GPA: %.2lf\n", max);
        for(i=0;i < s->count; i++)
        {
            if( s->listed[i].GPA < min )
                min = s->listed[i].GPA;
        }
        printf("Minimum GPA: %.2lf\n", min);

        for(i=0;i < s->count; i++)
        {
            sum += s->listed[i].GPA;
        }
        ave = sum / s->count ;
        printf("Average GPA: %.2lf\n", ave);

    }

    void performance_list(struct stack_students *s)
    {
        int i;
        double max=0,min=5,sum=0,ave;
        for(i=0;i < s->count; i++)
        {
            if( s->listed[i].GPA > max )
                max = s->listed[i].GPA;
        }
        for(i=0;i < s->count; i++)
        {
            if( s->listed[i].GPA < min )
                min = s->listed[i].GPA;
        }

        for(i=0;i < s->count; i++)
        {
            sum += s->listed[i].GPA;
        }
        ave = sum / s->count ;
        printf("\nThe End Results :\n");
        printf("------------------\n");
        for(i=0;i < s->count; i++)
        {
            printf("%5.15s\t%5.30s",s->listed[i].Name,"-------");
            if(s->listed[i].GPA==max)
                printf("\t%-5.10s\n","The Best");
            else if(s->listed[i].GPA>ave)
                printf("\t%-5.10s\n","Successful");
            else if(s->listed[i].GPA==min)
                printf("\t%-5.10s\n","The Worst");
            else if(s->listed[i].GPA<ave)
                printf("\t%-5.10s\n","Failed");
        }

    }



int main(int argc,char **argv)
{
    struct students p;
    struct stack_students stack;

/**Preliminary Instructions*/
    printf("    Make sure that you put the \"Students.txt\" file in the same directory\n");
    printf("    Students.txt File Should inlude the ID, Name, Birth year and GPA values\n");

    int i,CASE;
    FILE * fp;

/**Check if the file exists?*/
    if( (fp = fopen("Students.txt","r+")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }

/**Stack Initialization and File read*/
    init_stack(&stack);
    for(i=0; i <SIZE ; i++)
        {
            fscanf(fp,"%d %[ a-zA-Z] %d %lf",&p.stID,			/** %[ a-zA-Z] part is to scan String includes		   */
                                               p.Name,			/** whitespace and letters a to z and capital A to Z   */
                                              &p.BirthYear,
                                              &p.GPA);
            push(&stack, &p);
            if(feof(fp))
                {
                printf("\n *  File read success EOF Reached. With %d individuals.\n",stack.count);
                break;

                }
            if(i== SIZE-1)
                printf("\n *  File read success 45 Units Maximum size reached.\n");

        }
/**Option Menu*/
    printf("\n------- Program Options -------\n");
    printf(" \" 1 \" to see Students' List");
    printf("\n \" 2 \" to see the Stats on GPA");
    printf("\n \" 3 \" to see the Result Performances");
    printf("\n   *  Anything else would terminate the application");

/**Select The Option*/
/**Other than 1,2,3 Any other option will terminate program*/
    select:
    printf("\n\nEnter your choice : ");
    scanf("%d",&CASE);
    switch(CASE)
    {
    case 1:
        {
            studentlist(&stack);
            break;
        };
    case 2:
        {
            stats_on_gpa(&stack);
            break;
        };
    case 3:
        {
            performance_list(&stack);
            break;
        };
    default:
        exit(1337);
    }
/**Lets user select again after using 1,2,3*/
goto select;
}
