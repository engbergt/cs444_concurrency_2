#include <cstdlib>
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <mutex>

std::mutex forks[5];

void randomWaitTime(int minSeconds, int maxSeconds){
    int random_num = rand()%(maxSeconds-minSeconds + 1) + minSeconds;
    std::this_thread::sleep_for(std::chrono::seconds(random_num));
}

void eat()
{
    randomWaitTime(2,9);
}

void think()
{
    randomWaitTime(1,20);
}

void getForks(int philosopherNum)
{
    if(philosopherNum == 0)
    {
        forks[1].lock();
        forks[0].lock();
    }
    else
    {
        forks[philosopherNum].lock();
        forks[(philosopherNum + 1)%5].lock();
    }
    std::cout<< "phil " <<philosopherNum << " got a fork." <<std::endl;
}

void putForks(int philosopherNum)
{
    if(philosopherNum == 0) // the 0th philosopher picks the left fork first.
    {
        forks[1].unlock();
        forks[0].unlock();
    }
    else
    {
        forks[philosopherNum].unlock(); // the rest of the philosopher are righties.
        forks[(philosopherNum + 1)%5].unlock();
    }
    std::cout<< "phil " <<philosopherNum << " put a fork" <<std::endl;
}

void dinnerTime(int philosopherNum)
{
    while(true)
    {
        think();
        getForks(philosopherNum);
        eat();
        putForks(philosopherNum);
    }
}

int main(int arc, char **argv)
{
    srand((unsigned)time(0));
    std::cout<< "It's time to eat!" <<std::endl;
    std::cout<< "Type: 'ctrl + c' at anytime to stop dinner." <<std::endl;  

    std::thread lewis (dinnerTime, 0);
    std::thread joe (dinnerTime, 1);
    std::thread bob (dinnerTime, 2);
    std::thread will (dinnerTime, 3);
    std::thread mack (dinnerTime, 4);

    lewis.join();

    // std::cout<< "hello world!" <<std::endl;
    // std::cout<< "all done!" <<std::endl;

}