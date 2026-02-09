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

void infix_to_prefix(char *infix, char *prefix)
{
    int i;
    int j = -1;
    for(i = 0; infix[i]; ++i);
    for(--i; i >= 0; --i)
    {
        char c = infix[i];
        if(isalnum(c))
        {
            prefix[++j] = c;
        }
        else if(c == ')') push(c);
        else if(c == '(')
        {
            while(peek() != ')') prefix[++j] = pop();
            pop();
        }
        else
        {
            if(top == -1 || peek() == ')') push(c);
            else
            {
                while(top > -1 && peek() != ')' && precedence(peek()) >= precedence(c)) 
                    prefix[++j] = pop();
                push(c);
            }
        }
    }
    while(top > -1)
        prefix[++j] = pop();

    prefix[++j] = '\0';

    for(i = 0, --j; i < j; ++i, --j)
    {
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}

int main() 
{
    char infix[100];
    char prefix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_prefix(infix, prefix);
    printf("The prefix expression is %s\n", prefix);
    return 0;
}