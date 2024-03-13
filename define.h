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

const char KEY_Q = 'q';
const char KEY_W = 'w';
const char KEY_S = 's';
const char KEY_A = 'a';
const char KEY_D = 'd';
const char KEY_R = 'r';


