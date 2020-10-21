#include <thread>
#include <mutex>
#include <string>
#include <iostream>

std::mutex threadlock;

void threadPrint(std::string msg) {
    //Lock the thread and print things.
    //Since it is locked, the first thread should fully finish before the other one starts.
    //This is just an exercise to demonstrate.
    threadlock.lock();
    std::cout << msg << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
    threadlock.unlock();
}

int main() {
    std::thread t1(threadPrint, "Thread 1");
    std::thread t2(threadPrint, "Thread 2");
    t1.join();
    t2.join();
    std::cout << "We're done!";
    return 0;
}