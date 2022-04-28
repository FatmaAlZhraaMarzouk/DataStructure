/**************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber    */
/*  Description : Stack Array Based               */
/*  Date        : 27/12/2021                      */
/* Version      : V01                             */
/**************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 3


typedef int StackEntry ; 
typedef struct stack
{
    StackEntry Arr[MaxSize];
    StackEntry Top;
    StackEntry Size;
}Stack;
void Stack_voidInit(Stack* ps);
void Stack_voidPush(int Copy_StackValue, Stack* ps );
int Stack_intPop(Stack* ps);
int Stack_intReturnTop(Stack* ps);
int Stack_intIsFull(Stack* ps);
int Stack_intIsEmpty(Stack* ps);
void Stack_voidPrint(Stack* ps);
int Stack_intReturnSize(Stack* ps);
int main(){
    Stack s1;
    int Value=0;
    int Size;
    Stack_voidInit(&s1);
    Stack_voidPush(5,&s1);
    Stack_voidPush(3,&s1);
    Stack_voidPush(6,&s1);
    Stack_voidPush(7,&s1);
    Stack_voidPrint(&s1);
    Size=Stack_intReturnSize(&s1);
    printf("The Size of Stack = %d\n",Size);
    Value = Stack_intPop(&s1);
    printf("Top Value = %d\n",Value);
    Value = Stack_intPop(&s1);
    printf("Top Value = %d\n",Value);
    Value = Stack_intPop(&s1);
    printf("Top Value = %d\n",Value);
    Value = Stack_intPop(&s1);
    printf("Top Value = %d\n",Value);
    return 0;
}
void Stack_voidInit(Stack* ps){
    ps->Top=-1;
    ps->Size=0;
}
void Stack_voidPush(int Copy_StackValue, Stack* ps ){

    if(Stack_intIsFull(ps))
    {
        printf("Stack Overflow\n");
    }
    else{
        ps->Top++;          //increment Top
        ps->Arr[ps->Top]=Copy_StackValue; //Assign Value
        ps->Size++;
    }

}

int Stack_intPop(Stack* ps){

    if(Stack_intIsEmpty(ps))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else{
        int TopValue;

        TopValue=ps->Arr[ps->Top];
        ps->Top--;
        ps->Size--;
        return TopValue;
    }
}
int Stack_intReturnTop(Stack* ps){

    if(Stack_intIsEmpty(ps))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else{
        int TopValue;
        TopValue=ps->Arr[ps->Top];
        return TopValue;
    }
}

int Stack_intIsFull(Stack* ps){
       return ps->Top==MaxSize-1;
}
int Stack_intIsEmpty(Stack* ps){
        return ps->Top==-1;
}
void Stack_voidPrint(Stack* ps){
    if(Stack_intIsEmpty(ps))
    {
        printf("The Stack is Embty\n");
    }
    else{
        int i = ps->Top;
        while(i!=-1){
            printf("The Value of Element %d\n",ps->Arr[i]);
            i--;
        }
    }
}
int Stack_intReturnSize(Stack* ps){
    return ps->Size;
}

