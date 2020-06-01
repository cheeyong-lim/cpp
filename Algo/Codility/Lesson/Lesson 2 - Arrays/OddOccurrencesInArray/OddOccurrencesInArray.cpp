#include "Utility/Utility.h"

int OddOccurrencesInArray(std::vector<int> &A) {
	std::unordered_map<int, int> map;
	for (auto& elem : A)
	{
		if (map.find(elem) == map.end())
			map[elem] = 1;
		else
			++map[elem];
	}

	for (auto it = map.begin(); it != map.end(); ++it)
	{
		if (it->second % 2)
			return it->first;
	}

	return -1;
}

bool TestCase(const std::vector<int>& v1, int answer, bool verbose)
{
   std::cout<<"---- Test Case -----"<<std::endl;
   std::vector<int> tempV1 = v1;
   int myanswer = -1;
   {
        Timer timer("OddOccurrencesInArray : ", Timer::TYPE::ALL);
        myanswer = OddOccurrencesInArray(tempV1);
        
   }

    bool result = Compare<int>(myanswer, answer, verbose);
    std::string str = result ? "Passed!" : "Failed!";
    std::cout<< "Result : "<<str<<std::endl;
    return result;
}

bool RandomTestCase(int arraySize, bool verbose)
{
    RandomIntGenerator generator(1, 1000);
    int answer = generator.GetRandom();
    std::vector<int> vec;
    vec.reserve(arraySize + 1);
    int halfSize = arraySize * 0.5f;
    vec.push_back(answer);
    for(int i = 0; i < halfSize; ++i)
    {
        int num = generator.GetRandom();
        while(num == answer)
            num = generator.GetRandom();
        vec.push_back(num);
        vec.push_back(num);
    }
    ScrambleVector(vec);
    
     return TestCase(vec, answer, verbose);
}

int main()
{
    bool v = true;
    bool result = true;
    if(!TestCase(std::vector<int>{1, 9, 1 }, 9, v))
        result = false;
    if(!TestCase(std::vector<int>{1, 1, 9 }, 9, v))
        result = false;
    if(!TestCase(std::vector<int>{9, 3, 9, 3, 9,  7, 9},  7, v))
        result = false;
    if(!TestCase(std::vector<int>{1},  1, v))
        result = false;
    if(!TestCase(std::vector<int>{9, 9, 9 }, 9, v))
        result = false;
    if (!RandomTestCase(100, v))
        result = false;
    if (!RandomTestCase(1000, v))
        result = false;
    if (!RandomTestCase(10000, v))
        result = false;
    std::string str = result ? "Passed!" : "Failed!";
    std::cout<< "***** Final Result *****"<<std::endl;
    std::cout<<"Final Result : "<<str<<std::endl;
}