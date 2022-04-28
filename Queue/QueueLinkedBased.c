/********************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber          */
/*  Description : Regular Queue Linked Based            */
/*  Date        : 30/12/2021                            */
/* Version      : V01                                   */
/********************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20

typedef struct queuenode
{
    int Data;
    struct queuenode * Next;
}QueueNode;
typedef struct queue{
    QueueNode* Front;
    QueueNode* Rear;
    int Size;
}Queue;

void Queue_voidInit(Queue* pq);
void Queue_EnQueue(int Copy_QueueValue, Queue* pq );
void Queue_DeQueue(Queue* pq,int * pd);
int Queue_intIsFull(Queue* pq);
int Queue_intIsEmpty(Queue* pq);
void Queue_voidPrint(Queue* pq);
int Queue_intReturnSize(Queue* pq);
void Queue_Clear(Queue* pq);
int main(){
    Queue q1;
    int Value;
    int Size;
    Queue_voidInit(&q1);
    Queue_EnQueue(5,&q1);
    Queue_EnQueue(3,&q1);
    Queue_EnQueue(6,&q1);
    Queue_EnQueue(7,&q1);
    Queue_voidPrint(&q1);
    Size=Queue_intReturnSize(&q1);
    printf("The Size of Queue = %d\n",Size);
    Queue_DeQueue(&q1,&Value);
    printf("Value = %d\n",Value);
    Queue_DeQueue(&q1,&Value);
    printf("Value = %d\n",Value);
    Queue_Clear(&q1);
    Queue_DeQueue(&q1,&Value);
    printf("Value = %d\n",Value);
    Queue_DeQueue(&q1,&Value);
    printf("Value = %d\n",Value);
    return 0;
}

void Queue_voidInit(Queue* pq){
    pq->Front=NULL;
    pq->Rear=NULL;
    pq->Size=0;
}
void Queue_EnQueue(int Copy_QueueValue, Queue* pq ){

    QueueNode* pn=(QueueNode*)malloc(sizeof(QueueNode));
    pn->Data=Copy_QueueValue;
    pn->Next=NULL;
    if(Queue_intIsEmpty(pq))
    {
        pq->Front = pn;
    }
    else{
        pq->Rear->Next=pn;


    }
    pq->Rear=pn;
    pq->Size++;
    
}
void Queue_DeQueue(Queue* pq,int * pd){
    if(Queue_intIsEmpty(pq))
    {
        printf("This is an Empty Queue\n");
    }
    else
    {
        QueueNode* pn = pq->Front;
        *pd = pn->Data;
        pq->Front = pq->Front->Next;
        free(pn);
        if(Queue_intIsEmpty(pq))
        {
            pq->Rear = NULL;
        }
        pq->Size--;
    }  
}
int Queue_intIsFull(Queue* pq){
    return 0;
}
int Queue_intIsEmpty(Queue* pq){
    return (pq->Front==NULL);
}
void Queue_voidPrint(Queue* pq){
    if(Queue_intIsEmpty(pq))
    {
        printf("The Queue is Empty\n");
    }
    else
    { 
       QueueNode*  pn = pq->Front;
        while(pn!=NULL){
            printf("The Value of Element %d\n",pn->Data);
            pn=pn->Next;
        }
    }
}
int Queue_intReturnSize(Queue* pq){
    return pq->Size;
}
void Queue_Clear(Queue* pq){

    QueueNode* pn=pq->Front;
    while (pn!=NULL)
    {
        pq->Front=pq->Front->Next;
        free(pn);
        pq->Size--;
        pn=pq->Front;
    }
}
