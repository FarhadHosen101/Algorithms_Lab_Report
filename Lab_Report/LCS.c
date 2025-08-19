#include <stdio.h>
#include <string.h>

// Function to find max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find LCS length using Dynamic Programming
int lcs(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build dp[][] table in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n]; // Final answer in bottom-right cell
}

// Main function
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcs(X, Y, m, n);
    printf("Length of LCS = %d\n", length);

    return 0;
}
