#include "Tetris.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

TETRIS::TETRIS(int height, int width) : height_(height), width_(width), disp(height, width), bls(), mainm(height, std::vector<int>(width)), score(0), line(0), isend(false)
{
    welcome();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mainm[i][j] = 0;
        }
    }
    left_ = new std::string[3];
    left_[0] = "Welcome to Tetris!";
    left_[1] = "";
    left_[2] = "";
    disp.spack(left_, 1);
    disp.rflush();
}

void TETRIS::welcome()
{
    using std::cout;
    using std::endl;
    int wx = 0, wy = 0;
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    wx = (int)((win.ws_col - 45) / 2);
    wy = (int)((win.ws_row - 7) / 2 - 1);
    system("clear");
    for (int i = 0; i < wy; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "WELCOME TO" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "████████╗███████╗████████╗██████╗ ██╗███████╗" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ██║   █████╗     ██║   ██████╔╝██║███████╗" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ██║   ██╔══╝     ██║   ██╔══██╗██║╚════██║" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ██║   ███████╗   ██║   ██║  ██║██║███████║" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("clear");
}

std::vector<std::vector<int>> TETRIS::mixmatix(int blx, int bly, std::vector<int> nebl) noexcept(false)
{
    int width_ = 10;
    std::vector<std::vector<int>> vect = mainm;
    if (bly == height_)
    {
        throw(1);
    }
    

    if (bly < 3)
    {
        if (blx > (width_ - 4))
        {
            for (int y = 0; y <= bly; y++)
            {
                for (int x = blx; x < width_; x++)
                {
                    if (nebl[(4 - (bly - y + 1)) * 4 + x - blx] == 1)
                    {
                        if (mainm[y][x] == 1)
                        {
                            throw(1);
                        }
                        else
                        {
                            vect[y][x] = 1;
                        }
                    }
                }
            }
        }
        else
        {
            for (int y = 0; y <= bly; y++)
            {
                for (int x = blx; x <= blx + 3; x++)
                {
                    if (nebl[(4 - (bly - y + 1)) * 4 + x - blx] == 1)
                    {
                        if (mainm[y][x] == 1)
                        {
                            throw(1);
                        }
                        else
                        {
                            vect[y][x] = 1;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (blx > (width_ - 4))
        {
            for (int y = (bly - 3); y <= bly; y++)
            {
                for (int x = blx; x < width_; x++)
                {
                    if (nebl[(4 - (bly - y + 1)) * 4 + x - blx] == 1)
                    {
                        if (mainm[y][x] == 1)
                        {
                            throw(1);
                        }
                        else
                        {
                            vect[y][x] = 1;
                        }
                    }
                }
            }
        }
        else
        {
            for (int y = (bly - 3); y <= bly; y++)
            {
                for (int x = blx; x <= blx + 3; x++)
                {
                    if (nebl[(4 - (bly - y + 1)) * 4 + x - blx] == 1)
                    {
                        if (mainm[y][x] == 1)
                        {
                            throw(1);
                        }
                        else
                        {
                            vect[y][x] = 1;
                        }
                    }
                }
            }
        }
    }
    return vect;
}

void TETRIS::check()
{
    std::vector<int> needrm;
    std::vector<int> zero(width_);
    for (int i = 0; i < width_; i++)
    {
        zero[i] = 0;
    }

    int lineadd = 0;
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            lineadd += mainm[y][x];
        }
        if (lineadd == width_)
        {
            needrm.push_back(y);
        }
        lineadd = 0;
    }

    for (int i = 0; i < needrm.size(); i++)
    {
        mainm.erase(mainm.begin() + needrm[i]);
        line++;
        mainm.insert(mainm.begin(), zero);
    }

    for (int x = 0; x < width_; x++)
    {
        lineadd += mainm[0][x];
    }

    if (lineadd == 0)
    {
        score += 4;
    }
    else if (lineadd > (width_ - 4))
    {
        isend = true;
    }
    else
    {
        lineadd = 0;
        for (int i = 0; i < width_; i++)
        {
            if (mainm[0][i] == 1)
            {
                lineadd++;
            }
            else
            {
                lineadd = 0;
            }
            if (lineadd == 4)
            {
                score += 4;
            }
        }
    }
}

bool TETRIS::kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

int TETRIS::getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void TETRIS::run()
{
    int dis;
    struct winsize win;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&win);
    dis = win.ws_col*win.ws_row;
    int newbx = 0, newby = 0;
    std::vector<int> nowbv(17);
    std::vector<std::vector<int>> prevm(height_, std::vector<int>(width_));
    prevm = mainm;
    BLOCK::Block *newbloc;
    while (!isend)
    {
        newbx = 0, newby = 0;
        newbloc = &bls.get();
        nowbv = newbloc->get();
        std::srand(std::time(0));
        newbx = rand()%(width_-nowbv[16]+1);
        try
        {
            prevm = mixmatix(newbx, newby, nowbv);
        }
        catch (int a)
        {
            mainm = prevm;
        }
        disp.mrflush(prevm);
        while (true)
        {
            if (kbhit())
            {
                switch (getch())
                {
                    case 'w':
                        nowbv = newbloc->operator++();
                        break;
                    case 's':
                        newby++;
                        break;
                    case 'a':
                        newbx = (newbx == 0) ? newbx : (newbx - 1);
                        break;
                    case 'd':
                        newbx = (newbx == (width_ - nowbv[16])) ? newbx : (newbx + 1);
                        break;
                    case 'c':
                        isend=true;
                        return;
                        break;
                    default:
                        break;
                }

                try
                {
                    prevm = mixmatix(newbx, newby, nowbv);
                    disp.mrflush(prevm);
                }
                catch (int a)
                {
                    mainm = prevm;
                    break;
                }
            }
            else
            {
                    ioctl(STDOUT_FILENO,TIOCGWINSZ,&win);
                    if(dis != win.ws_col*win.ws_row)
                    {
                        disp.mrflush(prevm);
                    }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if (newby < nowbv[17])
        {
            isend = true;
        }
        else
        {
            check();

            if (score != 0)
            {
                left_[1] = "Score: " + std::to_string(score);
                disp.spack(left_, 2);
                if (line != 0)
                {
                    left_[2] = "Eliminated Rows: " + std::to_string(line);
                    disp.spack(left_, 3);
                }
            }
        }
    }
}

TETRIS::~TETRIS()
{
    using std::cout;
    using std::endl;
    int wx = 0, wy = 0;
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    wx = (int)((win.ws_col - 45) / 2);
    wy = (int)((win.ws_row - 9) / 2 - 1);
    system("clear");
    for (int i = 0; i < wy; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "Game ended." << endl;
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "Your score: " << score << endl;
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "Eliminated Rows: " << line << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "████████╗███████╗████████╗██████╗ ██╗███████╗" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ██║   █████╗     ██║   ██████╔╝██║███████╗" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ██║   ██╔══╝     ██║   ██╔══██╗██║╚════██║" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ██║   ███████╗   ██║   ██║  ██║██║███████║" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (int i = 0; i < wx; i++)
    {
        cout << " ";
    }
    cout << "   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝" << endl;
    delete[] left_;
}