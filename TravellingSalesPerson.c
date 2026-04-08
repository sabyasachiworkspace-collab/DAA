#include <stdio.h>
#include <limits.h>
#define N 4
#define INF 999

int tsp(int n, int cost[N][N]) {
    int dp[1<<N][N];
    for(int i=0; i<(1<<N); i++)
        for(int j=0; j<N; j++)
            dp[i][j] = INF;
     dp[1][0] = 0; // start from vertex 0
    for(int mask = 1; mask < (1<<N); mask += 2) { // only masks including 0
        for(int u = 0; u < N; u++) {
            if(!(mask & (1<<u))) continue;
            for(int v = 0; v < N; v++) {
                if(mask & (1<<v)) continue;
                if(dp[mask][u] + cost[u][v] < dp[mask | (1<<v)][v])
                    dp[mask | (1<<v)][v] = dp[mask][u] + cost[u][v];
            }
        }
    }
    int min_cost = INF;
    for(int i = 1; i < N; i++) {
        if(dp[(1<<N)-1][i] + cost[i][0] < min_cost)
            min_cost = dp[(1<<N)-1][i] + cost[i][0];
    }
    return min_cost;
}

int main() {
    int n = N;
    int cost[N][N];
    printf("Enter cost matrix:\n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &cost[i][j]);
    int min_cost = tsp(n, cost);
    printf("Minimum cost of TSP = %d\n", min_cost);
    return 0;
}

