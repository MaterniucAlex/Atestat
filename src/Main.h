#ifndef MAIN
#define MAIN

#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 720

const int FPS = 30;
const int msInAsecond = 1000;
const int minimumWaitTime = msInAsecond / FPS;

void renderAndWait(int *array, int n);

int selectedID = 0;

#endif // !MAIN
