#include "../VirtualComputer/ComputerModule/ComputerModules.hpp"
#include "../VirtualComputer/ComputerModule/Computer.hpp"
#include "../VirtualComputer/User/User.hpp"
#include "../VirtualComputer/Utils/Utils.hpp"

#include "Games/HangMan/HangMan.hpp"
#include "GameModule/GameModules.hpp"

using namespace std;
using namespace ComputerModule;
using namespace UserModule;
using namespace Utils;
using namespace HangMan;

#define __init__ public:
#define __endinit__ private:

class Game : public Program {
  __init__
    Game(string title) : Program { title } {
        
    }
    ~Game() {
        
    }
  __endinit__
	
  public:
    void play() {
        println(title() + ": Hello!!!!!!!");
    }
    void exit() {
        println(title() + ": Bye!!!!!!!!!!!!!!!!!!!");
    }
};

class AMDCPU : public CPU {
    
};

class SigeumchiRAM : public RAM {
public:
    SigeumchiRAM(num_t capacity) : RAM { capacity } {
        
    }
};

class SamsungLaptop : public Computer {
    
};

class LGgram : public Computer {
    
};



void test1() {
    show_log = true;
    
    Game game("new game");
	
    Mainboard mb;
    AMDCPU cpu;
    RAM ram;
    RAM* sgcram = new SigeumchiRAM(4);
    Memory m(16);
    m.push(&game);
	
    mb.plugCPU(&cpu);
    mb.plugRAM(sgcram);
    mb.plugMemory(&m);
	
    mb.playProgram("new game");
	
	
    sleep(1000);            //프로그램 종료를 의도적으로 늦춰서 스레드가 다 돌게 하기 위함 ㅇㅇ
    println("test1() End.");
}

void test2() {
    Computer desktop;
    User steve { "steve" };
    steve.setComputer(&desktop);
    steve.turnOnTheComputer();
    steve.computer()->doSomething();
    steve.turnOffTheComputer();
    steve.setComputer(new SamsungLaptop());
    steve.turnOnTheComputer();
    steve.computer()->doSomething();
    steve.turnOffTheComputer();
}

void programInstallTest() {
    User user { "user" };
    SamsungLaptop pc;
    
    user.setComputer(&pc);
    user.turnOnTheComputer();
    
    user.computer()->install(new Game("gggame"));
    user.computer()->install(new Game("gggame"));
    user.computer()->install(new Game("a"));
    user.computer()->install(new Game("b"));
    user.computer()->install(new Game("c"));
    user.computer()->install(new Game("d"));
    user.computer()->install(new Game("e"));
    user.computer()->install(new Game("f"));
    user.computer()->playProgram("gggame");
    user.computer()->playProgram("gggame");
    user.computer()->playProgram("a");
    user.computer()->playProgram("b");
    user.computer()->playProgram("c");
    user.computer()->playProgram("d");
    user.computer()->playProgram("e");
    user.computer()->playProgram("f");
    user.computer()->playProgram("f");
    user.computer()->playProgram("f");

    user.turnOffTheComputer();
}

void hangManTest() {
    User user { "user" };
    LGgram pc;
    
    user.setComputer(&pc);
    user.turnOnTheComputer();
    
    user.computer()->install(new HangManGame());
    user.computer()->playProgram("HangMan");
    
    user.turnOffTheComputer();
}

void CanvasTest() {
    using namespace GameModule;
    
    Canvas c { 40, 10 };
    TxtImage ti { "src/VirtualComputerTest/test.txtimg" };
    println(toString(ti.getWidth()));
    println(toString(ti.getHeight()));
    println(ti.getByString());
    println("\n\n\n");
    
    println("--- Canvas ---");
    c.draw(ti, 5, 5);
    c.draw(ti, 0, 0, false);
    c.draw(ti, 15, 0);
    c.draw(ti, 37, 7, false);
    c.draw(ti, 39, 2);
    c.draw(ti, 26, 9);
    c.draw(ti, -2, 6);
    c.draw(ti, 19, -2);
    c.show();
    
    println("\n\n\n");
    
    TxtImage sample { "src/VirtualComputerTest/TextImageSample.txtimg" };
    println("--- Canvas ---");
    c.draw(sample, 20, 4);
    c.draw("test string hi!", 7, 8);
    c.draw("test string hi!", 7, 9, false);
    c.draw("test string hi!", 35, 6);
    c.draw("test string hi!", -4, 5, false);
    c.draw("test string hi!", 7, 90, false);
    c.draw("Hello World!\nNice to meet you!\n", 20, 1, false);
    c.show();
}

int main() {
    hangManTest();
}