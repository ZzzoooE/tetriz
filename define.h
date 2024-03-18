#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <map>
#include <functional>
#include <vector>
#include <termios.h>
#include <memory>
#include <cassert>
#include <random>
#include <list>

using Tetromino = std::array<std::array<std::pair<int, int>, 3>, 4>;
using namespace std::chrono_literals;
using Matrix = std::vector<std::vector<int>>;;

const char KEY_Q = 'Q';
const char KEY_W = 'W';
const char KEY_S = 'S';
const char KEY_A = 'A';
const char KEY_D = 'D';
const char KEY_R = 'R';
const char KEY_q = 'Q';
const char KEY_w = 'w';
const char KEY_s = 's';
const char KEY_a = 'a';
const char KEY_d = 'd';
const char KEY_r = 'r';


