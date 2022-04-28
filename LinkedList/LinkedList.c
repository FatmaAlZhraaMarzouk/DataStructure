/********************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber          */
/*  Description : Linked List Based                     */
/*  Date        : 30/12/2021                            */
/* Version      : V01                                   */
/********************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20

typedef struct listnode{
    int Data;
    struct listnode * Next;

}ListNode;

typedef struct list{
    int size;
    ListNode * head;

}List;

void List_voidInit(List* pl);
void List_Insert(int pos, List* pl,int Copy_ListValue);
void List_Delete(int pos, List* pl,int * pd );
void List_RetriveList(int pos, List* pl,int * pd );
void List_ReplaceValue(int pos, List* pl,int Copy_ListValue );
int List_intIsFull(List* pl);
int List_intIsEmpty(List* pl);
int List_intReturnSize(List* pl);
void List_DestroyList(List* pl);
void List_Print(List* pl);

int main(){

    List l1;
    int Value;
    int Size;
    List_voidInit(&l1);
    List_Insert(0, &l1,10);
    List_Insert(1, &l1,11);
    List_Insert(2, &l1,15);
    printf("Print all element in list\n");
    List_Print(&l1);
    
    Size=List_intReturnSize(&l1);
    printf("\nThe Size of List = %d\n",Size);

    List_RetriveList(2,&l1, &Value);
    printf("The RetrivedValue is= %d\n", Value);

    List_Delete(1,&l1, &Value);
    printf("The RetrivedValue is= %d\n", Value);
    
    Size= List_intReturnSize(&l1);
    printf("The size of the list is= %d\n", Size);

    return 0;
}


void List_voidInit(List* pl){
    pl->head=NULL;
    pl->size=0;
}

void List_Insert(int pos, List* pl,int Copy_ListValue ){
    ListNode* q;
    int i;
    ListNode* pn=(ListNode*)malloc(sizeof(ListNode));
    pn->Data=Copy_ListValue;
    pn->Next=NULL;

    if(pos == 0)       
    {
        pn->Next = pl->head;
        pl->head = pn;
    }
    else
    {
        for(q = pl->head, i=0; i< pos-1; i++)
        {
            q = q->Next;
        }
        pn ->Next= q->Next;
        q->Next= pn;
    }
    pl->size++;
}
void List_Delete(int pos, List* pl,int * pd ){
    
    int i;
    ListNode *q, *tmp;
    if(pos==0)
    {
        *pd = pl->head->Data;
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }
    else
    {
        for(q= pl->head, i=0; i<pos-1; i++)
        {
            q = q->Next;
        }
        *pd = q->Next->Data;
        tmp= q->Next->Next;
        free(q->Next);
        q->Next = tmp;
    }
    pl->size--;
}
void List_RetriveList(int pos, List* pl,int * pd ){
    
    int i;
    ListNode* q;
    for(q= pl->head, i=0; i< pos; i++)
    {
        q = q->Next;
    }
    *pd= q->Data;
}
void List_ReplaceValue(int pos, List* pl,int Copy_ListValue ){
    int i;
    ListNode* q;
    for(q= pl->head, i=0; i<pos; i++)
    {
        q = q->Next;
    }
    q->Data= Copy_ListValue;
}
int List_intIsFull(List* pl){
    return 0;
}
int List_intIsEmpty(List* pl){
    return (pl->head == NULL);

}
int List_intReturnSize(List* pl){
    return (pl->size);
}
void List_Print(List* pl)
{
    ListNode* q= pl->head;

    while(q != NULL)
    {
        printf("%d\t", q->Data);
        q= q->Next;
    }
}
void List_DestroyList(List* pl){

     ListNode* tmp;
    while(pl->head != NULL)       
    {
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }

    pl->size=0;
}