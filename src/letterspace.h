#ifndef LETTERSPACE_H
#define LETTERSPACE_H

//Letterspace class.  Similar to the Letter class, but currently not
//inheriting from said class.  Doesn't do much itself, but is used heavily
//by other parts of the program.

//The letterspace that sits on the screen
class Letterspace
{
    private:
    //The X and Y offsets of the letterspace
    int x, y, w, h;
    
    public:
    //Constructor
    Letterspace(int, int);

    //Show the letterspace on the screen
    void show(); 

    //Destructor
    ~Letterspace();
};
#endif
