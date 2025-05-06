#ifndef _LOGIC_H_
#define _LOGIC_H_
#include "display.h"
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>



namespace BLOCK
{   
    class Block
    {
        public:
            std::vector<std::vector<int>> main;
            int now;
            Block(std::string seed);
            std::vector<int> & get();
            std::vector<int> & operator++();
            std::vector<int> & operator--();
    };
    
    class BLOCKS
    {
        public:
            std::vector<Block> store;
            int seed;
            BLOCKS();
            Block & get();
    };
}





#endif