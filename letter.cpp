//Downwards
//Produced and developed by CTG Empire
//Letter class

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "constants.h"
#include "letter.h"
#include "functions.h"
#include "globals.h"
#include "level.h"

Letter::Letter()
{
    //Set the button's attributes
    box.x = 0;
    box.y = 0;
    box.w = LETTER_WIDTH;
    box.h = LETTER_HEIGHT;
    
    //default sprite for testing
    letter = &letters[LETTER_A];
    
    //Initialize the velocity
    xVel = 0;
    yVel = 2;
}

void Letter::handle_input()
{
    
    //The mouse offsets 
    int x = 0, y = 0; 
    
    //If the mouse is being moved 
    if( event.type == SDL_MOUSEMOTION )
    {
        x = event.motion.x;
        y = event.motion.y;
        
        if (clicked == true)
        { 
            box.x = x;
            box.y = y;
            yVel = 0;
            
            if (event.motion.x > (SCREEN_WIDTH - LETTER_WIDTH))
            {
                //move back
                box.x = SCREEN_WIDTH - LETTER_WIDTH;        
            }
            if (event.motion.y > (SCREEN_HEIGHT - LETTER_HEIGHT))
            {
                //move back
                box.y = SCREEN_HEIGHT - LETTER_HEIGHT;  
            }
        }
    }
    
     //If a mouse button was pressed 
    if( event.type == SDL_MOUSEBUTTONDOWN ) 
    { 
        //If the left mouse button was pressed 
        if( event.button.button == SDL_BUTTON_LEFT ) 
        { 
            //Get the mouse offsets 
            x = event.button.x; 
            y = event.button.y; 
            
            //If the mouse is over the button 
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) ) 
            {   
                clicked = true;
            } 
        } 
    } 
    
    //If a mouse button was released 
    if( event.type == SDL_MOUSEBUTTONUP ) 
    { 
        //If the left mouse button was released 
        if( event.button.button == SDL_BUTTON_LEFT ) 
        { 
            //Get the mouse offsets 
            x = event.button.x; 
            y = event.button.y;
            
            clicked = false;
            yVel = 2;
        }
    } 
    
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= LETTER_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += LETTER_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= LETTER_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += LETTER_WIDTH / 2; break;    
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += LETTER_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= LETTER_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += LETTER_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= LETTER_WIDTH / 2; break;    
        }        
    }
}

void Letter::move()
{
    //Move the letter left or right
    box.x += xVel;
    
    //If the letter went too far to the left or right
    if( ( box.x < 0 ) || ( box.x + LETTER_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        box.x -= xVel;    
    }
    
    //Move the letter up or down
    box.y += yVel;
    
    //If the letter went too far up or down
    if( ( box.y < 0 ) || ( box.y + LETTER_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        box.y -= yVel;  
    }
}

void Letter::show()
{
    //Show the letter
    apply_surface( box.x, box.y, letterSheet, screen, NULL);
}

//Destructor.  Currently not being used.
Letter::~Letter()
{
    SDL_FreeSurface(letterSheet);
}
