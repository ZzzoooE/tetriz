#pragma once 
#include "tetromino.h"
namespace gm {

extern bool running;
extern int row, col;
extern Tetromino cur;

void init();
void quit();

void rotate();
void left();
void right();
void down();

} 