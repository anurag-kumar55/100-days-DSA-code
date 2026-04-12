/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

Input

5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
0

Output

0 2 3 9 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, weight;
} Node;

typedef struct {
    Node arr[MAX];
    int size;
} MinHeap;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *h, int idx) {
    while (idx && h->arr[(idx - 1) / 2].weight > h->arr[idx].weight) {
        swap(&h->arr[idx], &h->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void heapifyDown(MinHeap *h, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < h->size && h->arr[l].weight < h->arr[smallest].weight)
        smallest = l;
    if (r < h->size && h->arr[r].weight < h->arr[smallest].weight)
        smallest = r;

    if (smallest != idx) {
        swap(&h->arr[idx], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int v, int weight) {
    h->arr[h->size].v = v;
    h->arr[h->size].weight = weight;
    heapifyUp(h, h->size);
    h->size++;
}

Node pop(MinHeap *h) {
    Node root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap *h) {
    return h->size == 0;
}

typedef struct AdjNode {
    int v, weight;
    struct AdjNode* next;
} AdjNode;

AdjNode* graph[MAX];

void addEdge(int u, int v, int w) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->v = v;
    node->weight = w;
    node->next = graph[u];
    graph[u] = node;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (!isEmpty(&h)) {
        Node cur = pop(&h);
        int u = cur.v;

        AdjNode* temp = graph[u];
        while (temp) {
            int v = temp->v;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) graph[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}