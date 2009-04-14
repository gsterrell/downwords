//Downwards
//Produced and developed by CTG Empire
//Global variables that will be used throughout the program

//The headers
#include "SDL/SDL.h"
#include "globals.h"

//The surfaces
SDL_Surface *letterSheet = NULL;
SDL_Surface *screen = NULL;
//Holds the letters
SDL_Rect *letter = NULL;
SDL_Rect letters[ 26 ];

//Holds the backgrounds
SDL_Surface *background1 = NULL;

//The event structure
SDL_Event event;
