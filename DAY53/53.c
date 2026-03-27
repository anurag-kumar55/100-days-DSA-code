/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[MAX];
    int front = 0, rear = 0;

    q[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = q[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int hd[MAX];  

    int front = 0, rear = 0;

    int vertical[200][MAX] = {0};
    int count[200] = {0};

    int min = 0, max = 0;

    q[rear] = root;
    hd[rear++] = 100; 

    while (front < rear) {
        struct Node* node = q[front];
        int h = hd[front++];
        
        vertical[h][count[h]++] = node->data;

        if (h < min) min = h;
        if (h > max) max = h;

        if (node->left) {
            q[rear] = node->left;
            hd[rear++] = h - 1;
        }

        if (node->right) {
            q[rear] = node->right;
            hd[rear++] = h + 1;
        }
    }
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", vertical[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}