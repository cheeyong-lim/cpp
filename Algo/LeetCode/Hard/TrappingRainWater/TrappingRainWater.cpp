#include "Utility/Utility.h"

int trap_dynamic(const std::vector<int>& height) 
{
    int water = 0;
    if (height.size() <= 1)
        return water;

    std::vector<int> leftMaxVec(height.size());
    std::vector<int> rightMaxVec(height.size());

    leftMaxVec[0] = height[0];
    for (int i = 1; i < height.size(); ++i) 
    {
        leftMaxVec[i] = std::max(height[i], leftMaxVec[i - 1]);
    }

    rightMaxVec[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; --i) 
    {
        rightMaxVec[i] = std::max(height[i], rightMaxVec[i + 1]);
    }

    for (int i = 0; i < height.size(); ++i)
        water += std::min(leftMaxVec[i], rightMaxVec[i]) - height[i];

    return water;
}

int trap_bruteforce(const std::vector<int>& height) 
{
    int water = 0;
    if (height.size() <= 1)
        return water;
    
    for (int curr = 0; curr != height.size(); ++curr) 
    {
        int leftMax = 0;
        int rightMax = 0;

        for (int left = curr; left >= 0; --left) 
        {
            leftMax = std::max(leftMax, height[left]);
        }

        for (int right = curr; right < height.size(); ++right) 
        {
            rightMax = std::max(rightMax, height[right]);
        }
            
        water += std::min(leftMax, rightMax) - height[curr];
    }

    return water;
}



int main()
{
    std::cout<<trap_dynamic(std::vector<int>{0,1,0,2,1,0,1,3,2,1,2,1})<<std::endl;
    std::cout<<trap_bruteforce(std::vector<int>{0,1,0,2,1,0,1,3,2,1,2,1})<<std::endl;
}