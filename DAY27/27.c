/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30
*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newnode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2;

    while(temp1 != NULL) {
        temp2 = head2;
        while(temp2 != NULL) {
            if(temp1->data == temp2->data) {
                printf("%d\n", temp1->data);
                return;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    printf("No Intersection\n");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}