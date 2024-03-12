#include "terminal.h"
#include <iostream>
#include <string>

const std::string CSI = "\033[";

//移动光标  \033[row;colH
void tc::move_to(int row, int col)
{
    std::cout << CSI << row << ';' << col << 'H';
}

//设置前景色 \033[38;5idm
void tc::set_fore_color(int id)
{
     std::cout << CSI << "38;5;" << id << 'm';
}

//设置背景色 \033[48;5idm
void tc::set_back_color(int id)
{
    std::cout << CSI << "48;5;" << id << 'm';
}

//清空屏幕 \033[2J
void tc::clean_screen()
{
    std::cout << CSI << "2J";
}

//重置颜色样式 \033[0m
void tc::reset_color()
{
    std::cout << CSI << "0m";
}

//隐藏光标 \033[?25l
void tc::hide_cursor()
{
    std::cout << CSI << "?25l";
}

//显示光标 \033[?25h
void tc::show_cursor()
{
    std::cout << CSI << "?25h";
}
