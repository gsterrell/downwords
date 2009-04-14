#include "constants.h"
//#include "letter.h"
#include "functions.h"
#include "globals.h"
#include "timer.h"
#include "level.h"

bool level_init()
{
    //bool load_files()
//{
    //Load the letter image
    letterSheet = load_image( "a.png" );
    
    background1 = load_image( "background.png" );
    
    //If there was a problem in loading the letter
    if( letterSheet == NULL )
    {
        return false;    
    }
    
    if( background1 == NULL )
    {
        return false;    
    }
    
    //If everything loaded fine
    return true;
//}    
}

bool level_files()
{
    apply_surface(0, 0, background1, screen, NULL );
}

void level_end()
{
    //Free the surface
    SDL_FreeSurface( letterSheet ); 
    SDL_FreeSurface( background1 );       
}
