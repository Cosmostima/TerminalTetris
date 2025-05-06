#include "display.h"

Display::Display(int height, int width):height_(height),width_(width*2)
{
    spack();
}

void Display::mrflush(std::vector<std::vector<int>> matr)
{
    std::string flush_="";
    int ww=0,wh=0,sx=0,sy=0;
    struct winsize win;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&win);
    sx = (int)((win.ws_col-(width_+4))/2);
    sy = (int)((win.ws_row-(height_+1))/2)-1;
    ww = win.ws_col;
    wh = sy+height_+2;

    for (int j = 0; j < wh; j++)
    {
        if (j<leftn_)
        {
            flush_+=left_[j];
            for (int i = 0; i < (sx - left_[j].size()); i++)
            {
                flush_ += " ";
            }
        }
        else
        {
            for (int i = 0; i < sx; i++)
            {
                flush_ += " ";
            }
        }

        if (j <= sy)
        {
            for (int i = 0; i < (width_+4); i++)
            {
                flush_ += " ";
            }
        }
        else if (j == (wh-1))
        {
            flush_ += "<!";
            for (int i = 0; i < width_; i++)
            {
                flush_ += "=";
            }
            flush_ += "!>";
        }
        else
        {
            flush_ += "<!";
            for (int i = 0; i < (int)(width_/2); i++)
            {
                if (matr[j-sy-1][i]==1)
                {
                    flush_ += "[]";
                }
                else
                {
                    flush_ += ". ";
                }
            }
            
            
            flush_ += "!>";
        }
        
        if (j<rightn_)
        {
            for (int i = 0; i < (ww - right_[j].size()); i++)
            {
                flush_ += " ";
            }
            flush_+=right_[j];
        }
        flush_+="\n";
    }
    system("clear");
    std::cout << flush_;
}

void Display::rflush()
{
    std::string flush_="";
    int ww=0,wh=0,sx=0,sy=0;
    struct winsize win;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&win);
    sx = (int)((win.ws_col-(width_+4))/2);
    sy = (int)((win.ws_row-(height_+1))/2)-1;
    ww = win.ws_col;
    wh = sy+height_+2;

    for (int j = 0; j < wh; j++)
    {
        if (j<leftn_)
        {
            flush_+=left_[j];
            for (int i = 0; i < (sx - left_[j].size()); i++)
            {
                flush_ += " ";
            }
        }
        else
        {
            for (int i = 0; i < sx; i++)
            {
                flush_ += " ";
            }
        }

        if (j <= sy)
        {
            for (int i = 0; i < (width_+4); i++)
            {
                flush_ += " ";
            }
        }
        else if (j == (wh-1))
        {
            flush_ += "<!";
            for (int i = 0; i < width_; i++)
            {
                flush_ += "=";
            }
            flush_ += "!>";
        }
        else
        {
            flush_ += "<!";
            for (int i = 0; i < (int)(width_/2); i++)
            {
                flush_+=". ";
            }
            flush_ += "!>";
        }
        
        if (j<rightn_)
        {
            for (int i = 0; i < (ww - right_[j].size()); i++)
            {
                flush_ += " ";
            }
            flush_+=right_[j];
        }
        flush_+="\n";
    }
    system("clear");
    std::cout << flush_;
}

void Display::spack(std::string* left, int leftn, std::string* right, int rightn)
{
    left_ = left;
    leftn_ = leftn;
    right_=right;
    rightn_ = rightn;
}