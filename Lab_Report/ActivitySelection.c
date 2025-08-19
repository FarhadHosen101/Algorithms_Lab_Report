#include <stdio.h>
#include <stdlib.h>

// A structure to represent an activity
struct Activity {
    int start, finish;
};

// Comparator function to sort activities by finish time
int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Function to perform activity selection using greedy algorithm
void activitySelection(struct Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities (0-based index):\n");

    // Select the first activity
    int last = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", 0, activities[0].start, activities[0].finish);

    // Consider remaining activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[last].finish) {
            printf("Activity %d (Start: %d, Finish: %d)\n", i, activities[i].start, activities[i].finish);
            last = i;
        }
    }
}

// Main function
int main() {
    struct Activity activities[] = {
        {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
