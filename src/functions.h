//Downwards
//Produced and developed by CTG Empire
//Header file for various common tasks for handling of graphics. 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

//File Loader, handles the input of files into the program
SDL_Surface *load_image( char* filename );

//Surface blitter, applies the selected surface
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);

//Initialization
bool init();

void set_letters();

//Clean up
void clean_up();

#endif
