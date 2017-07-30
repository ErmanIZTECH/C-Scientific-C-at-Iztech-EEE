//////////////////////////////////////////////////
//HW 8 Final

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 15

typedef struct node{
    int item;
    struct node *next;
}ListNode,b;

int search(ListNode *ilk,int value);
void printNode(ListNode *ilk);
void split(ListNode *ilk,ListNode **OddList,ListNode **EvenList);

int main(){
    ListNode *ilk=NULL;
    ListNode *temp;
    ListNode *OddList=NULL;
    ListNode *EvenList=NULL;
    
    int fibonacci[SIZE]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    int value=0;
    int i;

    ilk=(struct node*)malloc(sizeof(ListNode));
    temp=ilk;
    for(i=0;i<SIZE;i++){
        temp->item=fibonacci[i];
        if(i==(SIZE-1))  //last item
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




//////////////////////////////////////////////////////////////////////////////////////////////
HW 8.1

#include<stdio.h>
#include<stdlib.h>

void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main(){
	
}


////////////////////////////////////////////////////////////////////////////////////
8.2
// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
 
void segregateEvenOdd(struct node **head_ref)
{
    struct node *end = *head_ref;
    struct node *prev = NULL;
    struct node *curr = *head_ref;
 
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
 
    struct node *new_end = end;
 
    /* Consider all odd nodes before the first even node
       and move then after end */
    while (curr->data %2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    // 10->8->17->17->15
    /* Do following steps only if there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to point to first even node */
        *head_ref = curr;
 
        /* now current points to the first even node */
        while (curr != end)
        {
            if ( (curr->data)%2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between prev and current */
                prev->next = curr->next;
 
                /* Make next of curr as NULL  */
                curr->next = NULL;
 
                /* Move curr to end */
                new_end->next = curr;
 
                /* make curr as new end of list */
                new_end = curr;
 
                /* Update current pointer to next of the moved node */
                curr = prev->next;
            }
        }
    }
 
    /* We must have prev set before executing lines following this
       statement */
    else prev = curr;
 
    /* If there are more than 1 odd nodes and end of original list is
      odd then move this node to end to maintain same order of odd
      numbers in modified list */
    if (new_end!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning  */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    segregateEvenOdd(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////
8.3
/*
 * C Program to Modify the Linked List such that All Even Numbers
 * appear before all the Odd Numbers in the Modified Linked List 
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void create(struct node **);
void generate_evenodd(struct node *, struct node**);
void release(struct node **);
void display(struct node *);
 
int main()
{
    struct node *p = NULL, *q = NULL;
    int key, result;
 
    printf("Enter data into the list\n");
    create(&p);
    
    generate_evenodd(p, &q);
    printf("even list:\n");
    display(q);
    printf("odd list:\n");
    release(&p);
 
    return 0;
}
 
void generate_evenodd(struct node *list, struct node **head)
{
    struct node *even = NULL, *odd = NULL, *temp;
    struct node *reven, *rodd;
    while (list != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = list->num;
        temp->next = NULL;
        if (list->num % 2 == 0)
        {
            if (even == NULL)
            {
                even = temp;
            }
            else
            {
                reven->next = temp;
            }
            reven = temp;
    	}
        else
        {
            if (odd == NULL)
            {
                odd = temp;
            }
            else
            {
                rodd->next = temp;
            }
            rodd = temp;
        }
        list = list->next;
    }
    reven->next = odd;
    *head = even;
}

 
void create(struct node **head)
{
    int c, ch;
    struct node *temp, *rear;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}
 
void release(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}


////////////////////////////////////////////////////////////////////////////////
8.4
/*
 	sayıları al
 	liste gönder
 	listte poklynoma çevir
 	gerivyazdır
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
/*void create(struct node **);
void polynomial(struct node *, struct node**);
void release(struct node **);
void display(struct node *);*/

void polynomial(struct node *list, struct node **head)
{
	double x;
    struct node *temp;
   // struct node *reven, *rodd;
    while (list != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = list->num;
        temp->next = NULL;
       
       
    }
 
}

 
void create(struct node **head)
{
    int c, ch;
    struct node *temp, *rear;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}
 
void release(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}


int main()
{
    struct node *p = NULL, *q = NULL;
    int key, result;
 
    printf("Enter data into the list\n");
    create(&p);
    
    polynomial(p, &q);
    printf("coefficients:\n");
    display(q);
    printf("pow:\n");
    release(&p);
 
    return 0;
}
 
///////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct listnode{
	int number;
	int derece;
	struct listnode *next;
};

typedef struct listnode * List;
List init_list();
int empty_list(List);

List init_list(){
	return(NULL);
}

List add_to_front(List slist, int number ,int number2 ,int *flag){
	List node;
	
	node = (struct listnode *)malloc(sizeof(struct listnode));
	if(node == NULL){
		*flag = 0;
	}
	else{
		node->number = number;
		node->derece = number2;
		node->next = slist;
		slist = node;
		*flag = 1;
	}
	return(slist);
}


void show_names(List slist){
	//if(!empty_list(slist)){
		show_names(slist->next);
		printf("%dx^ ",slist->number);
		printf("%d",slist->derece);
		printf("+");	
//	}
}

int main(){	
	int i,tempNumber,flag,temp2,n;
	List polynomial;
	int array[6];
	
	polynomial =  init_list();
	printf("Enter the numbers:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d",&array[i]);
	}
	
	for(i=0;i<n;i=i+2){
		tempNumber = array[i];
		temp2 = array[i+1];
		polynomial = add_to_front(polynomial,tempNumber,temp2,&flag);			
	}
	printf("\nOutput:");
	show_names(polynomial);	
	
	return 0;
}


	
