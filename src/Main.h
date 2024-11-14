#pragma once
#ifndef MAIN
#define MAIN

#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 720

static const int FPS = 30;
static const int msInAsecond = 1000;
static const int minimumWaitTime = msInAsecond / FPS;

void renderAndWait(int *array, int n);

static int selectedID = 0;

#endif // !MAIN
