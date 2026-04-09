/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists

Input:
Enter number of vertices: 4
Enter number of edges: 4
Enter edges (u v):
0 1
1 2
2 3
3 1
Output:
YES
*/
#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int n;                
int adj[MAX][MAX];      
bool visited[MAX];      
bool recStack[MAX];     
bool dfs(int v) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i]) {
                return true; 
            }
        }
    }

    recStack[v] = false; 
    return false;
}
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n)
            adj[u][v] = 1;
        else
            printf("Invalid edge ignored: %d %d\n", u, v);
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}