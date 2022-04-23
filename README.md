# Virtual Computer

mkdir -p /workspace/VirtualComputer/obj/
g++ -c $(find /workspace/VirtualComputer/src/VirtualComputer/ -name *.cpp -o -name *.c) -o /workspace/VirtualComputer/obj/sample.o -g -std=c++17 -pthread -lm && /workspace/VirtualComputer/bin//main