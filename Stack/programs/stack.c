#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

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
        printf("Stack Underflow\n");
        return -1;
    }
    else
        return data[top--];
}

void display()
{
    if(top == -1){
        printf("Stack is empty\n");    
        return;
    }
    
    for(int i = top; i > -1; i--)
        printf("%d ", data[i]);

    printf("\n");
}

int main()
{
    int choice, a;
    
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
                push(a);
                break;
            case 2:
                a = pop();
                if (a != -1) printf("Popped element is %d\n", a);
                break;
            case 3: 
                display();
                break;
            case 4:
                return 0;
        }
    }

    return 0;
}