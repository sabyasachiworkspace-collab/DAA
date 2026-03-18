#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
// Function to find the length of the LCS using Dynamic Programming
void lcsLength(char *X, char *Y, int m, int n, int dp[][n + 1]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Base case: LCS of an empty string with any string is 0
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match, add 1 to diagonal value
            } else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]); // Characters don't match, take max of top or left values
            }
        }
    }
}
// Function to reconstruct and print the LCS from the dp table
void printLCS(char *X, char *Y, int m, int n, int dp[][n + 1]) {
    int length = dp[m][n];
    char lcs[length + 1];
    lcs[length] = '\0'; // Null-terminate the string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1]; // Found a matching character, add to LCS
            i--;
            j--;
            length--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up if the value above is greater
        } else {
            j--; // Move left otherwise
        }
    }
    printf("Longest Common Subsequence: %s\n", lcs);
}
int main() {
    char X[10],Y[15];
    printf("1st string:");
    scanf("%s",X);
    printf("2nd string:");
    scanf("%s",Y);
    int m = strlen(X);
    int n = strlen(Y);
    // Create a 2D array to store the lengths of common subsequences
    // Size is (m+1)x(n+1) to handle base cases (empty strings)
    int dp[m + 1][n + 1];
    lcsLength(X, Y, m, n, dp);
    printf("Length of LCS: %d\n", dp[m][n]);
    printLCS(X, Y, m, n, dp);
    return 0;
}
