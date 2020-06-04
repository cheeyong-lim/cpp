#include "Utility/Utility.h"

int maxProfit(const std::vector<int>& prices) 
{
    int profit = 0;
    if(prices.size() >= 2)
    {
        auto buy = prices.begin();
        auto sell  = prices.begin() + 1;
        while(sell != prices.end())
        {
            if(*buy < *sell)
            {
                profit += *sell - *buy;
            }
            ++buy;
            ++sell;
        }
    }
    return profit;
}

int main()
{
    std::cout<<maxProfit(std::vector<int>{7,1,5,3,6,4})<<std::endl;
}