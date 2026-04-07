/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order

Input:

n = 5
edges:
0 1
0 2
1 3
1 4
source = 0

Output:

BFS Traversal: 0 2 1 4 3
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int vertex;
    struct Node* next;
};
int queue[MAX];
int front = -1, rear = -1;
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}
void BFS(struct Node* adj[], int n, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    struct Node* adj[MAX];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }
    printf("Enter source vertex: ");
    scanf("%d", &start);

    BFS(adj, n, start);

    return 0;
}