#include "game.h"
#include "tetromino.h"
#include "utils.h"
#include "terminal.h"

namespace gm
{
bool running{false};
Piece one_piece;
std::list<Piece> next_pieces;
Matrix playfield;
std::chrono::microseconds duration;
Matrix frame;
int score{0}, level{0};

void init()
{
    level = 0;
    score = 0;
    running = true;
    one_piece = pick();
    while (next_pieces.size()) next_pieces.pop_back();
    for (int i = 0; i < 5; i ++ ) {
        next_pieces.emplace_back(pick());
    }
    playfield = Matrix(22, std::vector<int>(10, 0));
    duration = 500ms;
    frame = playfield;
}

bool clean() {
    for (int i = 18; i >= 2; i -- ) {
        int cnt = 0;
        for (int j = 11; j <= 21; j ++ ) {
            cnt += playfield[i][j] > 0;
        }
        if (cnt == 10) {
            for (int row = i; row >= 2; row -- ) {
                for (int j = 11; j <= 21; j ++ ) {
                    playfield[row][j] = playfield[row - 1][j];
                }
            }
            score += 10;
            if (score % 50 == 0) {
                level ++ ;
                duration -= 50ms;
                if (duration < 100ms) duration = 100ms;
            }
            return true;
        }   
    }
    return false;
}

void to_down() {
    auto [x, y] = one_piece.get_xy();
    for (int i = 0; i < 4; i ++ ) {
        auto [dx, dy] = one_piece.get_mino(one_piece.get_index(), i);
        if (playfield[x + dx][y + dy] == 0) {
            playfield[x + dx][y + dy] = (int)one_piece.get_color();
        } else {
            running = false;
        }
    }
    while (clean());
    one_piece = next_pieces.front();
    next_pieces.pop_front();
    next_pieces.emplace_back(pick());
}


void process()
{
    render();
    if (ut::timer(duration)) {
        down();
    } 
}



//把当前块的颜色渲染到帧上
void render() {
    frame = playfield;
    auto [x, y] = one_piece.get_xy();
    for (int i = 0; i < 4; i ++ ) {
        auto [dx, dy] = one_piece.get_mino(one_piece.get_index(), i);
        frame[x + dx][y + dy] = (int)one_piece.get_color();
    }
}

Piece pick() {
    std::mt19937 gen(time(NULL) + clock());
    int type = gen() % 7;
    //I,J,L,O,S,T,Z
    switch (type)
    {
    case 0:
        return Piece(I, 2, 15, 0);
    case 1:
        return Piece(J, 2, 15, 0);
    case 2:
        return Piece(L, 2, 15, 0);
    case 3:
        return Piece(O, 2, 15, 0);        
    case 4:
        return Piece(S, 2, 15, 0);
    case 5: 
        return Piece(T, 2, 15, 0);
    case 6:
        return Piece(Z, 2, 15, 0);
    default:
        break;
 
    }
    return Piece(J, 2, 15, 1);
    
}

void reset() {
    init();
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
    if (!one_piece.down()) {
        to_down();
    };
}

} // namespace gm

