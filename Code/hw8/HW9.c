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

    int fibonacci[100]; //={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    int value=0;
    int j,i,tempr=0;
	fibonacci[0]=1;
	j=1;
	do{
		fibonacci[j]=tempr+fibonacci[j-1];
		tempr=fibonacci[j];
		j++;
	}while(fibonacci[j-1]<=atoi(argv[1]));
    ilk=(struct node*)malloc(sizeof(ListNode));
    temp=ilk;
    for(i=0;i<j;i++){
        temp->item=fibonacci[i];
        if(i==(j-1))  //last item
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
        tempE=NULL;
        tempO=NULL;

		printf("Even List:");
        printNode((*ptrEvenList));
        printf("Odd List:");
        printNode((*ptrOddList));
    }
}

void printNode(ListNode *ilk){
    if (ilk==NULL)
        return;
    while(ilk!=NULL){
        printf("%d ",ilk->item);
        ilk=ilk->next;
        //if(ilk->item  = 30)
        //continue;
    }
    printf("\n");
}

