#ifndef CLASSES_H
#define CLASSES_H

//The dot that will move around on the screen
class Dot
{
    private:
    //The X and Y offsets of the dot
    int x, y;
    
    //The velocity of the dot
    int xVel, yVel;
    
    public:
    //Initializes the variables
    Dot();
    
    //Takes key presses and adjusts the dot's velocity
    void handle_input();
    
    //Moves the dot
    void move();
    
    //Shows the dot on the screen
    void show();
};

//The timer
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;
    
    //The ticks stored when the timer was paused
    int pausedTicks;
    
    //The timer status
    bool paused;
    bool started;
    
    public:
    //Initializes variables
    Timer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    int get_ticks();
    
    //Checks the status of the timer
    bool is_started();
    bool is_paused();    
};

#endif
