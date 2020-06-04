#include "Utility/Utility.h"

int evalRPN(const std::vector<std::string>& tokens) 
{
    std::vector<int> numberStack;
    numberStack.reserve(tokens.size());
    int result = 0;
    for(auto it = tokens.begin(); it != tokens.end(); ++it)
    {
        if(*it == "+")
        {
            int result = *numberStack.rbegin() + *(numberStack.rbegin() + 1);
            numberStack.pop_back();
            numberStack.pop_back();
            numberStack.push_back(result);
        }
        else if(*it == "-")
        {
            int result = *(numberStack.rbegin() + 1) - *numberStack.rbegin();
            numberStack.pop_back();
            numberStack.pop_back();
            numberStack.push_back(result);
        }
        else if(*it == "*")
        {
            int result = *(numberStack.rbegin() + 1) * *numberStack.rbegin();
            numberStack.pop_back();
            numberStack.pop_back();
            numberStack.push_back(result);
        }
        else if(*it == "/")
        {
             int result = *(numberStack.rbegin() + 1) / *numberStack.rbegin();
            numberStack.pop_back();
            numberStack.pop_back();
            numberStack.push_back(result);
        }
        else
        {
            numberStack.push_back(std::stoi(*it));
        }
    }
    return numberStack.back();
}

int main()
{
    std::cout<<evalRPN(std::vector<std::string>{"2", "1", "+", "3", "*"})<<std::endl; //9
    std::cout<<evalRPN(std::vector<std::string>{"4", "13", "5", "/", "+"})<<std::endl; //6
    std::cout<<evalRPN(std::vector<std::string>{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"})<<std::endl; //22
}