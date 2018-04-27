#include <cstdlib>
#include <iostream>
#include <thread>

int forks [5]; // Array of mutexes.
char **philosphers [5]; // Array of strings, philosopher names.

int eat()
{
    srand((unsigned)time(0)); 
    int random_num;
    random_num = (rand()%10)+2;
    return random_num;
    // sleep(random_num);
}

void think()
{
    srand((unsigned)time(0)); 
    int random_num;
    random_num = (rand()%21)+1;
    // sleep(random_num);
}

void dinnerTime()
{
    while(true)
    {
        think();
        // getForks();
        eat();
        // putForks();
    }
}

int main(int arc, char **argv)
{
    std::cout<< "hello world!" <<std::endl;

    int answer = eat();

    std::stringstream sstm;
    sstm << "Answer: " << answer;
    result = sstm.str();

    return 0;
}