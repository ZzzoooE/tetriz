#include "utils.h"
#include "define.h"


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

bool timer(std::chrono::microseconds sec)
{
    static auto start = std::chrono::steady_clock::now(); 
    auto end = std::chrono::steady_clock::now();
    if (end - start > sec) {
        start = end;
        return true;
    }
    return false;
}

}
