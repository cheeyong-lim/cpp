#include "../Utility.h"

Timer::Timer(const std::string& msg, const TYPE timeType) : done(false), message(msg), timerType(timeType)
{
    start = std::chrono::steady_clock::now();
}

Timer::~Timer()
{
    end = std::chrono::steady_clock::now();
    done = true;
    OutputElapsed(end);
}

void Timer::OutputElapsed(const std::chrono::time_point<std::chrono::steady_clock>& timePoint) const
{
    OutputElapsed(timePoint, timerType);
}

void Timer::OutputElapsed(const std::chrono::time_point<std::chrono::steady_clock>& timePoint, const TYPE timeType) const
{
    if(timeType == TYPE::MILLISEC)
    {
        std::chrono::duration<double, std::milli> milliSec = timePoint - start;
        std::cout<<message<<milliSec.count()<<" milliseconds"<<std::endl;
    }
    
    if(timeType == TYPE::MICROSEC)
    {
         std::chrono::duration<double, std::micro> microSec = timePoint - start;
         std::cout<<message<<microSec.count()<<" microseconds"<<std::endl;
    }
    
    if(timeType == TYPE::NANOSEC)
    {
        std::chrono::duration<double, std::nano> nanoSec = timePoint - start;
        std::cout<<message<<nanoSec.count()<<" nanoseconds"<<std::endl;
    }
    
    if(timeType == TYPE::SEC)
    {
        std::chrono::duration<double> sec = timePoint - start;
        std::cout<<message<<sec.count()<<" seconds"<<std::endl;
    }
    
    if(timeType == TYPE::ALL)
    {
        OutputElapsed(timePoint, TYPE::SEC);
        OutputElapsed(timePoint, TYPE::MILLISEC);
        OutputElapsed(timePoint, TYPE::MICROSEC);
        OutputElapsed(timePoint, TYPE::NANOSEC);
    }
}
