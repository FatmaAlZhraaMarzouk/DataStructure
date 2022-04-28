/********************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber          */
/*  Description : Circular Queue Array Based            */
/*  Date        : 30/12/2021                            */
/* Version      : V01                                   */
/********************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef struct queue{
    int Arr[MaxSize];
    int Front;
    int Rear;
    int Size;
}Queue;

void Queue_voidInit(Queue* pq);
void Queue_EnQueue(int Copy_QueueValue, Queue* pq );
void Queue_DeQueue(Queue* pq,int * pd);
int Queue_intIsFull(Queue* pq);
int Queue_intIsEmpty(Queue* pq);
void Queue_voidPrint(Queue* pq);
int Queue_intReturnSize(Queue* pq);
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
    Queue_DeQueue(&q1,&Value);
    printf("Value = %d\n",Value);
    Queue_DeQueue(&q1,&Value);
    printf("Value = %d\n",Value);
    return 0;
}

void Queue_voidInit(Queue* pq){
    pq->Front=-1;
    pq->Rear=-1;
    pq->Size=0;
}
void Queue_EnQueue(int Copy_QueueValue, Queue* pq ){
    if(Queue_intIsFull(pq)){
        printf("Queue IS Full\n");
    }
    else{
        if(pq->Front == -1)
        {
            pq->Front = 0;
            pq->Rear=0;
        }
        else{
            if(pq->Rear==MaxSize-1)
                pq->Rear=0;
            else
                pq->Rear++;
        }
        pq->Arr[pq->Rear]= Copy_QueueValue;
        pq->Size++;
    }
}
void Queue_DeQueue(Queue* pq,int * pd){
     if(Queue_intIsEmpty(pq))
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        *pd = pq->Arr[pq->Front];
        if(pq->Front==pq->Rear)
        {
            pq->Front=-1;
            pq->Rear=-1;
        }
        else{
            if(pq->Front==MaxSize-1)
                pq->Front=0;
            else 
                pq->Front++;

        }  
    }
}
int Queue_intIsFull(Queue* pq){
    return ((pq->Rear==MaxSize-1&&pq->Front==0)||(pq->Front==pq->Rear+1));
}
int Queue_intIsEmpty(Queue* pq){
    return (pq->Front==-1);
}
void Queue_voidPrint(Queue* pq){
    if(Queue_intIsEmpty(pq))
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        int i=pq->Front;
        if(i<=pq->Rear)
        {
            while (i<=pq->Rear)
            {
                printf("%d\n", pq->Arr[i]);
                i++;
            }        
        }
        else{
            while (i<=MaxSize-1)
            {
                printf("%d\n", pq->Arr[i]);
                i++;
            }
        }
    }

}
int Queue_intReturnSize(Queue* pq){
    return pq->Size;
}