#include <stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve Rod Cutting problem using Dynamic Programming
int rodCutting(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;  // no profit for length 0

    // Build the dp[] array in bottom-up manner
    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];  // maximum profit for rod length n
}

// Main function
int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    int maxProfit = rodCutting(price, n);
    printf("Maximum obtainable value is %d\n", maxProfit);

    return 0;
}
