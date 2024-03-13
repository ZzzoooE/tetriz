#pragma once 
#include "tetromino.h"
#include "piece.h"

namespace gm {

extern bool running;
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
//渲染当前帧
void render();
//获取下一个方块
Piece pick();
//游戏退出
void quit();


void rotate();
void left();
void right();
void down();

} 