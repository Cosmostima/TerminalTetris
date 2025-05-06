#ifndef _TETRIS_H_
#define _TETRIS_H_

#include "display.h"
#include "logic.h"
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <stdlib.h>


class TETRIS
{
    protected:
        const int height_;
        const int width_;
        Display disp;
        BLOCK::BLOCKS bls;
        std::vector<std::vector<int>> mainm;
        int score;
        int line;
        bool isend;
        std::string * left_;
        void welcome();
    public:
        TETRIS(int height=20, int width=10);
        ~TETRIS();
        bool kbhit();
        int getch();
        void check();
        std::vector<std::vector<int>> mixmatix(int blx, int bly, std::vector<int> nebl) noexcept(false);
        void run();
};







#endif