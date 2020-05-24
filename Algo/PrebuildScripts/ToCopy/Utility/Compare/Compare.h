#pragma once
#include <iostream>

template<typename T>
bool Compare(const T& val1, const T& val2, bool verbose = true)
{
    if(verbose)
    {
        std::cout<<"val1 : "<<val1<<" val2 : "<<val2<<std::endl;
    }
    
    return val1 == val2;
}

template<typename T>
bool Compare(const std::vector<T>& vec1, const std::vector<T>& vec2, bool verbose = true)
{
    if(vec1.size() != vec2.size())
    {
        if(verbose)
        {
            std::cout<<"vec1 size = "<<vec1.size()<<" vec2 size = "<<vec2.size()<<std::endl;
        }
        return false;
    }
    
    bool result = true;
    for(int i = 0; i < vec1.size(); ++i)
    {
        if(vec1[i] != vec2[i])
        {
            result = false;
        }
        
        if(verbose)
        {
            std::cout<<"vec1 : "<< vec1[i]<<" vec2 : "<<vec2[i]<<std::endl;
        }
        else
        {    
                if(!result)
                    return result;
        }
    }
    
    return result;
}