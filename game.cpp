#include "game.h"
#include "tetromino.h"

namespace gm
{
bool running{false};
int row{0}, col{0};
Tetromino cur;

void init() {
    running = true;
    row = 2;
    col = 15;
    cur = I;
}

void quit() {
    running = false;
}

void rotate()
{
    cur = rotate(cur);
}

void left()
{
    col -- ;
}

void right()
{
    col ++ ;
}

void down()
{
    row ++ ;
}

} // namespace gm

