/********************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber          */
/*  Description : Stack Linked Based                    */
/*  Date        : 29/12/2021                            */
/* Version      : V01                                   */
/********************************************************/
 
#include<stdio.h>
#include<stdlib.h>

typedef int StackData;

typedef struct Stacknode
{
    StackData Data;
    struct Stacknode * Next;
}StackNode;
typedef struct stack
{
    int Size;
    StackNode* Top;

}Stack;


void Stack_voidInit(Stack* ps);
void Stack_voidPush(int Copy_StackValue, Stack* ps );
void Stack_voidPop(Stack* ps,int * pd);
void Stack_voidReturnTop(Stack* ps,StackData * pd);
int Stack_intIsFull(Stack* ps);
int Stack_intIsEmpty(Stack* ps);
void Stack_voidPrint(Stack* ps);
int Stack_intReturnSize(Stack* ps);
void Stack_Clear(Stack* ps);
int main(){
    Stack s1;
    int Value;
    int Size;
    Stack_voidInit(&s1);
    Stack_voidPush(5,&s1);
    Stack_voidPush(3,&s1);
    Stack_voidPush(6,&s1);
    Stack_voidPush(7,&s1);
    Stack_voidPrint(&s1);
    Size=Stack_intReturnSize(&s1);
    printf("The Size of Stack = %d\n",Size);
    Stack_voidPop(&s1,&Value);
    printf("Top Value = %d\n",Value);
    Stack_voidPop(&s1,&Value);
    printf("Top Value = %d\n",Value);

    Stack_Clear(&s1);
    Size=Stack_intReturnSize(&s1);
    printf("The Size of Stack = %d\n",Size);

    Stack_voidPop(&s1,&Value);
    printf("Top Value = %d\n",Value);
    Stack_voidPop(&s1,&Value);
    printf("Top Value = %d\n",Value);
    return 0;
}
void Stack_voidInit(Stack* ps){
    ps->Top=NULL;
    ps->Size=0;
}
void Stack_voidPush(int Copy_StackValue, Stack* ps ){
    StackNode* pn=(StackNode*)malloc(sizeof(StackNode));
    pn->Data=Copy_StackValue;
    pn->Next=ps->Top;
    ps->Top=pn;
    ps->Size++;
}
void Stack_voidPop(Stack* ps,int * pd){

    if(Stack_intIsEmpty(ps))
    {
        printf("Stack is Empty\n");
    }
    else{
    *pd =ps->Top->Data;
    StackNode* pn=ps->Top;
    ps->Top=ps->Top->Next;
    free(pn);
    ps->Size--;
    }
}
void Stack_voidReturnTop(Stack* ps,StackData * pd){

    if(Stack_intIsEmpty(ps))
    {
        printf("Stack is Empty\n");
    }
    else{
        *pd =ps->Top->Data;
    }

}
int Stack_intIsFull(Stack* ps){
    return 0;
}
int Stack_intIsEmpty(Stack* ps){
    return (ps->Top==NULL);
}
void Stack_voidPrint(Stack* ps){
    if(Stack_intIsEmpty(ps))
    {
        printf("The Stack is Embty\n");
    }
    else{
        StackNode*  i = ps->Top;
        while(i!=NULL){
            printf("The Value of Element %d\n",i->Data);
            i=i->Next;
        }
    }
}
int Stack_intReturnSize(Stack* ps)
{
    return ps->Size;
}
void Stack_Clear(Stack* ps){

    StackNode* pn=ps->Top;
    while (pn!=NULL)
    {
        ps->Top=ps->Top->Next;
        free(pn);
        ps->Size--;
        pn=ps->Top;
    }
}