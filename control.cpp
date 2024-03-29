#include "control.h"
#include "define.h"
#include "game.h"

namespace gm {

char command;

std::map<char, std::function<void()>> comm_func {
    {KEY_Q, command_quit},
    {KEY_q, command_quit},
    {KEY_W, command_rotate},
    {KEY_w, command_rotate},
    {KEY_S, command_down},
    {KEY_s, command_down},
    {KEY_A, command_left},
    {KEY_a, command_left},
    {KEY_D, command_right},
    {KEY_d, command_right},
    {KEY_R, command_reset},
    {KEY_r, command_reset},
};

char getch() {
   char c;
   struct termios old, cur;
   tcgetattr(0, &cur);
   old = cur;
   cfmakeraw(&cur);
   tcsetattr(0, 0, &cur);
   c = getchar();
   tcsetattr(0, 0, &old);
   return c;
}

void key_event() {
   while (running) {
      command = getch();
      auto it = comm_func.find(command);
      if (it != comm_func.end()) {
        it->second();
      }
   }
}


void start_listener()
{
   std::thread t(key_event);
   t.detach();
}

void command_reset() {
   reset();
}

void command_quit()
{
    quit();
}

void command_rotate()
{
   rotate();
}

void command_left()
{
   left();
}

void command_right()
{
   right();
}

void command_down()
{
   down();
}
   
}
