#include "Utility/Utility.h"
#include "binary_gap_template.hpp"

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

void run_tests_for_solution_1()
{
	bool v = true;
	bool result = true;
	std::cout << "Running test cases for solution 1" << std::endl;
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

void assert_testcase(bool condition, const char *failure_message, const char *file_name, long line_number)
{
	if (!condition)
	{
		std::cout << file_name << ", line " << line_number << ": " << failure_message << '\n';
	}
}

#define ASSERT_TESTCASE(condition) \
	assert_testcase((condition), "\"" #condition "\" - NOT OK", __FILE__, __LINE__)

void run_tests_for_solution_2()
{
	using namespace codility::lesson_1;
	Timer timer("", Timer::MILLISEC);
	std::cout << "Running tests for solution 2\n";
	ASSERT_TESTCASE(binary_gap<int>(0) == 0);
	ASSERT_TESTCASE(binary_gap<int>(1) == 0);
	ASSERT_TESTCASE(binary_gap<int>(2) == 0);
	ASSERT_TESTCASE(binary_gap<int>(3) == 0);
	ASSERT_TESTCASE(binary_gap<int>(4) == 0);
	ASSERT_TESTCASE(binary_gap<int>(5) == 1);
	ASSERT_TESTCASE(binary_gap<int>(9) == 2);
	ASSERT_TESTCASE(binary_gap<int>(15) == 0);
	ASSERT_TESTCASE(binary_gap<int>(16) == 0);
	ASSERT_TESTCASE(binary_gap<int>(17) == 3);
	ASSERT_TESTCASE(binary_gap<int>(20) == 1);
	ASSERT_TESTCASE(binary_gap<int>(32) == 0);
	ASSERT_TESTCASE(binary_gap<int>(529) == 4);
	ASSERT_TESTCASE(binary_gap<int>(1041) == 5);
	ASSERT_TESTCASE(binary_gap<int>(1073741824) == 0);
	ASSERT_TESTCASE(binary_gap<int>(1073741825) == 29);
	std::cout <<"Tests completed.\n";
}

int main()
{
	run_tests_for_solution_1();
	run_tests_for_solution_2();
	return 0;
}
