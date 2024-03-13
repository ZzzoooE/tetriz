#include "draw.h"
#include "terminal.h"
#include <iostream>
#include <cassert>
#include "utils.h"

/*
 	    0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
 */


namespace dw {

//用两个输出字符表示布局的一块像素格,所以第k格的起始坐标应该是2k-1 
inline int block2col(int b) {
    return b * 2 - 1;
}

void frame(Matrix &f, int top, int left)
{
    int row, col;
    for (int x = 0; x < 20; x ++ ) {
        for (int y = 0; y < 10; y ++ ) {
            tc::move_to(x + top, block2col(y + left));
            if (f[x][y] > 0) {
                tc::reset_color();
                tc::set_back_color(f[x][y]);
                std::cout << "  ";
            } else {
                tc::reset_color();
                std::cout << "\u30FB";
            }
        }
    }
}

// void tetromino(const gm::Piece &p)
// {
//    int color = (int)gm::tetro_color[t];
//    assert(color != 0);
//    tc::set_back_color(color);

//    tc::move_to(top, block2col(left));
//    std::cout << "  ";

//    for (auto p: t[idx]) {
//        int x = p.first + top;
//        int y = block2col(p.second + left);
//        tc::move_to(x, y);
//        std::cout << "  ";
//    }

// }

//绘制如下窗口 (top,left)为左上角坐标,width,height对应其宽度,高度,第一行中间居中显示标题    
/*
┌──────title───────┐
│                  │
│                  │
│                  │
│                  │
└──────────────────┘
*/
void window(int top, int left, int width, int height, std::string title)
{
    width -= 2;  //每一行的首尾字符都是特殊的 中间的字符都是一样的，特殊处理收尾的字符，中间用循环处理 
    height -= 2;  //首位两行特殊处理 中间行使用循环
    assert(width >= 0 && height >= 0);

    //第一行
    tc::move_to(top, block2col(left));
    std::string s = " ┌";
    for (int i = 0; i < width; i ++ ) {
        s += "──";
    }
    s += "┐ ";
    std::cout << s;
    //在第一行中间居中输出title
    tc::move_to(top, block2col(left) + ((width + 2) * 2 - title.length()) / 2);
    std::cout << title;

   //中间行循环处理
    s = " │";
    for (int i = 0; i < width; i ++ ) s += "  ";
    s += "│ ";
    for (int row = 0; row < height; row ++ ) {
            tc::move_to( ++ top, block2col(left));
            std::cout << s;
    }
   
   //最后一行
    tc::move_to( ++ top, block2col(left));
    s = " └";
    for (int i = 0; i < width; i ++ ) {
        s += "──";
    }
    s += "┘ ";
    std::cout << s;
}

}
