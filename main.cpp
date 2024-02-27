#include <iostream>
#include "terminal.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main() {
   tc::hide_cursor();

   int i = 1;
   while (true) {
      tc::clean_screen();
      tc::move_to(i ++ , 10);
      tc::set_back_color(15);
      std::cout << "  ";
      std::cout << std::flush;
      tc::reset_color();
      std::this_thread::sleep_for(500ms);
   }
   return 0;
}