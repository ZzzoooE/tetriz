#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"
#include "tetromino.h"

//初始化
void init() {
   tc::hide_cursor();
   gm::init();
   gm::start_listener();
   
}

//游戏主体
void loop() {
   while (gm::running) {
      //显示每一帧的画面
      tc::clean_screen();
      gm::process();
      dw::window(1, 1, 9, 6, "Hold");
      dw::window(1, 10, 12, 22, "Trtriz");
      dw::window(7, 1, 9, 16, "Status");
      dw::window(19, 22, 8, 4, "Info");
      dw::window(1, 22, 8, 18, "Next");
   
      tc::move_to(8, 6);
      std::cout << "FPS:" << ut::fps();

      tc::move_to(10, 6);
      std::cout << "Score:" << gm::score;
      
      tc::move_to(12, 6);
      std::cout << "Level:" << gm::level;

      tc::move_to(14, 6);
      std::cout << "Command:" << gm::command;

     

      dw::frame(gm::frame, 2, 11);
      dw::frame_tetro(gm::one_piece, 4, 5);

      int i = 0;
      for (auto next_piece : gm::next_pieces)        
         dw::frame_tetro(next_piece, ( ++ i) * 3 + 1, 25);
      tc::reset_color();
      std::cout << std::flush;

      std::this_thread::sleep_for(16ms); //每一帧停留在屏幕上的时间
   }
}

//收尾
void exit() {
   tc::show_cursor();
   tc::reset_color();
   tc::clean_screen();
   tc::move_to(1, 1);
   tc::set_fore_color(9);
   puts("Game Over!!");
}

int main() {
   init();
   loop();
   exit();
   return 0;
}