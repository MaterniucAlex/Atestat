#include "quickSort.h"
#include "../../arrayFunctions/arrayFunctions.h"
#include "../../Main.h"

int partition(int arr[], int n, int low, int high) {
  int pivot = arr[high]; // choose the last element as the pivot
  int i = low - 1; // pointer for the smaller element

  for (int j = low; j < high; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment the smaller element pointer
      /*switchArrayItemsAndRender(arr, n, i, j); // swap the elements*/
    }
  }
  // Swap the pivot element with the element at (i+1)
  setSelectedId(i+1);
  switchArrayItemsAndRender(arr, n, i + 1, high);
  return (i + 1); // return the index of the pivot element
}

// QuickSort function
void quicksort(int arr[], int n, int low, int high) {
  if (low < high) {
    // Partition the array and get the pivot index
  if (!isGameRunning()) return;
    int pi = partition(arr, n, low, high);

    // Recursively sort elements before and after the partition
    quicksort(arr, n, low, pi - 1);
    quicksort(arr, n, pi + 1, high);
  }
}
