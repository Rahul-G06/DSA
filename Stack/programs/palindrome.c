#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack
{
    int top;
    char data[SIZE];
};

typedef struct stack stack;

void push(stack *s, char a)
{
    if(s->top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        s->data[++(s->top)] = a;
}

int pop(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
        return s->data[(s->top)--];
}

int check(stack *s, char* a)
{
    for(int i = 0; a[i]; ++i)
    {
        push(s, a[i]);
    }

    for(int i = 0; a[i]; ++i)
    {
        if(a[i] != pop(s))
            return 0;
    }

    return 1;
}

int main()
{
    stack s;
    s.top = -1;
    char a[100];

    printf("Enter a string: ");
    scanf("%s", a);

    check(&s, a) ? printf("The string is a palindrome\n") : printf("The string is not a palindrome\n");

    return 0;
}