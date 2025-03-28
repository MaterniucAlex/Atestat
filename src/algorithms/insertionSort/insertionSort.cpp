#include "insertionSort.h"
#include "../../arrayFunctions/arrayFunctions.h"
#include "../../Main.h"

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key, to one position ahead
    // of their current position
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      if (!isGameRunning()) return;
      setSelectedId(j+1);
      switchArrayItemsAndRender(arr, size, j + 1, j + 1);
      j = j - 1;
    }

    arr[j + 1] = key;
    setSelectedId(j+1);
    switchArrayItemsAndRender(arr, size, j + 1, j + 1);
  }
}
