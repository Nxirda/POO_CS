#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <string>

class Timer
{
    private:
    
        //Parameters

        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock> end_time;

    public:

        //Constructor

        Timer();

        //Methods

        void start();
        void stop();
        void print(std::string func_name);
};

#endif