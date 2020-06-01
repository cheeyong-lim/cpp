#include "../Utility.h"

std::vector<int> GenerateVecSeq(int start, int end)
{
    std::vector<int> v;
    if(end <= start)
        return v;
        
    int size = end - start;
    v.reserve(size);

    for(int i = start; i < end; ++i)
        v.push_back(i);
        
    return v;
}

std::list<int> GenerateListSeq(int start, int end)
{
    std::list<int> list;
    if(end <= start)
        return list;
        
    int size = end - start;

    for(int i = start; i < end; ++i)
        list.push_back(i);
        
    return list;
}

std::stack<int> GenerateStackSeq(int start, int end)
{
    std::stack<int> s;
    if(end <= start)
        return s;
        
    int size = end - start;

    for(int i = start; i < end; ++i)
        s.push(i);
        
    return s;
}

std::queue<int> GenerateQueueSeq(int start, int end)
{
    std::queue<int> q;
    if(end <= start)
        return q;
        
    int size = end - start;

    for(int i = start; i < end; ++i)
        q.push(i);
        
    return q;
}


