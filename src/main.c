#include "SDL3/SDL.h"

int main()
{

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Atestat", 1270, 720, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  SDL_Event event;
  SDL_bool isRunning = SDL_TRUE;
  while(isRunning)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          isRunning = SDL_FALSE;
          break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
