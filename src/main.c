#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "arrayFunctions/arrayFunctions.h"
#include "algorithms/algorithms.h"
#include <SDL3/SDL_events.h>
#include <stdio.h>
#include "Main.h"

SDL_Renderer *renderer;
int timer_start;

SDL_Renderer *renderer;

enum appState {
  ALGO,
  MAIN_MENU,
  SELECTION
};
int algoNumber;

enum appState state;

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_Window *window = SDL_CreateWindow("Algoritmi de sortare - Vizualizator", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, NULL);

  state = MAIN_MENU;

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
        case SDL_EVENT_KEY_UP:
          switch (state) {
            case MAIN_MENU:
              state = SELECTION;
              break;
            case ALGO:
              state = SELECTION;
              break;
            case SELECTION:
              switch (event.key.keysym.sym) {
                case SDLK_1:
                  algoNumber = 1;
                  shuffleAray(array, n);
                  state = ALGO;
                  break;
                case SDLK_2:
                  algoNumber = 2;
                  shuffleAray(array, n);
                  state = ALGO;
                  break;
                case SDLK_3:
                  algoNumber = 3;
                  shuffleAray(array, n);
                  state = ALGO;
                  break;
                case SDLK_4:
                  algoNumber = 4;
                  shuffleAray(array, n);
                  state = ALGO;
                  break;
                case SDLK_5:
                  algoNumber = 5;
                  shuffleAray(array, n);
                  state = ALGO;
                  break;
                default:
                  break;
              
              }
              break;
          
          }
          break;
      }
    }
    printf("%d", state);

    //update
    if (state == ALGO)
      if (!isArraySorted(array, n))
      {
        switch (algoNumber) {
          case 1:
            quicksort(array, n, 0, n-1);
            break;
          case 2:
            simpleSort(array, n);
            break;
          case 3:
            bubbleSort(array, n);
            break;
          case 4:
            mergeSort(array, n, 0, n-1);
            break;
          case 5:
            insertionSort(array, n);
            break;
        }
        continue;
      }
    selectedID = -1;

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

  switch (state) {
    case ALGO:
      renderArray(renderer, array, n);
      break;
    case MAIN_MENU:
      break;
    case SELECTION:
      break;
  
  }

  SDL_RenderPresent(renderer);

  //fps controll
  int currentTime = SDL_GetTicks();
  int loopTime = timer_start - currentTime;
  SDL_Delay(minimumWaitTime - loopTime);
  timer_start = SDL_GetTicks();
}
