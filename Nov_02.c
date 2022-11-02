#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

// This function prints contents of linked list starting
// from the given Node

void printList(struct Node*n)
{
    while(n!=Node)
    {
        printf("%d", n->data);
        n=n->next;

    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 100; // assign data in first node
    head->next = second; //Link first node with second

    second->data = 150; //assign data to second node
    second->next = third;

    third->data = 800;
    third->next = NULL;

    printfList(head);

}
