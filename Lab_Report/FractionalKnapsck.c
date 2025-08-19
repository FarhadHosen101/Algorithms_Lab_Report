#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value, weight;
};

// Function to compare items by value/weight ratio (for qsort)
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? 1 : -1; // descending order
}

// Function to calculate maximum value in fractional knapsack
double fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items by decreasing value/weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            // Take the whole item
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of the remaining item
            totalValue += items[i].value * ((double)W / items[i].weight);
            break; // knapsack is full
        }
    }

    return totalValue;
}

// Main function
int main() {
    struct Item items[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    double maxProfit = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxProfit);

    return 0;
}
