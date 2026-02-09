#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100

int top = -1;
int data[SIZE];

void push(int a)
{
    if(top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        data[++top] = a;
}

int pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else
        return data[top--];
}

int operate(int op1, char op, int op2)
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
    int a, op1, op2;
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
                push((int)(postfix[i] - '0'));
            }
        }
        else
        {
            op2 = pop();
            op1 = pop();
            a = operate(op1, postfix[i], op2);
            push(a);
        }
    }

    a = pop();
    printf("%d", a);
}

int main() 
{
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    evaluate_postfix(postfix);
    return 0;
}