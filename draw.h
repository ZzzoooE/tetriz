#pragma once
#include <string>
// #include "define.h"
#include "tetromino.h"
#include "piece.h"

namespace dw
{
    void window(int top, int left, int width, int height, std::string title);
    int block2col(int b);  
    void frame(Matrix &f, int top, int left);
    void frame_tetro(gm::Piece p, int top, int left);
} // namespace dw
