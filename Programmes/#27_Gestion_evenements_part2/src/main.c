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

void SDL_ExitWithError(const char *message);

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

    while(program_launched)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
//                case SDL_MOUSEMOTION:
//                    afficher("%d / %d\n", event.motion.x, event.motion.y);
//                    break;
                /*
                    SDL_BUTTON_LEFT
                    SDL_BUTTON_MIDDLE
                    SDL_BUTTON_RIGHT
                */
                case SDL_MOUSEBUTTONDOWN:
                    afficher("Clic en %dx/%dy\n", event.button.x, event.button.y);
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(event.button.clicks >= 2)
                            afficher("Double-clic !\n");
                        else
                        afficher("Clic gauche !\n");
                    }
                    if(event.button.button == SDL_BUTTON_MIDDLE)
                        afficher("Clic molette !\n");
                    if(event.button.button == SDL_BUTTON_RIGHT)
                        afficher("Clic droit !\n");

                    break;
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_LEAVE)
                        afficher("La souris est sortie de la fenetre.\n");
                    if(event.window.event == SDL_WINDOWEVENT_ENTER)
                        afficher("La souris est sur la fenetre.\n");
                    break;
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