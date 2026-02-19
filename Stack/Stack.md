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
    2. a `'('`, push it onto the stack.
    3. a `')'`, pop the stack and place it on the postfix expression until we get a corresponding `'('`.
    4. an operator,
        - if stack is empty or top of the stack is `'('` push the operator onto stack.
        - else check the precedence of the scanned symbol,
            - if the precedence is greater or equal to the precedence of the operator on top of stack, pop the stack content, place it on the postfix expression, push the scanned symbol onto stack.
            - else push the symbol onto the stack.
3. Pop the stack until the stack is empty and place the content on the postfix expression.

Note: the `^` operator is right associative.

Check `infix_to_postfix.c

### Conversion of Infix Expression to Prefix Expression
Write a program to convert a given infix expression to a prefix expression.
#### Algorithm:
1. Scan the expression from right to left
2. If the scanned symbol is
    1. operand, place it onto prefix expression.
    2. `')'`, push it onto stack.
    3. `'('`, pop the content of stack until you get a corresponding `')'`.
    4. operator, check if stack is empty or top of stack is `')'`. 
        - If yes, push the operator onto stack.
        - Else, check the precedence of the operator. While stack is not empty and the top of the stack is not `')'` and the precedence of the top of stack is greater than or equal to the precedence of the scanned symbol, pop the stack content and place it on the prefix expression and push the operator onto stack.
3. Pop the stack until it is empty and place the contents onto the prefix expression.
4. Reverse the prefix to get the actual result.

Check `infix_to_prefix.c`

### Evaluation of Postfix Expression
Write a program to evaluate a given postfix_expression.

#### Algorithm
1. Scan the given postfix expression from left to right.
2. If the scanned symbol is
    - operand, push it onto stack.
    - operator, pop two elements from stack and assign them to `operand2` and `operand1` respectively. Find the value of `operand1 operator operand2` and push the value onto the stack.
3. Pop the content of the stack to get the final answer.

Check `postfix_evaluation.c`

### Recursion
The process in which a function calls itself directly or indirectly is called recursion.

In the case of recursion, all the recursive function calls will be pushed onto stack, If there is no base case or case condition, the stack will overflow. To avoid this, every recursive function must have a base case.

A recursive function to find the factorial of a given number:
```c
int factorial(int n)
{
    if(n == 1) return 1;
    else return n * factorial(n - 1);
}
```

A recursive function to find the GCD of two numbers.
```c
int gcd(int x, int y)
{
    if(x == y) 
        return x;
    if(x > y)
        return gcd(x - y, y);
    if(x < y);
        return gcd(y, x);
}
```

A recursive function to perform binary search.
```c
int search(int *a, int low, int high, int key)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(a[mid] == key)
        return mid + 1;
    if(key < a[mid])
        search(a, low, mid - 1; key);
    if(key > a[mid])
        search(a, mid + 1, high, key);
}
```

A recursive function to solve Tower of Hanoi Problem.
```c
void tower_of_hanoi(int n, char a, char b, char c)
{
    if(n = 0) return;

    tower_of_hanoi(n - 1, a, c, b);
    printf("Move disc from %c to %c\n", a, b);
    tower_of_hanoi(n - 1, c, b, a);
}
```

In the Tower of Hanoi problem, we have 3 poles denoted by `source` (A), `destination` (B), and `temporary` (c). On the `source`, n discs are stacked one above the other in decreasing order of diameter.

The objective here is to move all the discs from the `source` to the `destination` such that the `destination` should have the same property as the `source`.

To achieve this, the rules are 
1. Only one disc can be moved across the poles.
2. At any time, the discs on a pole must be in descending order of size.

In general, the Tower of Hanoi problem can be solved recursively in the following manner.
1. Recursively move (n - 1) discs from `source` to `temporary` with the help of `destination`.
2. Move the nth disc from `source` to `destination`.
3. Recursively move (n - 1) discs from `temporary` to `destination` with the help of `source`.