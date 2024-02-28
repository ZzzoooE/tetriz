#include <iostream>
#include "terminal.h"
#include "utils.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;



void init() {
   tc::hide_cursor();
}

void loop() {
   int i = 1;
   while (true) {
   
      
      tc::clean_screen();

      tc::move_to(1, 1);
      std::cout << "FPS:" << ut::fps();
      
      tc::move_to(i ++ % 20, 10);
      tc::set_back_color(15);
      std::cout << "  ";
      std::cout << std::flush;
      tc::reset_color();
      std::this_thread::sleep_for(16ms);
   }
}

void exit() {
   tc::show_cursor();
   tc::reset_color();
}

int main() {
   init();
   loop();
   exit();
  
 
   return 0;
}