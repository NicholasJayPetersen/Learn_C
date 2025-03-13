#include <stdio.h>

#define MAX_VALUE 100  // Adjust based on your range

void countDuplicates(int arr[], int size) {
    int freq[MAX_VALUE] = {0};  // Frequency array

    // Count occurrences
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Display duplicates
    printf("Duplicate counts:\n");
    for (int i = 0; i < MAX_VALUE; i++) {
        if (freq[i] > 1) {
            printf("Value %d: %d times\n", i, freq[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 3, 1, 6, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    countDuplicates(arr, size);
    return 0;
}
