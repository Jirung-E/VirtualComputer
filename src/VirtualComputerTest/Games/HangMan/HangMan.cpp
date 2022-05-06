#include "HangMan.hpp"

#include "../../../VirtualComputer/Utils/Utils.hpp"

#include <iostream>
#include <random>

using namespace HangMan;
using namespace std;
using namespace Utils;
using namespace GameModule;


HangManGame::HangManGame() : Game { "HangMan" }, life_max { 7 }, life { 7 }, 
                             human { "src/VirtualComputerTest/Games/HangMan/resource/Human.txtimg" }, 
                             scaffold { new TxtImage[7] { 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(1).txtimg" }, 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(2).txtimg" }, 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(3).txtimg" }, 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(4).txtimg" }, 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(5).txtimg" }, 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(6).txtimg" }, 
                                 { "src/VirtualComputerTest/Games/HangMan/resource/Scaffold(7).txtimg" }, 
                             } },
                             words { } 
{
    words.add("awesome", "???: (this) screen, (this) camera, long lasting battery life!");
    words.add("block", "minecraft!");
    words.add("clock", "time");
    words.add("door", "open the (this) please~");
    words.add("easy", "(this) <-> hard");
    words.add("freedom", "(this) is not free");
    words.add("ground", "fall to the (this)");
    words.add("horizon", "Samsung Galaxy Call Theme");
    words.add("iron", "Fe");
    words.add("jupiter", "largest planet in our solar system.");
    words.add("knock", "hitting a door");
    words.add("loop", "ring");
    words.add("moon", "Jane");
    words.add("nut", "almond, etc..");
    words.add("orange", "sweet, sour, fruit");
    words.add("punch", "hit!");
    words.add("quality", "(this) is better than quantity");
    words.add("request", "draw it for me!");
    words.add("soil", "dirt");
    words.add("table", "desk");
    words.add("utopia", "world of dreams");
    words.add("vector", "force, direction");
    words.add("winter", "cold..");
    words.add("xylitol", "gum");
    words.add("year", "day, month, ");
    words.add("zigzag", "warigari");
}

HangManGame::~HangManGame() {
    
}

void HangManGame::play() {
    canvas.resize(64, 10);
    
    index_t word_idx = getRandomIndex();
    
    string answer = words.answer(word_idx);
    string vanished_answer = "";
    for(int i=0; i<answer.length(); ++i) {
        vanished_answer += "_ ";
    }
    string wrong_alphabets = "";
    string hint = words.hint(word_idx);
    
    canvas.clearTo(' ');
    canvas.draw(" ~ HangMan ~ ", 0, 0, false);
    canvas.draw(human, 3, 4, true);
    canvas.draw("                         ", 15, 1, false);
    canvas.draw("Answer: " + vanished_answer, 16, 3, false);
    canvas.draw("Wrong: " + wrong_alphabets, 16, 5, false);
    canvas.draw("Hint: " + hint, 16, 7, false);
    
    while(true) {        
        // println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("clear");
        
        canvas.show();
        canvas.draw("                         ", 15, 1, false);
        
        char guess = getAlphabet();
        if(!('a' <= guess && guess <= 'z')) {
            canvas.draw("Invalid Value. Try Again.", 15, 1, false);
            continue;
        }
        
        bool is_wrong = true;
        for(int i=0; i<answer.length(); ++i) {
            if(guess == answer.at(i)) {
                is_wrong = false;
                vanished_answer.at(i*2) = guess;
                continue;
            }
        }
        
        if(is_wrong) {
            bool already_wrong = false;
            for(int i=0; i<wrong_alphabets.length(); ++i) {
                if(guess == wrong_alphabets.at(i)) {
                    already_wrong = true;
                    break;
                }
            }
            
            if(already_wrong == false) {
                wrong_alphabets += guess;
                wrong_alphabets += " ";
                canvas.draw("Wrong: " + wrong_alphabets, 16, 5, false);

                life--;
                canvas.draw(scaffold[life_max - (life+1)], 0, 2, true);
                if(life <= 0) {
                    system("clear");
                    canvas.draw("You Dead...", 15, 1, false);
                    canvas.show();
                    break;
                }
            }
        }
        else {
            canvas.draw("Answer: " + vanished_answer, 16, 3, false);
        }
        
        bool clear = true;
        for(int i=0; i<vanished_answer.length(); ++i) {
            if(vanished_answer.at(i) == '_') {
                clear = false;
            }
        }
        
        if(clear) {
            system("clear");
            canvas.draw("Correct!", 15, 1, false);
            canvas.show();
            break;
        }
    }
}

void HangManGame::exit() {
    
}


char HangManGame::getAlphabet() {
    char alphabet;
    
    print("[Enter a alphabet]: ");
    alphabet = cin.get();
    
    string erase_buffer;
    getline(cin, erase_buffer);
    cin.clear();
    
    // to lower
    if('A' <= alphabet && alphabet <= 'Z') {
        alphabet += 'a'-'A';
    }
    
    return alphabet;
}


index_t HangManGame::getRandomIndex() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, words.numOfWords()-1);
    
    return dis(gen);
}