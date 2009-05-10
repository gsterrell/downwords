//Downwards
//Produced and developed by CTG Empire
//Global variables that will be used throughout the program

#ifndef GLOBALS_H
#define GLOBALS_H

//The header
#include "SDL/SDL.h"

//The surfaces
extern SDL_Surface *letterSheet;
extern SDL_Surface *screen;
extern SDL_Surface *letterspaceSheet;

//Hold the letters
extern SDL_Rect *letter;
extern SDL_Rect letters[];

//Holds the letterspaces
extern SDL_Rect *letterspace;
extern SDL_Rect letterspaceBox;

//Holds the backgrounds
extern SDL_Surface *background1;

//The event structure
extern SDL_Event event;

#endif
