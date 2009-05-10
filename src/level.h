#ifndef LEVEL_H
#define LEVEL_H

//Basic level stuff

//Initializes everything
bool level_init();

//loads the files
bool level_files();

//Starts the level, when it is actually implemented
void level_start();

//Ends the level by freeing the surfaces
void level_end();

#endif
