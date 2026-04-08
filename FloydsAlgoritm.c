#include <stdio.h>
#define INF 999

int main() {
    int n, i, j, k;
    int a[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];

    printf("Shortest path matrix:");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf(" ");
    }
    return 0;
}
