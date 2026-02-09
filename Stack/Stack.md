# Stack

A `stack` is a linear non-primitive data structure where the insertion and deletion of element is done from the same end, referred to as the top of the stack.

The insertion operation is referred to as push and deletion operation is referred to as pop. In a stack, the last element inserted will be the first one to be retreived. Hence, stack is termed as `LIFO` (Last-in-First-out).

## Implementation of a stack using an array

Let `SIZE` denote the size of a stack implemented using an array `data[SIZE]`. Let `top` denote the end used for `push` and `pop` operations with an initial value of -1.

Insert image here

### Push
Before adding an element onto a stack, we first check whether the stack is full or not. The condition that denotes a full stack is 
```
top == SIZE - 1
```
. If the stack is not full, the `push` operation can be performed by the statement 
```
data[++top] = item;
```
If the stack is full and we try to push, it results in a condition called `overflow`.

A C function to perform push operation:

```c
void push(int a)
{
    if(top == SIZE - 1)
        printf("\nStack Overflow");
    else
        data[++top] = a;
}
```

### Pop
The main objective of the `pop` operation is to retrieve the top most element from the stack. Before retrieving, we check whether the stack is empty or not. The condition to check whether the stack is empty is 
```
top == -1
```
If the stack is not empty, the popped element is
```
data[top--]
```
If the stack is empty and we try to pop, it results in a condition called underflow.

A C function to perform pop operation:

```c
int pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
        return data[top--];
}
```

### Display
```c
void display()
{
    if(top == -1){
        printf("\nStack is empty.");    
        return;
    }
    
    for(int i = top; i > -1; i--)
        printf("%d ", data[i]);
}
```

Check the programs for full implementation of stack in C.

## Applications

### Reversing a String
Write a program to check if a given string is a palindrome or not using stack.

Check `palindrome.c`



### Checking Parenthesis Matching
Write a program to check for parenthesis balancing using stack.

Check `parenthesis.c`

### Conversion of Infix Expression to Postfix Expression
Write a program to convert a given infix expression to a postfix expression.

#### Algorithm:
1. Scan the given infix expression from left to right.
2. If the character is 
    1. an operand, place it on the postfix expression.
    2. a '(', push it onto the stack.
    3. a ')', pop the stack and place it on the postfix expression until we get a corresponding '('.
    4. an operator,
        - if stack is empty or top of the stack is '(' push the operator onto stack.
        - else check the precedence of the scanned symbol,
            - if the precedence is greater or equal to the precedence of the operator on top of stack, pop the stack content, place it on the postfix expression, push the scanned symbol onto stack.
            - else push the symbol onto the stack.
3. Pop the stack until the stack is empty and place the content on the postfix expression.

Note: the `^` operator is right associative.

Check `infix_to_postfix.c`
