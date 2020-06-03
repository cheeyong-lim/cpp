#include "Utility/Utility.h"

int DoClimbStairs(int currStep, int n)
{
    if (currStep > n)
    {
        return 0;
    }
    if (currStep == n)
    {
        return 1;
    }

    int  climb1 = DoClimbStairs(currStep + 1, n);
    int climb2 = DoClimbStairs(currStep + 2, n);
    return climb1 + climb2;;
}
//1 or 2 steps
int climbStairs_rec(int n)
{
    return DoClimbStairs(0, n);
}

int climbStairs(int n) 
{
    if (n <= 1)
        return n;
    std::vector<int>v(n + 1);
    v[1] = 1;
    v[2] = 2;
    for(int i = 3; i <= n; ++i)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
}

int main()
{
    std::cout<<climbStairs(4)<<std::endl;
    std::cout<<climbStairs_rec(4)<<std::endl;
}
