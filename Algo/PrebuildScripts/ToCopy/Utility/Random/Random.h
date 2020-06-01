#pragma once
#include "../Utility.h"

class RandomIntGenerator
{
public:
    explicit RandomIntGenerator(int min, int max) : u(min, max)
    {
        e.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }
    
    int GetRandom()
    {
        return u(e);
    }
    
private:
    std::default_random_engine e;
    std::uniform_int_distribution<int> u;
};

class RandomRealGenerator
{
public:
    explicit RandomRealGenerator(double min, double max) : u(min, max)
    {
        e.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }
    
    double GetRandom()
    {
        return u(e);
    }
    
    float GetRandomFloat()
    {
        return static_cast<float>(GetRandom());
    }
private:
    std::default_random_engine e;
    std::uniform_real_distribution<double> u;
};

template<typename T>
void ScrambleVector(std::vector<T>& vec)
{
    int times = vec.size() < 100 ? 100 : vec.size();
    RandomIntGenerator generator(0, vec.size() - 1);
    for(int i  = 0; i < times; ++i)
    {
        int index = generator.GetRandom();
        int index2 = generator.GetRandom();
        std::swap(vec[index], vec[index2]);
    }
}

template<typename T>
std::vector<T> GetScrambleVector(const std::vector<T>& vec)
{
    std::vector<T> v(vec);
    ScrambleVector(v);
    return v;
}