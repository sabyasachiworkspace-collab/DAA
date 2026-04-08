#include <stdio.h>
#define INF 999
int main() {
    int n, i, j, ne = 1, min, cost = 0;
    int costmat[10][10], visited[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &costmat[i][j]);

    visited[1] = 1;

    while(ne < n) {
        min = INF;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(costmat[i][j] < min && visited[i] && !visited[j]) {
                    min = costmat[i][j];
                }
        cost += min;
        ne++;
    }

    printf("Minimum cost = %d", cost);
    return 0;
}
