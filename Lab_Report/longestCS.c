#include <stdio.h>
#include <string.h>

// Function to find max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to find LCS length
int lcs(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
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
