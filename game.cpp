#include "game.h"
#include "tetromino.h"
#include "utils.h"

namespace gm
{
bool running{false};
Piece one_piece;
Matrix playfield;
std::chrono::microseconds duration;
Matrix frame;


void init()
{
    running = true;
    one_piece = pick();
    playfield = Matrix(22, std::vector<int>(10, 0));
    duration = 500ms;
    frame = playfield;
    one_piece.set_playfield(std::make_shared<Matrix>(playfield));
}

void process()
{
    render();
    if (ut::timer(duration)) {
        one_piece.down();
    }
}

void render() {
    frame = playfield;
    auto [x, y] = one_piece.get_xy();
    for (int i = 0; i < 4; i ++ ) {
        auto [dx, dy] = one_piece.get_mino(one_piece.get_index(), i);
        frame[x + dx][y + dy] = (int)one_piece.get_color();
    }
}

Piece pick() {
    return Piece(J, 3, 15, 1);
}

void quit() {
    running = false;
}

void rotate()
{
    one_piece.rotate(); 
}

void left()
{
    one_piece.left();
}

void right()
{
    one_piece.right();
}

void down()
{
    one_piece.down();
}

} // namespace gm

