#include "Utility/Utility.h"

int maxProfit_bruteforce(const std::vector<int>& prices) 
{
    int profit = 0;
    if(prices.size() >= 2)
    {
        auto buyLast = prices.end() - 1;
        for(auto buy = prices.begin(); buy != buyLast; ++buy)
        {
            for(auto sell = buy + 1; sell != prices.end(); ++sell)
            {
                int currProfit = *sell - *buy;
                if(currProfit > profit)
                    profit = currProfit;
            }
        }
    }
    return profit;
}

int maxProfit(const std::vector<int>& prices) 
{
    int profit = 0;
    if(prices.size() >= 2)
    {
        int lowest = INT_MAX;
        for(auto it = prices.begin(); it != prices.end(); ++it)
        {
            if(*it < lowest)
            {
                lowest = *it;
            }
            else if(*it - lowest > profit)
            {
                profit = *it - lowest;
            }
        }
    }
    return profit;
}

int main()
{
    std::cout<<maxProfit_bruteforce(std::vector<int>{7,1,5,3,6,4})<<std::endl; //5
    std::cout<<maxProfit_bruteforce(std::vector<int>{7,6,4,3,1})<<std::endl; //0
    std::cout<<maxProfit(std::vector<int>{7,1,5,3,6,4})<<std::endl; //5
    std::cout<<maxProfit(std::vector<int>{7,6,4,3,1})<<std::endl; //0
}