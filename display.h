#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <vector>

class Display
{
    private:
        const int height_;
        const int width_;
        std::string *left_;
        int leftn_;
        std::string *right_;
        int rightn_;
    public:
        Display(int height = 20, int width = 10);
        void spack(std::string* left=nullptr, int leftn=0, std::string* right_=nullptr, int rightn_=0);
        void mrflush(std::vector<std::vector<int>> matr);
        void rflush();

};



#endif