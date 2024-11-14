#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "arrayFunctions/arrayFunctions.h"
#include "algorithms/algorithms.h"
#include "Main.h"

SDL_Renderer *renderer;
int timer_start;

SDL_Renderer *renderer;

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
      mergeSort(array, n, 0, n-1);
      /*insertionSort(array, n);*/
      continue;
    }
    else selectedID = -1;

    renderAndWait(array, n);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  return 0;
}

void renderAndWait(int *array, int n)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
  SDL_RenderClear(renderer);

  renderArray(renderer, array, n);

  SDL_RenderPresent(renderer);

  //fps controll
  int currentTime = SDL_GetTicks();
  int loopTime = timer_start - currentTime;
  SDL_Delay(minimumWaitTime - loopTime);
  timer_start = SDL_GetTicks();
}
