#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100

int top = -1;
int data[SIZE];

void push(char a)
{
    if(top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        data[++top] = a;
}

char pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else
        return data[top--];
}

int operate(char op1, char op, char op2)
{
    switch(op)
    {
        case '+': 
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '%': 
            return op1 % op2; 
    }
}

int evaluate_postfix(char *postfix)
{
    int a;
    for(int i = 0; postfix[i]; ++i)
    {
        if(isalnum(postfix[i]))
        {
            if(isalpha(postfix[i]))
            {
                printf("Enter the value of %c:", postfix[i]);
                scanf("%d", &a);
                push(a);
            }
            else
            {
                push(postfix[i] - '0');
            }
        }
    }
}