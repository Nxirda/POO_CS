#include <Timer.h>
#include <iostream>
#include <ctime>

Timer::Timer(){}

void Timer::start() { this->start_time = std::chrono::high_resolution_clock::now(); }

void Timer::stop() { this->end_time = std::chrono::high_resolution_clock::now(); }

void Timer::print(std::string func_name) 
{
    auto micro_s_duration = std::chrono::duration_cast<std::chrono::microseconds> (this->end_time -this->start_time);
    auto ms_duration = std::chrono::duration_cast<std::chrono::milliseconds> (this->end_time -this->start_time);
    auto s_duration = std::chrono::duration_cast<std::chrono::seconds> (this->end_time -this->start_time);
    std::cout << "Elapsed time in function "
              << func_name << " : " 
              << s_duration.count() << "s "
              << (ms_duration.count()) - (s_duration.count()*1000) << "ms "
              << (micro_s_duration.count()) - (ms_duration.count()*1000) << "us \n";
                                                    
}