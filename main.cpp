#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define TILE_SIZE 20

void renderBoard(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255); // Set the color to white

  for (int i = 0; i <= SCREEN_WIDTH / TILE_SIZE; i++)
  {
    SDL_RenderDrawLine(renderer, i * TILE_SIZE, 0, i * TILE_SIZE, SCREEN_HEIGHT);
  }
  for (int j = 0; j <= SCREEN_HEIGHT / TILE_SIZE; j++)
  {
    SDL_RenderDrawLine(renderer, 0, j * TILE_SIZE, SCREEN_WIDTH, j * TILE_SIZE);
  }
}

int main(int argc, char **argv)
{
  SDL_Window *window = SDL_CreateWindow("Hunger Games", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
  if (window == NULL)
  {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  int quit = 0;
  while (!quit)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
        quit = 1;
      }
    }

    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer); // Clear the renderer with the background color

    renderBoard(renderer); // Draw the grid lines

    SDL_RenderPresent(renderer); // Present the renderer
    // SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
  }

  SDL_Quit();

  return 0;
}