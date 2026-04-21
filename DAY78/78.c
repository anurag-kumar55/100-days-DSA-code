/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6
*/
#include <stdio.h>
#include <limits.h>

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 1; v <= n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n+1][n+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[n+1], mstSet[n+1];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;
    int total = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                key[v] = graph[u][v];
    }

    printf("%d\n", total);
    return 0;
}