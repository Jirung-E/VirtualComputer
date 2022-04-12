#include <iostream>
#include <thread>


int main() {
	using namespace std;
	
	thread t1 { []() { for(int i=0; i<100; ++i) { printf("t1: %d\n", i); } } };
	thread t2 { []() { for(int i=0; i<100; ++i) { printf("t2: %d\n", i); } } };
	
	t1.join();
	t2.join();
}