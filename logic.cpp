#include "logic.h"

namespace BLOCK
{
    Block::Block(std::string seed):main(4,std::vector<int>(18)),now(0)
    {
        for (int s = 0; s < 4; s++)
        {
            for (int i = 0; i < 18; i++)
            {
                main[s][i]=(int)(seed[18*s+i]-'0');
            }
        }    
    }

    std::vector<int> & Block::get()
    {
        int randomNumber = 0;
        std::srand(std::time(0)+now*100000);
        randomNumber = rand()%4;
        if (now == randomNumber)
        {
            std::srand(std::time(0)+212131);
            randomNumber = rand()%4;
        }
        now = randomNumber;
        return main[now];
    }

    std::vector<int> & Block::operator++()
    {
        now = (now + 1)%4;
        return main[now];
    }

    std::vector<int> & Block::operator--()
    {
        now = (now - 1)%4;
        now = (now >= 0)?now:-now;
        return main[now];
    }


    /*
        class BLOCKS
    {
        public:
            std::vector<Block> store;
            BLOCKS();
            std::vector<int> & get();
    };
    */

    BLOCKS::BLOCKS():seed(1212212)
    {
        using std::string;
        string BlueRicky = "000000001000111032000011001000100023000000001110001032000001000100110023";
        store.emplace_back(BlueRicky);
        string OrangeRicky = "000000000010111032000010001000110023000000001110100032000011000100010023";
        store.emplace_back(OrangeRicky);
        string Smashboy = "000000001100110022000000001100110022000000001100110022000000001100110022";
        store.emplace_back(Smashboy);
        string Hero = "000000000000111141100010001000100014000000000000111141100010001000100014";
        store.emplace_back(Hero);
        string Teewee = "000000000100111032000010001100100023000000001110010032000001001100010023";
        store.emplace_back(Teewee);
        string ClevelandZ = "000000001100011032000001001100100023000000001100011032000001001100100023";
        store.emplace_back(ClevelandZ);
        string RhodeIslandZ = "000000000110110032000010001100010023000000000110110032000010001100010023";
        store.emplace_back(RhodeIslandZ);
    }
    Block & BLOCKS::get()
    {
        int randomNumber = 0;
        std::srand(std::time(nullptr)+seed);
        randomNumber = rand();
        seed = randomNumber;
        std::srand(randomNumber%7+seed);
        randomNumber = rand();
        return store[randomNumber%7];
    }

}