#ifndef HangMan_hpp
#define HangMan_hpp

#include "../../GameModule/Game.hpp"
#include "../../../VirtualComputer/Utils/UtilTypes.hpp"

#include <string>

#include "Words/Words.hpp"


namespace HangMan {
    class HangManGame : public GameModule::Game {
        private: const Utils::count_t life_max;
        private: Utils::count_t life;
        private: const GameModule::TxtImage human;
        private: const GameModule::TxtImage* scaffold;
        private: Words words;

    public:
        HangManGame();
        ~HangManGame();

    public:
        void play();
        void exit();

    private:
        char getAlphabet();
        
        Utils::index_t getRandomIndex() const;
    };
}

#endif










/*
인터페이스:


 ~ HangMan ~ 

+---          
|               ANSWER: _ _ _ _ _       
|   o         
|  /|\          WRONG: E T I P Y 
|  / \        
|               Hint: time

[Enter a alphabet]: C



참고로 답은 Clock

사람은 처음부터 서있음, 문제 틀릴때마다 기둥이 세워짐, 마지막에는 목메담
      
     
    o
   /|\
   / \ 
 
 
      
     
    o
   /|\
|  / \ 
|

      
     
|   o
|  /|\
|  / \ 
|

|    
|    
|   o
|  /|\
|  / \ 
|

+-    
|    
|   o
|  /|\
|  / \ 
|

+---  
|    
|   o
|  /|\
|  / \ 
|

+-----
|    
|   o
|  /|\
|  / \ 
|

+---+-
|   |
|   o
|  /|\
|  / \ 
|
*/