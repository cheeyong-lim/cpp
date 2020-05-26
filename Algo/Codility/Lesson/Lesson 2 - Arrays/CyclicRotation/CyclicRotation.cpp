#include "Utility/Utility.h"

void RotateArray(std::vector<int>& A) 
{
	auto it = A.rbegin();
	for (auto nextIt = it + 1; nextIt != A.rend(); ++it, ++nextIt) 
	{
		std::swap(*it, *nextIt);
	}
}

void PrintArray(const std::vector<int>& A) 
{
	for (auto& elem : A)
		std::cout << elem << " ";
	std::cout << std::endl;
}

std::vector<int> ArrayCyclicRotation(std::vector<int>& A, int K) 
{
	if (A.size() < 2 || A.size() == (unsigned)K)
		return A;
	//PrintArray(A);
	for (int i = 0; i < K; ++i) 
	{
		RotateArray(A);
		//PrintArray(A);
	}

	return A;
}

bool TestCase(const std::vector<int>& v1, int k, const std::vector<int>& v2, bool verbose)
{
   std::cout<<"---- Test Case -----"<<std::endl;
   std::vector<int> tempV1 = v1;
   {
        Timer timer("ArrayCyclicRotation : ", Timer::TYPE::ALL);
        ArrayCyclicRotation(tempV1, k);
        
   }
    std::cout<<"ArrayCyclicRotation{";
    for(auto& elem : v1)
        std::cout<<elem<<" ";
    std::cout<<"} , k =  "<<k<<std::endl;
    bool result = Compare<int>(tempV1, v2, verbose);
    std::string str = result ? "Passed!" : "Failed!";
    std::cout<< "Result : "<<str<<std::endl;
    return result;
}

int main() 
{
    bool v = true;
    bool result = true;
    if(!TestCase(std::vector<int>{3,8,9,7,6}, 3, std::vector<int>{9,7,6,3,8}, v))
        result = false;
    if(!TestCase(std::vector<int>{0,0,0}, 3, std::vector<int>{0,0,0}, v))
        result = false;
    if(!TestCase(std::vector<int>{1,2,3,4}, 4, std::vector<int>{1, 2, 3, 4}, v))
        result = false;
    if(!TestCase(std::vector<int>{1,2}, 2, std::vector<int>{1, 2}, v))
        result = false;
    if(!TestCase(std::vector<int>{1,2 }, 1, std::vector<int>{2, 1}, v))
        result = false;
    if(!TestCase(std::vector<int>{}, 10, std::vector<int>{}, v))
        result = false;
    if(!TestCase(std::vector<int>{1}, 5, std::vector<int>{1}, v))
        result = false;
}