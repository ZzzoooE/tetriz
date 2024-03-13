#pragma once
#include "tetromino.h"

namespace gm
{

class Piece {
public:
    Piece() = default;
    Piece(Tetromino &_tetro_set, int _x, int _y, int _index);
    void down();
    void set_playfield(std::shared_ptr<Matrix> _sp_playfield);
    std::pair<int, int> get_xy();
    std::pair<int, int> get_mino(int i);
    Color get_color();
    bool test(int x, int y);
private:
    Tetromino tetro_set;
    int x, y;
    int index; //[0 R 2 L]
    Color color;
    std::shared_ptr<Matrix> sp_playfield;
};






} // namespace pc
