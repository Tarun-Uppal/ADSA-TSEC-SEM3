#include <stdio.h>

// Function declarations
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

void printArray(int arr[], int size);

int main() {
    int arr1[] = {38, 27, 43, 3, 9, 82, 10};
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original array:\n");
    printArray(arr1, size);

    // Demonstration of Merge Sort
    mergeSort(arr1, 0, size - 1);
    printf("\nArray sorted using Merge Sort:\n");
    printArray(arr1, size);

    // Demonstration of Quick Sort
    quickSort(arr2, 0, size - 1);
    printf("\nArray sorted using Quick Sort:\n");
    printArray(arr2, size);

    return 0;
}

// ==========================================
// MERGE SORT IMPLEMENTATION
// ==========================================

// Main recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left/right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Merges two subarrays: arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ==========================================
// QUICK SORT IMPLEMENTATION
// ==========================================

// Helper function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // partitionIndex is partitioning index, arr[partitionIndex] is now at right place
        int partitionIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

/* Places the last element as pivot, places smaller elements to 
   the left of pivot, and larger elements to the right */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// ==========================================
// HELPER FUNCTION
// ==========================================

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}