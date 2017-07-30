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
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;
}*global = NULL;       //Global Node

void link_push(int);     /**                        */
void link_pop();         /**   Functions included   */
void link_list();        /**                        */

int main(int argc,char **argv)
{
    int choise, data_in;
    while(1){
        printf("\n\tOptions\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. QUIT\n");
        printf("Enter your choise: ");
        scanf("%d",&choise);
        switch(choise){
            case 1:{
                printf("Enter the data to PUSH into list: ");
                scanf("%d", &data_in);
                link_push(data_in);
                break;}
            case 2: {
                link_pop();
                break;}
            case 3: {
                link_list();
                break;}
            case 4: exit(1337);
            default: printf("\n\tWrong input....\n");
        }
    }
}
void link_push(int data_in)
{
    struct Node *node_New;
    node_New = (struct Node*)malloc(sizeof(struct Node));
    node_New->data = data_in;
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
            printf("\nPopped data is: %d", tmp->data);
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
                printf("%d->",temp->data);
                temp = temp -> next;
            }
        printf("%d->Null\n",temp->data);
        }
}
