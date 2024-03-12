#pragma once
#include "define.h"
#include "color.h"

namespace gm {

//I[5][5] JLOSTZ[3][3]
using Tetromino = std::vector<std::vector<int>>;
extern Tetromino I,J,L,O,S,T,Z;
Tetromino rotate(Tetromino &t);
extern std::map<int, Color> tetro_color;

}