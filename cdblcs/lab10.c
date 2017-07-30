/*************************************************************************************/
/*************************************************************************************/
/**																					**/
/**								**** READ ME ****            						**/
/**																					**/
/**         																		**/
/**          Author : Erman OLCAY													**/
/**         Purpose : Given Assignment Number 10									**/
/**  Specifications : Using Structures and Linked Lists								**/
/**                   pushing popping and listing operations can be made        	**/
/**																					**/
/*************************************************************************************/
/*************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
struct Node
{
    char Name[80];
    char SurName[80];
    int kg;
    struct Node *next;
}*global = NULL;       //Global Node

void link_push(char *,char *,int);     /**                        */
void link_pop();         /**   Functions included   */
void link_list();        /**                        */

int main(int argc,char **argv)
{
    int choise,weight;
    char *pass_name,*pass_surname;
    pass_name=(char *)malloc(sizeof(char)*80);
    pass_surname=(char *)malloc(sizeof(char)*80);
    while(1){
        printf("\n\tAirport Luggage System.\n-----------------------------------------------\n");
        printf("\t1\t-->\tAdd New Luggage\n\t2\t-->\tGet Luggage Out\n\t3\t-->\tDISPLAY Luggages\n\t4\t-->\tExit\n");
        printf("Enter your choice: ");
        scanf("%d",&choise);
        switch(choise){
            case 1:{
                printf("Passenger\nName\t\t\t: ");
                scanf("%s",pass_name);
                //printf("Name\t\t: %s",pass_name);
                printf("Surname\t\t\t: ");
                scanf("%s",pass_surname);
                printf("Luggage Weight (kgs)\t: ");
                scanf("%d",&weight);
                link_push(pass_name,pass_surname,weight);
                break;}
            case 2: {
                link_pop();
                break;}
            case 3: {
                printf("\nLuggage List\n-----------------------------------------------\n");
                link_list();
                printf("\n-----------------------------------------------\n");
                break;}
            case 4: exit(1337);
            default: printf("\n\tWrong input....\n");
        }
    }
}
void link_push(char *pass_name,char *pass_surname,int weight)
{
    struct Node *node_New;
    node_New = (struct Node*)malloc(sizeof(struct Node));
    node_New->kg = weight;
    strcpy(node_New->Name,pass_name);
    strcpy(node_New->SurName,pass_surname);
    if(global == NULL)
        node_New->next = NULL;
    else
        node_New->next = global;

    global = node_New;
    printf("\nPushed...\n");
}

void link_pop()
{
    if(global == NULL)
        printf("\nList = NULL\n");
    else
        {
            struct Node *tmp = global;
            printf("\nLuggage is Delivered\nName\t\t: %s", tmp->Name);
            printf("\nSurname\t\t: %s", tmp->SurName);
            printf("\nLuggage Weight\t: %d kg\n", tmp->kg);
            global = tmp->next;
            free(tmp);
        }
}

void link_list()
{
    printf("\n");
    if(global == NULL)
        printf("\nList = NULL (empty list)\n");
    else
        {
        struct Node *temp = global;
        while(temp->next != NULL)
            {
                printf("%s",temp->Name);
                printf(" %s",temp->SurName);
                printf(" %d kg\n",temp->kg);
                temp = temp -> next;
            }
        printf("%s",temp->Name);
        printf(" %s",temp->SurName);
        printf(" %d kg\n",temp->kg);
        }
}
