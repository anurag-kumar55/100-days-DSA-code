/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

Input:
6
6
5 2
5 0
4 0
4 1
2 3
3 1

Output:
5 4 2 3 1 0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main() {
    int n, m;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX], index = 0;

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while(front <= rear) {
        int node = queue[front++];
        topo[index++] = node;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    if(index != n) {
        printf("Cycle detected");
    } else {
        for(int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}