#include <stdio.h>
#include <limits.h>

int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = (dp[i][j] < (matrixChainMemoised(p, i, k)
                          + matrixChainMemoised(p, k + 1, j)
                          + p[i - 1] * p[k] * p[j])) ? dp[i][j] : (matrixChainMemoised(p, i, k)
                          + matrixChainMemoised(p, k + 1, j)
                          + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

int MatrixChainOrder(int p[], int n) {
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // Corrected this line

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, n));
    return 0;
}
