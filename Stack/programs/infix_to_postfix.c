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

char peek()
{
    if(top == -1)
    {
        return '\0';
    }
    else
        return data[top];
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default: 
            return -1;
    }
}

void infix_to_postfix(char *infix, char *postfix)
{   
    char c;
    int j = -1;
    for(int i = 0; infix[i]; ++i)
    {
        
        c = infix[i];
        if(isalnum(c)) postfix[++j] = c;
        else
        {
            if(c == '(') push(c);
            else if(c == ')')
            {
                while(peek() != '(') postfix[++j] = pop();
                pop();
            }
            else
            {
                if(peek() == '\0' || peek() == '(') push(c);
                else
                {
                    if(c == '^') push(c);
                    else
                    {
                        int p = precedence(c);
                        if(p > precedence(peek())) push(c);
                        else
                        {
                            while(top != -1 && peek() != '(' && precedence(peek()) >= p) postfix[++j] = pop();
                            push(c);
                        }
                    }
                }
            }
        }
    }

    while(top != -1) postfix[++j] = pop();
    postfix[++j] = '\0';
    return;
}

int main() 
{
    char infix[100];
    char postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("The postfix expression is %s\n", postfix);
    return 0;
}