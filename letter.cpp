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

Letter::Letter(int x, int y, int w, int h, bool click )
{
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    clicked = click;
    
    //Set the default sprite
    clip = &clips;
    
    //Initialize the velocity
    xVel = 0;
    yVel = 1;
}

void Letter::handle_input()
{
    
    //The mouse offsets 
    int x = 0, y = 0; 
    
    //If the mouse is being moved
    //BLAYNE:  This is the one that I have been focusing on the most.  
    if( event.type == SDL_MOUSEMOTION )
    {
        x = event.motion.x;
        y = event.motion.y;
        
        if (clicked == true)
        { 
            box.x = x;
            box.y = y;
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
            
        } 
    } 
    
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= DOT_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += DOT_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= DOT_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += DOT_WIDTH / 2; break;    
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += DOT_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= DOT_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += DOT_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= DOT_WIDTH / 2; break;    
        }        
    }
}

void Letter::move()
{
    //Move the dot left or right
    x += xVel;
    
    //If the dot went too far to the left or right
    if( ( x < 0 ) || ( x + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        x -= xVel;    
    }
    
    //Move the dot up or down
    y += yVel;
    
    //If the dot went too far up or down
    if( ( y < 0 ) || ( y + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        y -= yVel;  
    }
}

void Letter::show()
{
    //Show the dot
    apply_surface( x, y, letter, screen, clip );
}

//Destructor.  Currently not being used.
Letter::~Letter()
{
    SDL_FreeSurface( letter);
}
