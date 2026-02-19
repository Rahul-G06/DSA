# Linked List
A `linked list` is defined as a collection of sequential data items. These sequential data items are termed as `nodes`. A linked list is a collection of nodes.

Linked lists use dynamic memory allocation.

A node in a linked list has two fields
1. Information field, where information is stored.
2. Link field, which holds the address of the next node.

A node in a linked list can be represented with the following structure definition.
```c
struct node
{
    int info;
    struct node *link;
};
```
There are four types of linked list:
1. Singly linked list
\
    Here, apart from the infomation field, each node has a link that contains only one address. i.e., address of the next node, and the last node link field contains `NULL`;
2. Circular singly linked list:
\
    A singly linked list where the last node contains the address of the first node.
3. Doubly linked list:
\
    here, each node contains the info field and the link field contains 2 addresses, addresses of the previous node and the next node.
4. Circular doubly linked list
\

## Singly Linked List
To implement a singly linked list, we'll consider the following structure definition to represent a node.

```c
struct node;
{
    int info;
    struct node *link;
};

typedef struct node node;
```

### Insertion
To insert a node at the front end, create a new node, assign the value to the `info` field and set the `link` to `head`.
```c
node insertFront(node head, int val)
{
    node* temp = (node*) malloc(sizeof(node));
    temp->info = val;
    temp->link = head;

    return temp;
}
```
To insert a node at the rear end, create a new node, assign the value to the `info` field and set the `link` to `NULL`. Traverse till you reach the last node of the linked list and then
```c
node insertRear(node head, int val)
{
    node* temp = (node*) malloc(sizeof(node));
    temp->info = val;
    temp->link = NULL;

    if(head == NULL) return temp;
    else
    {
        node* cur = head;
        while(cur->link != NULL)
            cur = cur->link;

        cur->link = temp;
        return head;
    }
}
```

### Deletion
To delete a node at the front end, store the address of the first node in a temporary pointer `temp` and point `head` to the next node. set the `link` of `temp` to `NULL` and free it. Return `head`:
```c
node deleteFront(node* head)
{
    if(head == NULL) return NULL;
    
    node* temp = head;
    head = head->link;

    temp->link = NULL;
    free(temp);

    return head;
}
```

To delete a node at the rear end, traverse the linked list till you reach the last node. Free the memory of the last node. If the second last node is `NULL` return `NULL`. Otherwise set the `link` of the second last node to `NULL` and return `head`. 
```c
node deleteRear(node* head)
{
    if(head == NULL) return NULL;

    prev = NULL;
    temp = head;

    while(temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    free(temp);
    if(prev == NULL) return NULL;
    else return head;
}
```

### Displaying

```c
void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->head);
        temp = temp->next;
    }
}
```