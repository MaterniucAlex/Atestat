#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "arrayFunctions/arrayFunctions.h"
#include "algorithms/algorithms.h"
#include "Main.h"
#include "stdio.h"

SDL_Renderer *renderer;
int timer_start;

SDL_Event event;
SDL_bool isRunning = SDL_TRUE;

SDL_Texture *mainMenu;
SDL_Texture *algos;
SDL_Texture *background;
SDL_Texture *quicksortExpl;
SDL_Texture *simpleSortExpl;
SDL_Texture *bubbleSortExpl;
SDL_Texture *mergeSortExpl;
SDL_Texture *insertionSortExpl;

enum appState {
  ALGO,
  MAIN_MENU,
  QUICKSORT_EXPL,
  SIMPLESORT_EXPL,
  BUBBLESORT_EXPL,
  MERGESOT_EXPL,
  INSERTIONSORT_EXPL,
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
  background = IMG_LoadTexture(renderer, "assets/bg.png");
  mainMenu = IMG_LoadTexture(renderer, "assets/MainMenu.png");
  algos    = IMG_LoadTexture(renderer, "assets/Algo.png");
  quicksortExpl    = IMG_LoadTexture(renderer, "assets/quickSort.png");
  simpleSortExpl    = IMG_LoadTexture(renderer, "assets/simpleSort.png");
  bubbleSortExpl    = IMG_LoadTexture(renderer, "assets/bubbleSort.png");
  mergeSortExpl    = IMG_LoadTexture(renderer, "assets/mergeSort.png");
  insertionSortExpl    = IMG_LoadTexture(renderer, "assets/insertionSort.png");
  printf("%s\n", SDL_GetError());
  
  state = MAIN_MENU;

  int n = 50;
  int array[n];

  shuffleAray(array, n);

  timer_start = SDL_GetTicks();

  while(isRunning)
  {
    //keyboard input
    handleEvents(array, n);

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
    setSelectedId(-1);

    renderAndWait(array, n);
  }

  SDL_DestroyTexture(mainMenu);
  SDL_DestroyTexture(algos);
  SDL_DestroyTexture(background);
  SDL_DestroyTexture(quicksortExpl);
  SDL_DestroyTexture(simpleSortExpl);
  SDL_DestroyTexture(bubbleSortExpl);
  SDL_DestroyTexture(mergeSortExpl);
  SDL_DestroyTexture(insertionSortExpl);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  return 0;
}

void renderAndWait(int *array, int n)
{
  SDL_FRect screen;
  screen.x = 0;
  screen.y = 0;
  screen.w = SCREEN_WIDTH;
  screen.h = SCREEN_HEIGHT;

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
  SDL_RenderClear(renderer);
  SDL_RenderTexture(renderer, background, &screen, &screen);

  switch (state) {
    case INSERTIONSORT_EXPL:
      SDL_RenderTexture(renderer, insertionSortExpl, &screen, &screen);
      break;
    case MERGESOT_EXPL:
      SDL_RenderTexture(renderer, mergeSortExpl, &screen, &screen);
      break;
    case BUBBLESORT_EXPL:
      SDL_RenderTexture(renderer, bubbleSortExpl, &screen, &screen);
      break;
    case SIMPLESORT_EXPL:
      SDL_RenderTexture(renderer, simpleSortExpl, &screen, &screen);
      break;
    case QUICKSORT_EXPL:
      SDL_RenderTexture(renderer, quicksortExpl, &screen, &screen);
      break;
    case MAIN_MENU:
      SDL_RenderTexture(renderer, mainMenu, &screen, &screen);
      break;
    case SELECTION:
      SDL_RenderTexture(renderer, algos, &screen, &screen);
      break;
    case ALGO:
      renderArray(renderer, array, n);
      break;
  
  }

  SDL_RenderPresent(renderer);

  //fps controll
  int currentTime = SDL_GetTicks();
  int loopTime = timer_start - currentTime;
  SDL_Delay(minimumWaitTime - loopTime);
  timer_start = SDL_GetTicks();
}

void handleEvents(int *array, int n)
{
  while (SDL_PollEvent(&event))
  {
    switch (event.type) {
      case SDL_EVENT_QUIT:
        isRunning = SDL_FALSE;
        forceSortArray(array, n);
        break;
      case SDL_EVENT_KEY_UP:
        switch (state) {
          case MAIN_MENU:
            state = SELECTION;
            break;
          case ALGO:
            forceSortArray(array, n);
            state = SELECTION;
            break;
          case SELECTION:
            // printf("%d\n", event.key.keysym.sym);
            switch (event.key.keysym.sym) {
              case SDLK_1:
              case 131072:
                algoNumber = 1;
                shuffleAray(array, n);
                state = QUICKSORT_EXPL;
                break;
              case SDLK_2:
              case 196608:
                algoNumber = 2;
                shuffleAray(array, n);
                state = SIMPLESORT_EXPL;
                break;
              case SDLK_3:
              case 262144:
                algoNumber = 3;
                shuffleAray(array, n);
                state = BUBBLESORT_EXPL;
                break;
              case SDLK_4:
              case 327680:
                algoNumber = 4;
                shuffleAray(array, n);
                state = MERGESOT_EXPL;
                break;
              case SDLK_5:
              case 393216:
                algoNumber = 5;
                shuffleAray(array, n);
                state = INSERTIONSORT_EXPL;
                break;
              default: break;
            }
            break;
          case QUICKSORT_EXPL:
          case SIMPLESORT_EXPL:
          case BUBBLESORT_EXPL:
          case MERGESOT_EXPL:
          case INSERTIONSORT_EXPL:
            state = ALGO;
            break;
        }
        break;
    }
  }
}

int selectedID = 0;

void setSelectedId(int id)
{
  selectedID = id;
}

int getSelectedId()
{
  return selectedID;
}

int isGameRunning()
{
  return state == ALGO;
}
