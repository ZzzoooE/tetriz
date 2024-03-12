#include "utils.h"
#include "define.h"

using namespace std::chrono_literals;

namespace ut {
int fps() //计算帧率
{
    static auto start = std::chrono::steady_clock::now(); //当前系统时间
    static int frame_count = 0;
    static int fps = 0;
    auto end = std::chrono::steady_clock::now();
    frame_count ++ ;
    if (end - start > 1s) {
        fps = frame_count;

        frame_count = 0;
        start = end;
    }
    return fps;
}

int b2c(int b) {
    return b * 2 - 1;
}

}
