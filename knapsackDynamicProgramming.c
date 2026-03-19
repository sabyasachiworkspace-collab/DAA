#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void main() {
    int n, W[20], P[20], CAP;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights of items:\n");
    for(int i = 1; i <= n; i++) 
scanf("%d", &W[i]);
    printf("Enter profits of items:\n");
    for(int i = 1; i <= n; i++) 
scanf("%d", &P[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &CAP);
    int DP[n+1][CAP+1];
    for(int i = 0; i <= n; i++)
        for(int w = 0; w <= CAP; w++)
            DP[i][w] = 0;
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= CAP; w++) {
            if(W[i] <= w)
                DP[i][w] = max(P[i] + DP[i-1][w-W[i]], DP[i-1][w]);
            else
                DP[i][w] = DP[i-1][w];
        }
    }
    printf("Maximum Profit = %d\n", DP[n][CAP]);
}
