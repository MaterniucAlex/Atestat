#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 720

void shuffleAray(int *array, int n);
void renderArray(int *array, int n, SDL_Renderer *renderer);
int isArraySorted(int *array, int n);
void switchArrayItemsAndRender(int *array, int n, int i, int j);
void  simpleSort(int *array, int n);
void quicksort(int *arr, int n, int low, int high);
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int n, int left, int right);
void insertionSort(int arr[], int size);

int switchId = 0;
int selectedID = 0;

SDL_Renderer *renderer;

const int FPS = 30;
const int msInAsecond = 1000;
const int minimumWaitTime = msInAsecond / FPS;
int timer_start;

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_Window *window = SDL_CreateWindow("Algoritmi de sortare - Vizualizator", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, NULL);

  SDL_Event event;
  SDL_bool isRunning = SDL_TRUE;

  int n = 50;
  int array[n];

  shuffleAray(array, n);

  timer_start = SDL_GetTicks();

  while(isRunning)
  {
    //keyboard input
    while (SDL_PollEvent(&event))
    {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          isRunning = SDL_FALSE;
          break;
      }
    }

    //update
    if (!isArraySorted(array, n))
    {
      /*quicksort(array, n, 0, n-1);*/
      /*simpleSort(array, n);*/
      /*bubbleSort(array, n);*/
      /*mergeSort(array, n, 0, n-1);*/
      insertionSort(array, n);
      continue;
    }
    else {
      switchId = -1;
      selectedID = -1;
    }

    //render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    renderArray(array, n, renderer);

    SDL_RenderPresent(renderer);

    //fps controll
    int currentTime = SDL_GetTicks();
    int loopTime = timer_start - currentTime;
    SDL_Delay(minimumWaitTime - loopTime);
    timer_start = SDL_GetTicks();
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  return 0;
}

void shuffleAray(int *array, int n)
{
  for(int i = 0; i < n; i++)
    array[i] = n + 1 - i;
}

void renderArray(int *array, int n, SDL_Renderer *renderer)
{
  SDL_FRect itemRect;
  itemRect.w = SCREEN_WIDTH / n;

  for(int i = 0; i < n; i++)
  {
    itemRect.x = i * itemRect.w;
    itemRect.h = SCREEN_HEIGHT / (n + 1) * array[i];
    itemRect.y = SCREEN_HEIGHT - itemRect.h;

    if (i == selectedID)
      SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    else if (i == switchId)
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    else
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &itemRect);
  }
}

int isArraySorted(int *array, int n)
{
  for(int i = 1; i < n; i++)
    if (array[i-1] > array[i]) return 0;
  return 1;
}

void switchArrayItemsAndRender(int *array, int n, int i, int j)
{
  if (i >= n || j >= n) return;

  int ok = array[i];
  array[i] = array[j];
  array[j] = ok;

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
  SDL_RenderClear(renderer);

  renderArray(array, n, renderer);

  SDL_RenderPresent(renderer);

  //fps controll
  int currentTime = SDL_GetTicks();
  int loopTime = timer_start - currentTime;
  SDL_Delay(minimumWaitTime - loopTime);
  timer_start = SDL_GetTicks();
}

void simpleSort(int *array, int n)
{
  for(int i = 0; i < n-1; i++)
  {
    int min = i;
    selectedID = i;
    for(int j = i + 1; j < n; j++)
      if (array[j] < array[min]) min = j;
    switchId = min;
    switchArrayItemsAndRender(array, n, selectedID, switchId);
  }
}

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
    switchArrayItemsAndRender(arr, n, i + 1, high);
    return (i + 1); // return the index of the pivot element
}

// QuickSort function
void quicksort(int arr[], int n, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, n, low, high);
        
        // Recursively sort elements before and after the partition
        quicksort(arr, n, low, pi - 1);
        quicksort(arr, n, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {

        selectedID = j;
        switchId   = j+1;
        switchArrayItemsAndRender(arr, n, selectedID, switchId);
      }
    }
  }
}

void merge(int arr[], int n, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    // Merge the temporary arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        selectedID = k;
        switchArrayItemsAndRender(arr, n, k, k);
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        selectedID = k;
        switchArrayItemsAndRender(arr, n, k, k);
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        selectedID = k;
        switchArrayItemsAndRender(arr, n, k, k);
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, n, left, mid);
        mergeSort(arr, n, mid + 1, right);

        // Merge the sorted halves
        merge(arr, n, left, mid, right);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            selectedID = j + 1;
            switchArrayItemsAndRender(arr, size, j + 1, j + 1);
            j = j - 1;
        }

        arr[j + 1] = key;
        selectedID = j + 1;
        switchArrayItemsAndRender(arr, size, j + 1, j + 1);
    }
}