//Downwards
//Produced and developed by CTG Empire
//Header file for various common tasks for handling of graphics. 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

//File Loader, handles the input of files into the program
SDL_Surface *load_image( std::string filename );

//Surface blitter, applies the selected surface
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

//Initialization
bool init();

//File loading
bool load_files();

//Clean up
void clean_up();

void set_clip();

#endif
