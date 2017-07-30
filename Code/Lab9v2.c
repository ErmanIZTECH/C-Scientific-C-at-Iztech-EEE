/*************************************************************************************/
/*************************************************************************************/
/**																					**/
/**								**** READ ME ****            						**/
/**																					**/
/**         																		**/
/**          Author : Erman OLCAY													**/
/**         Purpose : Given Assignment Number 9										**/
/**  Specifications : Using Structures and Linked Lists								**/
/**                   Entered number in command line								**/
/**                   .>\hw9_220206059.exe "number"									**/
/**                   program calculates every number that 							**/
/**                   in rule increasing fibonacci order							**/
/**                   inserts every single one of them in lists						**/
/**                   prints evens and odds in seperate lists						**/
/**																					**/
/*************************************************************************************/
/*************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
    int item;
    int deg;
    struct node *next;
}ListNode,b;

int search(ListNode *ilk,int value);
void printNode(ListNode *ilk);
void split(ListNode *ilk,ListNode **OddList,ListNode **EvenList);

int main(int argc,char **argv){
    ListNode *ilk=NULL;
    ListNode *temp;
    ListNode *OddList=NULL;
    ListNode *EvenList=NULL;

    int value=0;
    int j,i,tempr=0,nodes,coef[100][2],Tmp[100][2];
	j=1;
	beg:
	printf("\nEnter the number of nodes : ");
	scanf("%d",&nodes);
/*	for(i=0;i<nodes;i++)
    {
        printf("\nEnter the coeff. and degre : ");
        scanf("%d %d",&coef[i][0],&coef[i][1]);
    }
		//printf("%d\n",j);

		for(i=0;i<nodes;i++)
            {
                for(j=0;j<2;j++)
                {
                    printf("%d ",coef[i][j]);
                }
            printf("\n");
            }

    int index,smallest;

for(i=0;i<nodes;i++)
	{
	    smallest=nodes-i-1;
	    for(j=0;j<nodes;j++)
        {
            if(coef[j][1]==smallest)
			{
			    Tmp[i][0]=coef[j][0];
				smallest=coef[j][1];
			}
		}
        Tmp[i][1]=smallest;
	printf("\n");
	}

         /*               printf("\n");

		for(i=0;i<nodes;i++)
            {
                for(j=0;j<2;j++)
                {
                    printf("%d ",Tmp[i][j]);
                }
            printf("\n");
            }
            */

    ilk=(struct node*)malloc(sizeof(ListNode));
    temp=ilk;
    for(i=0;i<nodes+1;i++){
        printf("\nEnter the coeff. and degre : ");
        scanf("%d %d",&temp->item,&temp->deg);
        if(i==(nodes))  //last item
            break;
        temp->next=(struct node*)malloc(sizeof(ListNode));
        temp=temp->next;
    }
    temp->next=NULL;

    printNode((ilk));

    //split(ilk,&OddList,&EvenList);
goto beg;
return 0;
}

void split(ListNode *ilk,ListNode **ptrOddList,ListNode **ptrEvenList){
    int remainder ,b;
    ListNode *tempO,*tempE,*temp;

    if (ilk==NULL)
        return;
    else{
        temp=ilk;

        *ptrOddList=(struct node*)malloc(sizeof(b));
        *ptrEvenList=(struct node*)malloc(sizeof(b));

        tempO=*ptrOddList;
        tempE=*ptrEvenList;

        while(temp!=NULL){
            remainder=temp->item%2;

            if(remainder==0){
                tempE->next=(struct node*)malloc(sizeof(b));
                tempE->item=temp->item;
                tempE=tempE->next;
            }
            else{
                tempO->next=(struct node*)malloc(sizeof(b));
                tempO->item=temp->item;
                tempO=tempO->next;
            }
            temp=temp->next;
        }
        tempE->next=NULL;
        tempO->next=NULL;

		printf("Even List:");
//        printNode((*ptrEvenList));
        printf("Odd List:");
     //   printNode((*ptrOddList));
    }
}

void printNode(ListNode *ilk){
    int i;
    if (ilk->next==NULL)
        return;
    while(ilk->next!=NULL){

        printf(" %d  ",ilk->item);
        ilk=ilk->next;




    }
    printf("\n");
}

