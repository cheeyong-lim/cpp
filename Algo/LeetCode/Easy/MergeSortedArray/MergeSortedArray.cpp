#include "Utility/Utility.h"

 using namespace std;
 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    if (n == 0)
        return;

    if (m == 0)
    {
        for (int i = 0; i < n; ++i)
            nums1[i] = nums2[i];
        return;
    }

    const std::vector<int>& smallerArray = (m <= n) ? nums1 : nums2;
    const std::vector<int>& greaterArray = (m <= n) ? nums2 : nums1;
    int smallerSize, greaterSize;
    if(m <= n)
    {
        smallerSize = m;
        greaterSize = n;
    }
    else
    {
        smallerSize = n;
        greaterSize = m;
    }

    std::vector<int> mergedArray;
    mergedArray.reserve(nums1.size());

    /*
        1,4,5
        2,3,4,6

        1


    */
    int i = 0, j = 0;
    for(; i < smallerSize && j < greaterSize;)
    {
        if(smallerArray[i] < greaterArray[j])
        {
            mergedArray.push_back(smallerArray[i++]);
        }
        else if(smallerArray[i] == greaterArray[j])
        {
            mergedArray.push_back(smallerArray[i++]);
            mergedArray.push_back(greaterArray[j++]);
        }
        else
        {
            mergedArray.push_back(greaterArray[j++]);
        } 
    }

    //push whatever left over of the arry with greater size into the merged
    for(; j < greaterSize; ++j)
        mergedArray.push_back(greaterArray[j]);

    //in case smaller array contain the biggest elem.
    for (; i < smallerSize; ++i)
        mergedArray.push_back(smallerArray[i]);

    std::swap(mergedArray, nums1);
}

int main()
{
    std::vector<int> num1 = {1,2,3,0,0,0};
    std::vector<int> num2 = {2,5,6};
    merge(num1, 3, num2, num2.size());
    for(auto& elem : num1)
        std::cout<<elem<<" ";
}