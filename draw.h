#pragma once
#include <string>
#include "define.h"
#include "tetromino.h"

/**
 * @brief 程序运行层次
 *  ui:layout
 *  dw:draw      gm:game logic  ut:utils
 *  tc:terminal control
 * 
 */

namespace dw
{
    void window(int top, int left, int width, int height, std::string title);
    int block2col(int b);  
    // void tetromino(const gm::Piece &p);
    void frame(Matrix &f, int top, int left);
} // namespace dw
