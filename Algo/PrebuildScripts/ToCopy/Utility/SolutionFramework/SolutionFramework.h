#pragma once
#include "../Utility/Utility.h"

#if 0
namespace Utility
{
    class Solution
    {
    public:
        virtual bool Run() = 0;
    };

    class SolutionFramework
    {
    public:
        SolutionFramework()
        {

        }
        
        ~SolutionFramework()
        {

        }
      
        SolutionFramework(const std::initializer_list<std::unique_ptr<Solution>>& list)
        {
            solution.reserve(list.size());
            for(auto it = list.begin(); it != list.end(); ++it)
            {
                solutions.push_back(std::move(*it));
            }
        }
      
        void AddSolution(std::unique_ptr<Solution> sln)
        {
        solutions.push_back(std::move(sln));
        }
    private:
        std::vector<std::unique_ptr<Solution>> solutions;
    }; 
}
#endif
