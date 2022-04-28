/********************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber          */
/*  Description : Reverse Function using Stak operations*/
/*  Date        : 27/12/2021                            */
/* Version      : V01                                   */
/********************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20


typedef int StackEntry ; 
typedef char StackValue;
typedef struct stack
{
    StackValue Arr[MaxSize];
    StackEntry Top;
    StackEntry Size;
}Stack;
void Stack_voidInit(Stack* ps);
void Stack_voidPush(StackValue Copy_StackValue, Stack* ps);
void Stack_voidPrint(Stack* ps);
void Stack_voidReverse(Stack* ps);
int Stack_intReturnTop(Stack* ps);
int Stack_intIsFull(Stack* ps);
int Stack_intIsEmpty(Stack* ps);
int Stack_intReturnSize(Stack* ps);
StackValue Stack_intPop(Stack* ps);
void Stack_voidReverse2(Stack* ps);
int main(){
    Stack s1;
    StackValue Value;
    int Size;
    int i=0;
    char str[10];
    Stack_voidInit(&s1);
    printf("Enter String : ");
    scanf("%s",str);
    while (str[i] != '\0') {
        Stack_voidPush(str[i],&s1);
        i++;
    }
    Stack_voidPrint(&s1);
    Stack_voidReverse(&s1);
    Stack_voidPrint(&s1);
    Stack_voidReverse2(&s1);
    Stack_voidPrint(&s1);
    return 0;
}
void Stack_voidInit(Stack* ps){
    ps->Top=-1;
    ps->Size=0;
}
void Stack_voidPush(StackValue Copy_StackValue, Stack* ps){
    if(Stack_intIsFull(ps))
    {
        printf("Stack Overflow\n");
    }
    else{
        ps->Top++;          //increment Top
        ps->Arr[ps->Top]=Copy_StackValue; //Assign Value
        ps->Size++; //increment Stack Size
    }
}
StackValue Stack_intPop(Stack* ps){

    if(Stack_intIsEmpty(ps))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else{
        StackValue TopValue;
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
        StackValue TopValue;
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
        printf("Print Function Is Called : ");
        StackEntry i = ps->Top;
        while(i!=-1){
            printf("%c",ps->Arr[i]);
            i--;
        }
        printf("\n");
    }
}
int Stack_intReturnSize(Stack* ps){
    return ps->Size;
}
//Reverse Function Reverse Using Push/Pop Function
void Stack_voidReverse(Stack* ps){
    if(Stack_intIsEmpty(ps))
    {
        printf("The Stack is Embty\n");
    }
    else{
        printf("Reverse Function Is Called\n");
        int i;
        int size=ps->Size;
        StackValue temp[size];
        for(i=0;i<size;i++)
        {
            temp[i]=Stack_intPop(ps);

        }
        for(i=0;i<size;i++)
        {
            Stack_voidPush(temp[i],ps);
        }
    }  
}
//Another Function To Reverse using Temp Variable
void Stack_voidReverse2(Stack* ps){
    if(Stack_intIsEmpty(ps))
    {
        printf("The Stack is Embty\n");
    }
    else{
        printf("Reverse Function Is Called\n");
        int size=ps->Size;
        int i;
        StackValue temp;
        for(i=0;i<size/2;i++)
        {
            temp=ps->Arr[ps->Top];
            ps->Arr[ps->Top]=ps->Arr[i];
            ps->Arr[i]=temp;
            ps->Top--;
        }
        ps->Top=size-1;
    }  
}
