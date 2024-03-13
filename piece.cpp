#include "piece.h"
#include "define.h"

namespace gm
{

Piece::Piece(Tetromino &_tetro_set, int _index, int _x, int _y):
    tetro_set(_tetro_set), x(_x), y(_y), index(_index), sp_playfield(nullptr), color(tetro_color[_tetro_set]) {}



void Piece::down()
{
    if (test(x, y - 1)) {
        y -- ;
    }
}
void Piece::set_playfield(std::shared_ptr<Matrix> _sp_playfield)
{
    sp_playfield = _sp_playfield;;
}

std::pair<int, int> Piece::get_xy()
{
    return std::pair<int, int>(x, y);
}

std::pair<int, int> Piece::get_mino(int i)
{
    assert(i >= 0 && i <= 3);
    if (i == 0) return {0, 0};
    return tetro_set[index][i];
}

Color Piece::get_color()
{
    return color;
}

bool Piece::test(int ox, int oy)
{
    assert(sp_playfield!= nullptr);
    for (int i = 0; i < 3; i ++ ) {
        auto [dx, dy] = tetro_set[index][i];
        dx += ox, dy += oy;
        if (dx < 0 || dx > (*sp_playfield).size() - 1 || dy < 0 || dy > (*sp_playfield)[0].size() - 1) {
            return false;
        } 
        if ((*sp_playfield)[dx][dy] > 0) {
            return false;
        }
    }
    return true;
}
} // namespace gm
