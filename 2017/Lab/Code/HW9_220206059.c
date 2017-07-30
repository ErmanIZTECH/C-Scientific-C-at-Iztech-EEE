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

    int fibon[100]; //={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    int value=0;
    int j,i,tempr=0;
	fibon[0]=1;
	j=1;
	do{
		fibon[j]=tempr+fibon[j-1];
		tempr=fibon[j-1];
        j++;
	}while(fibon[j-1]<=atoi(argv[1]));
		//printf("%d\n",j);

		for(i=0;i<j-1;i++){
            //printf("%d\n",fibon[i]);
            }

    ilk=(struct node*)malloc(sizeof(ListNode));
    temp=ilk;
    for(i=0;i<j-1;i++){
        temp->item=fibon[i];
        if(i==(j-2))  //last item
            break;
        temp->next=(struct node*)malloc(sizeof(ListNode));
        temp=temp->next;
    }
    temp->next=NULL;

    split(ilk,&OddList,&EvenList);

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
        printNode((*ptrEvenList));
        printf("Odd List:");
        printNode((*ptrOddList));
    }
}

void printNode(ListNode *ilk){
    if (ilk->next==NULL)
        return;
    while(ilk->next!=NULL){
        printf("%d ",ilk->item);
        ilk=ilk->next;
    }
    printf("\n");
}

