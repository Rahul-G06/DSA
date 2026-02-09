#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stack
{
    int top;
    int data[SIZE];
};

typedef struct stack stack;

void push(stack *s, int a)
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
        return -1;
    }
    else
        return s->data[(s->top)--];
}

void display(stack *s)
{
    if(s->top == -1){
        printf("Stack is empty\n");    
        return;
    }
    
    for(int i = s->top; i > -1; i--)
        printf("%d ", s->data[i]);

    printf("\n");
}

int main()
{
    int choice, a;
    stack s;
    s.top = -1;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("Enter element to be pushed: ");
                scanf("%d", &a);
                push(&s, a);
                break;
            case 2:
                a = pop(&s);
                if (a != -1) printf("Popped element is %d\n", a);
                break;
            case 3: 
                display(&s);
                break;
            case 4:
                return 0;
        }
    }

    return 0;
}