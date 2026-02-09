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

int check(char* s)
{
    for(int i = 0; s[i]; ++i)
    {
        if(s[i] == '(') push(s[i]);
        else if(s[i] == ')')
        {
            if(top > -1 && pop() != '(') 
                return 0;
        }
    }

    return top == -1 ? 1 : 0;
}

int main()
{
    char a[100];

    printf("Enter a parentheses expression: ");
    scanf("%s", a);

    check(a) ? printf("Valid\n") : printf("Invalid\n");

    return 0;
}