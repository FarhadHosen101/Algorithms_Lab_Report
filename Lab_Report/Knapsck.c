#include <stdio.h>

// Function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    // Build table K[][] bottom up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W]; // maximum value that can be put in knapsack of capacity W
}

// Main function
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);

    int maxProfit = knapsack(W, wt, val, n);
    printf("Maximum profit = %d\n", maxProfit);

    return 0;
}
