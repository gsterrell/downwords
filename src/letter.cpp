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
    letterBox.x = 0;
    letterBox.y = 0;
    letterBox.w = LETTER_WIDTH;
    letterBox.h = LETTER_HEIGHT;
    
    //default sprite for testing
    letter = &letters[A];
    
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
            letterBox.x = x;
            letterBox.y = y;
            yVel = 0;
            
            if (event.motion.x > (SCREEN_WIDTH - LETTER_WIDTH))
            {
                //move back
                letterBox.x = SCREEN_WIDTH - LETTER_WIDTH;        
            }
            if (event.motion.y > (SCREEN_HEIGHT - LETTER_HEIGHT))
            {
                //move back
                letterBox.y = SCREEN_HEIGHT - LETTER_HEIGHT;  
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
            if( ( x > letterBox.x ) && ( x < letterBox.x + letterBox.w ) && ( y > letterBox.y ) && ( y < letterBox.y + letterBox.h ) ) 
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
        
        //If the mouse is over the button 
        if( ( letterBox.x > letterspaceBox.x ) && ( letterBox.x < letterspaceBox.x + letterspaceBox.w ) && ( letterBox.y > letterspaceBox.y ) && ( letterBox.y < letterspaceBox.y + letterspaceBox.h ) ) 
        {   
            letterBox.x = (letterspaceBox.x - 10);
            letterBox.y = (letterspaceBox.y - 10);
            yVel = 0;
        }
        //If the letter is over a letterspace, cover the letterspace.
        //This will handled by the "Sprite" class in the near future.
        if( ( letterBox.x < letterspaceBox.x ) && ( letterBox.x + letterBox.w > letterspaceBox.x ) && ( letterBox.y < letterspaceBox.y ) && ( letterBox.y + letterBox.h > letterspaceBox.y ))
        {   
            //Cover the letterspace with the letter
            letterBox.x = (letterspaceBox.x - 10);
            letterBox.y = (letterspaceBox.y - 10);
            yVel = 0;
        }
    }
    
    //This will be replaced later when letterspace & letter classes are 
    //as we wish.
    /*
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
    */
}

void Letter::move()
{
    //Move the letter left or right
    letterBox.x += xVel;
    
    //If the letter went too far to the left or right
    if( ( letterBox.x < 0 ) || ( letterBox.x + LETTER_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        letterBox.x -= xVel;    
    }
    
    //Move the letter up or down
    letterBox.y += yVel;
    
    //If the letter went too far up or down
    if( ( letterBox.y < 0 ) || ( letterBox.y + LETTER_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        letterBox.y -= yVel;  
    }
}

//Shows the letter
void Letter::show()
{
    //Show the letter
    apply_surface( letterBox.x, letterBox.y, letterSheet, screen, NULL);
}

//Destructor.  Currently not being used.
Letter::~Letter()
{
    SDL_FreeSurface(letterSheet);
}
