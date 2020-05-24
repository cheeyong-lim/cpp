#include <vector>
#include <iostream>
#include <string>
#include "Utility/Utility.h"

int BinaryGap(int N) 
{
	int bitLength = sizeof(int) * 8;
	unsigned int bitMask = 1;
	std::vector<int> onePosVec;
	onePosVec.reserve(bitLength);
	for (int i = 0; i < bitLength; ++i, bitMask <<= 1)
	{
		if (N & bitMask)
		{
			onePosVec.push_back(i);
		}
	}

	int largest = 0;
	for (auto it = onePosVec.begin(); it != onePosVec.end(); ++it)
	{
		auto nextIt = it + 1;
		if (nextIt == onePosVec.end())
		{
			break;
		}
		else
		{
			int diff = *nextIt - *it - 1;
			//std::cout << diff << std::endl;
			if (diff > 0)
			{
				if (diff  > largest)
				{
					largest = diff;
				}
			}
		}
	}
	return largest;
}

bool TestCase(int binaryGapN, int answer, bool verbose)
{
    std::cout<<"---- Test Case -----"<<std::endl;
    int myanswer = -1;
    {
        Timer timer("BinaryGap : ", Timer::TYPE::ALL);
        myanswer = BinaryGap(binaryGapN);
    }
    
    std::cout<<"BinaryGap("<<binaryGapN<<") : "<<answer<<std::endl;
    bool result = Compare<int>(myanswer, answer, verbose);
    std::string str = result ? "Passed!" : "Failed!";
    std::cout<< "Result : "<<str<<std::endl;
    return result;
}

int main()
{
    bool v = true;
    bool result = true;
    if(!TestCase(9, 2, v))
        result = false;
    if(!TestCase(529, 4, v))
        result = false;
    if(!TestCase(20, 1, v))
        result = false;
    if(!TestCase(15, 0, v))
        result = false;
    if(!TestCase(32, 0, v))
        result = false;
    if(!TestCase(1041, 5, v))
        result = false;
    
    std::string str = result ? "Passed!" : "Failed!";
    std::cout<< "***** Final Result *****"<<std::endl;
    std::cout<<"Final Result : "<<str<<std::endl;
}