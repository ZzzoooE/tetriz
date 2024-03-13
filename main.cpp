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
   int i = 1;

   while (gm::running) {
      //显示每一帧的画面
      gm::process();
      tc::clean_screen();
      dw::window(1, 1, 9, 6, "Hold");
      dw::window(1, 10, 12, 22, "Trtriz");
      dw::window(7, 1, 9, 16, "Status");
      dw::window(19, 22, 8, 4, "Info");
      dw::window(1, 22, 8, 18, "Next");
   
      tc::move_to(10, 4);
      std::cout << "FPS:" << ut::fps();
      
      dw::frame(gm::frame, 2, 11);
      
      tc::reset_color(); //重置颜色样式

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
   puts("Bye!");
}

int main() {
   init();
   loop();
   exit();
   return 0;
}