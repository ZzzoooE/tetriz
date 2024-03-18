#include "piece.h"
#include "define.h"
#include "game.h"
namespace gm
{

Piece::Piece(Tetromino &_tetro_set, int _x, int _y, int _index = 0):
    tetro_set(_tetro_set), x(_x), y(_y), index(_index), color(tetro_color[_tetro_set]) {}


bool Piece::down()
{
   return move(1, 0);
}

void Piece::left()
{
    move(0, -1);
}

void Piece::right()
{
    move(0, 1);
}

void Piece::rotate()
{
    int ne_idx = (index + 1) % 4;
    if (test(x, y, ne_idx)) {
        index = ne_idx;
    }
}

std::pair<int, int> Piece::get_xy()
{
    return std::pair<int, int>(x, y);
}

std::pair<int, int> Piece::get_mino(int idx, int i)
{
    assert(i >= 0 && i <= 3);
    if (i == 3) return {0, 0};
    return tetro_set[idx][i];
}

Color Piece::get_color()
{
    return color;
}

int Piece::get_index()
{
    return index;
}

//判断当前piece是否可以用idx的旋转姿势以中心点为(ox, oy)存在
bool Piece::test(int ox, int oy, int idx)
{
    for (int i = 0; i <= 3; i ++ ) {
        auto [dx, dy] = get_mino(idx, i); //拓展坐标
        dx += ox, dy += oy;
        if (dx > 18 || dy < 12 || dy > 21) {
            return false;
        } 
        
        if (playfield[dx][dy] > 0) {
            return false;
        }
    }
    return true;
}

Tetromino Piece::get_tetro()
{
    return tetro_set;
}

//判断当前块能否不变样式的移动，如果可以，移动后的快应该可以存在
bool Piece::move(int dx, int dy)
{
    if (test(x + dx, y + dy, index)) {
        x += dx;
        y += dy;
        return true;
    }
    return false;
}
} // namespace gm
