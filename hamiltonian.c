#include <stdio.h>
int n, graph[10][10], path[10];
int isSafe(int v, int pos) {
    if(!graph[path[pos-1]][v])
		 return 0;
    for(int i = 0; i < pos; i++)
        if(path[i] == v) 
		return 0;
    return 1;
}
int hamCycle(int pos) {
    if(pos == n) 
		return (graph[path[pos-1]][path[0]]);
    for(int v = 1; v < n; v++) {
        if(isSafe(v, pos)) {
            path[pos] = v;
            if(hamCycle(pos+1)) 
		return 1;
            path[pos] = -1;
        }
    }
    return 0;
}
void main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    for(i = 0; i < n; i++) 
		path[i] = -1;
    path[0] = 0;

    if(hamCycle(1)) 
		printf("Hamiltonian cycle exists");
    else 
		printf("No Hamiltonian cycle");
}
