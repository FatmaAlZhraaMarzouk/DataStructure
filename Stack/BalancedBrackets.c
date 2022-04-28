/**************************************************/
/*  AUTHOR      : Fatma AlZahraa Marzouk Gaber    */
/*  Description : BalancedBrackets using Stack    */
/*  Date        : 27/12/2021                      */
/* Version      : V01                             */
/**************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>  
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
int Stack_intReturnTop(Stack* ps);
int Stack_intIsFull(Stack* ps);
int Stack_intIsEmpty(Stack* ps);
int Stack_intReturnSize(Stack* ps);
StackValue Stack_intPop(Stack* ps);
int BalancedBrackets(char *Str);
int main(){

    char str[10];
    printf("Enter Brackets to Check : ");
    scanf("%s",str);
    
    if(BalancedBrackets(str))
    {
        printf("Balanced Brackets\n");
    }else{
        printf("Not Balanced Brackets\n");
    }
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
int BalancedBrackets(char *str){
    Stack S1;
    Stack_voidInit(&S1);
    int i;
    char c;
    int len = strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            Stack_voidPush(str[i],&S1);
            continue;
        }
        if(str[i]==')'||str[i]=='}'||str[i]==']')
        {
            if(Stack_intIsEmpty(&S1)){
                return 0;
            }
            else{
                c=Stack_intPop(&S1);
                if (c == '(' && str[i] == ')')
                    return 1;
                else if (c == '{' && str[i]  == '}')
                    return 1;
                else if (c == '[' && str[i]  == ']')
                    return 1;
                else
                    return 0;
            }
        }
    }
    if (Stack_intIsEmpty(&S1))
        return 1; // balanced
    else
        return 0; // not balanced
}