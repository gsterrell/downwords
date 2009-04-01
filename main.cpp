//Downwards
//Produced and developed by CTG Empire

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "constants.h"
#include "letter.h"
#include "functions.h"
#include "globals.h"
#include "timer.h"

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;
    
    //The dot that will be used
    Letter myLetter(0,0,30,30, false);
    
    //The frame rate regulator
    Timer fps;
    
    //Initialize
    if( init() == false )
    {
        return 1;
    }
    
    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();
        
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the letter
            myLetter.handle_input();
            
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
        
        //Move the letter
        myLetter.move();
        
        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
        
        //Show the letter on the screen
        myLetter.show();
        
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;    
        }
        
        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }
        
    //Clean up
    clean_up();
    
    return 0;    
}
