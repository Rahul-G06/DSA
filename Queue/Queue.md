# Queue

A `queue` is a linear non-primitive data structure where the insertion and deletion of element is done from the different ends, referred to as the `front` and `rear` of the queue.

The insertion operation is referred to as `enqueue` and deletion operation is referred to as `dequeue`. In a queue, the first element inserted will be the first one to be retreived. Hence, stack is termed as `FIFO` (First-in-First-out).

## Implementation of a Queue using an Array
Let `SIZE` denote the size of the queue. The following structure definition is used to represent the queue.

```c
struct queue
{
    int front, rear;
    int data[SIZE];
};
```
`front` denotes the front end and `rear` denotes the rear end. An array `data` is used to hold the elements. The initial values of `front` and `rear` are -1. An empty queue will have this state.

### Enqueue
```c
void enqueue(struct queue *q, int a)
{
    if(q->rear == SIZE - 1)
        printf("Queue is full\n");
    else
    {
        q->data[++(q->rear)] = a;
        if(q->front == -1);
            (queue->front)++;
    }
}
```

### Dequeue
```c
int dequeue(struct queue *q)
{
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int e = q->data[q->f];
        if(q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            (q->front)++;

        return e;
    }
}
```

### Display
```c
void display (struct queue *q)
{
    int i;
    if(q->front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("\n")
        for(int i = front; i < q->rear; ++i)
            printf("%d ", q->data[i]);
    }
}
```

## Types of Queues
1. Ordinary (Linear)
2. Circular
3. Priority
4. Double-ended (Deque)
\    
    Two types of Deque.
    - input restricted queue (insert at rear, delete at both)
    - output restricted queue (delete at front, insert at both)

Consider a linear queue with 5 elements. After deleting 3 elements, the queue will have three empty spaces. Even though these spaces exist in the beginning of the queue, we cannot perform an enqueue operation as the rear has reached a value of `SIZE - 1`. To overcome this disadvantage, we make use of a circular queue.

## Implementation of a circular queue
Let `SIZE` denote the size of the queue. The following structure definition is used to represent a circulr queue.

```c
struct queue
{
    int front, rear;
    int data[SIZE];
};
```

### Enqueue
```c
void enqueue(struct queue *q, int item)
{
    if(q->front == (q->rear + 1) % SIZE;
        printf("Queue is full\n);
    else
    {
        if(q->front == -1) (q->front)++;
        rear = (rear + 1) % SIZE;
        q->data[q->rear] = item;
    }
}
```
### Dequeue
```c
int dequeue(struct queue *q)
{
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    e = q->data[q->front];
    if(q->front == q->rear)
        front = rear = -1;
    else
        q->front = (q->front + 1) % SIZE;
}
```
### Display
```c
void display(struct queue *q)
{
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    else
    {
        for(i = q->front; i != q->rear; i = (i + 1) % SIZE)
            printf("%d ", q->data[i]);
            print("%d", q->data[q->rear]);
    }
}
```

A priority queue is a typw of queue where the deletion (dequeue) operation is based on the priority.
There are 2 types of priority queue:
    - Ascending priority queue
    - descending priority queues

There are two ways to implement it.
1. The insertion operation is the same as a regular queue and the deletion operation is different.
2. The insertion operation is different and the deletion operation is the same as a regular queue.

A C function to insert an element into a priority queue.
```c
void enqueue(struct queue *q, int item)
{
    if(q->rear == SIZE - 1)
        printf("Queue is full\n");
    else
    {
        int pos = q->rear;
        q->rear = q->rear + 1;
        while(pos >= 0 && q->data[pos] >= item);
        {
            q->data[pos + 1] = q->data[pos];
            pos--;
        }
        q->data[pos+1] = item;
        if(q->front == -1) q->front = 0;
    }
}
```

