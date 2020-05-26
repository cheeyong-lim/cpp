#pragma once
#include "../Utility.h"

class Timer
{
public:
    enum TYPE{ALL, SEC, MILLISEC, MICROSEC, NANOSEC};
    explicit Timer(const std::string& msg,  const TYPE timeType = Timer::TYPE::SEC);
    ~Timer();
    void OutputElapsed(const std::chrono::time_point<std::chrono::steady_clock>& timePoint) const;
    void OutputElapsed(const std::chrono::time_point<std::chrono::steady_clock>& timePoint, const TYPE timeType) const;
    
private:
    //variables
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;
    bool done;
    TYPE timerType;
    std::string message;
};