#include <stdio.h>
int parent[10];
int find(int i) {
    while(parent[i]) i = parent[i];
    return i;
}
void uni(int i, int j) {
    parent[j] = i;
}

void main() {
    int n, i, j, a, b, u, v, min, cost = 0;
    int costmat[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &costmat[i][j]);
    for(i = 1; i <= n; i++) 
		parent[i] = 0;
    int ne = 1;
    while(ne < n) {
        min = 999;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(costmat[i][j] < min) {
                    min = costmat[i][j]; a = u = i; b = v = j;
                }
        u = find(u); 
	     v = find(v);
        if(u != v) {
            uni(u, v);
            cost += min;
            ne++;
        }
        costmat[a][b] = costmat[b][a] = 999;
    }
    printf("Minimum cost = %d", cost);
}
