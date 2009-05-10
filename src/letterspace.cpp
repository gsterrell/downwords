#include "letterspace.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "constants.h"
#include "functions.h"
#include "globals.h"
#include "level.h"

Letterspace::Letterspace(int x, int y)
{
    //Set the letterspace's attributes
    letterspaceBox.x = x;
    letterspaceBox.y = y;
    letterspaceBox.w = 20;
    letterspaceBox.h = 20;
}

//shows the letter space
void Letterspace::show() 
{
    //Show the letter space
    apply_surface( letterspaceBox.x, letterspaceBox.y, letterspaceSheet, screen, NULL);
}

//Destructor.  Currently not being used.
Letterspace::~Letterspace()   
{
    SDL_FreeSurface(letterspaceSheet);    
}
