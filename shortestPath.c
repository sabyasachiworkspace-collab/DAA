#include <stdio.h>
#define INF 999
int main() {
    int n, i, j, src;
    int cost[10][10], dist[10], visited[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (999 for no edge):");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);
    for(i = 0; i < n; i++) 
	dist[i] = cost[src][i];
    visited[src] = 1;

    for(i = 1; i < n; i++) {
        int min = INF, u = -1;
        for(j = 0; j < n; j++)
            if(!visited[j] && dist[j] < min) {
                min = dist[j]; u = j;
            }
        visited[u] = 1;
        for(j = 0; j < n; j++)
            if(!visited[j] && dist[j] > dist[u] + cost[u][j])
                dist[j] = dist[u] + cost[u][j];
    }

    printf("Shortest distances:");
    for(i = 0; i < n; i++)
        printf("%d -> %d = %d", src, i, dist[i]);

    return 0;
}
