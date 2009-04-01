//Downwards
//Produced and developed by CTG Empire

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "constants.h"
#include "functions.h"
#include "globals.h"

SDL_Surface *load_image( std::string filename ) 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old surface
        SDL_FreeSurface( loadedImage );
        
        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
    
    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;
    
    //Get offsets
    offset.x = x;
    offset.y = y;
    
    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was in error in setting up the screen
    if( screen == NULL )
    {
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Downwards", NULL );
    
    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the dot image
    letter = load_image( "a.png" );
    
    //If there was a problem in loading the dot
    if( letter == NULL )
    {
        return false;    
    }
    
    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( letter );
    
    //Quit SDL
    SDL_Quit();
}

void set_clips()
{
    //Clip the sprite sheet
    clips.x = 0;
    clips.y = 0;
    clips.w = 30;
    clips.h = 30;
}
