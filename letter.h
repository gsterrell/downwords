//Downwards
//Produced and developed by CTG Empire

#ifndef LETTER_H
#define LETTER_H

//The letter that will move around on the screen
class Letter
{
    private:
    //The X and Y offsets of the letter
    int x, y, w, h;
    
    //The velocity of the letter
    int xVel, yVel;
    
    //The attributes of the letter
    SDL_Rect box;
    
    //The part of the button sprite sheet that will be shown
    SDL_Rect* clip;
    
    bool clicked;
    
    public:
    //Initializes the variables
    Letter(int, int, int, int, bool);
    
    //Takes key presses and adjusts the letter's velocity
    void handle_input();
    
    //Moves the letter
    void move();
    
    //Shows the letter on the screen
    void show();
    
    //Destructor
    ~Letter();
};

#endif
