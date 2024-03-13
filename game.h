#pragma once 
#include "tetromino.h"
#include "piece.h"

namespace gm {

extern int level;
extern int score;
extern bool running;
extern std::list<Piece> next_pieces;
//当前掉落快
extern Piece one_piece;

//游戏场地
extern Matrix playfield;
//每帧时间间隔
extern std::chrono::microseconds duration;
//当前渲染帧
extern Matrix frame;
//游戏主逻辑
void process();
//游戏初始化
void init();
void to_down();

// 渲染当前帧
void render();
//获取下一个方块
Piece pick();
void reset();
// 游戏退出
void quit();

bool clean();
void rotate();
void left();
void right();
void down();

} 