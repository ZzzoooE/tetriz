#pragma once
#include "tetromino.h"

namespace gm
{

class Piece {
public:
    Piece() = default;
    Piece(Tetromino &_tetro_set, int _x, int _y, int _index);
    bool down();
    void left();
    void right();
    void rotate();
    // void set_playfield(std::shared_ptr<Matrix> _sp_playfield);
    std::pair<int, int> get_xy();
    std::pair<int, int> get_mino(int idx, int i);
    Color get_color();
    int get_index();
    bool test(int ox, int oy, int idx);
    Tetromino get_tetro();
private:
    bool move(int dx, int dy);
    Tetromino tetro_set;
    int x, y;
    int index; //[0 R 2 L]
    Color color;
    bool is_down;
};






} // namespace pc
