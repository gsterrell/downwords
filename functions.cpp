//Downwards
//Produced and developed by CTG Empire

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "constants.h"
#include "functions.h"
#include "globals.h"

SDL_Surface *load_image( char* filename ) 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename);
    
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

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
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
    if ( SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        exit(1);
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
    //Load the letter image
    letterSheet = load_image( "a.png" );
    
    //If there was a problem in loading the dot
    if( letterSheet == NULL )
    {
        return false;    
    }
    
    //If everything loaded fine
    return true;
}

void set_letters()
{
    letters[LETTER_A].x = 0;
    letters[LETTER_A].y = 0;
    letters[LETTER_A].w = LETTER_WIDTH;
    letters[LETTER_A].h = LETTER_HEIGHT;
        
    letters[LETTER_B].x = 5;
    letters[LETTER_B].y = 5;
    letters[LETTER_B].w = LETTER_WIDTH;
    letters[LETTER_B].h = LETTER_HEIGHT;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( letterSheet );
    
    //Quit SDL
    SDL_Quit();
}
