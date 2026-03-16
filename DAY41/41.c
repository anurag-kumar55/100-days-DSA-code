/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct node* temp = front;
    printf("%d\n", front->data);
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int N;
    scanf("%d",&N);

    char operation[10];
    int value;

    for(int i=0;i<N;i++)
    {
        scanf("%s",operation);

        if(strcmp(operation,"enqueue")==0)
        {
            scanf("%d",&value);
            enqueue(value);
        }
        else if(strcmp(operation,"dequeue")==0)
        {
            dequeue();
        }
    }

    return 0;
}