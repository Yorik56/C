/*
    GNU/Linux et MacOS
        > gcc main.c $(sdl2-config --cflags --libs) -o prog
        > gcc *.c $(sdl2-config --cflags --libs) -o prog
    Windows
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define afficher printf
#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 960
#define FPS_LIMIT 16

void SDL_ExitWithError(const char *message);
void SDL_limitFPS(unsigned int limit_fps);

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");

    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(1280, 960, 0, &window, &renderer) != 0)
        SDL_ExitWithError("impossible de creer la fenetre et le rendu");

    /*------------------------------------------------------------*/
    SDL_bool program_launched = SDL_TRUE;
    unsigned int frames_limit = 0;

    /*
        //Affiche des milisecondes écoulées depuis le lancement du programme
        unsigned int ticks = 0;
        SDL_Delay(3000);
        ticks = SDL_GetTicks();
        afficher("%dms ecoulees.\n", ticks);
        //Calculs d'invervalles en milisecondes pour 30 et 60 fps
        1000 (1 seconde) / 30 (images) = 33ms
        1000 (1 seconde) / 60 (images) = 16ms
     */

    frames_limit = SDL_GetTicks() + FPS_LIMIT;
    //Délai pour limiter à 60fps
    limit_fps(frames_limit);
    frames_limit = SDL_GetTicks() + FPS_LIMIT;
    while(program_launched)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
    /*------------------------------------------------------------*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_limitFPS(unsigned int limit_fps)
{
    unsigned int ticks = SDL_GetTicks();
    if(limit_fps < ticks)
        return;
    else if (limit_fps > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit_fps - ticks);
}