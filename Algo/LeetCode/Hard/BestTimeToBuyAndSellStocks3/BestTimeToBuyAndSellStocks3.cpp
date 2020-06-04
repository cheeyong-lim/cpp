#include "Utility/Utility.h"

int maxProfit(const std::vector<int>& prices) 
{
    int profit = 0;
    if(prices.size() >= 2)
    {
        std::vector<int> left(prices.size());
        std::vector<int> right(prices.size());

        left[0] = 0;
        int min = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            min = std::min(min, prices[i]);
            left[i] = std::max(left[i - 1], prices[i] - min);
        }

        right[0] = 0;
        int max = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i > 0; --i) 
        {
            max = std::max(max, prices[i]);
            right[i] = std::max(right[i + 1], max - prices[i]);
        }
       
        for(int i = 0; i < prices.size(); ++i)
        {
            int sum = left[i] + right[i];
            if (profit < sum)
                profit = sum;
        }
    }
    return profit;
}

int maxProfit_bruteforce(const std::vector<int>& prices)
{
    int profit = 0;
    if(prices.size() >=2)
    {
        int buy = 0;
        bool decreasing = true;
        std::vector<std::vector<int>> map(prices.size() - 1);
        for(int buy = 0; buy < prices.size() - 1; ++buy)
        {
            for(int sell = buy + 1; sell < prices.size(); ++sell)
            {
                int sale = prices[sell] - prices[buy];
                if (sale > profit) 
                {
                    profit = sale;
                    decreasing = false;
                }

                map[buy].push_back(sale);
            } 
        }
        //early termination for decreasing stocks
        if (decreasing)
            return profit;

        int lastOfMap = map.size() - 1;
        for (int i = 0; i < map.size(); ++i) 
        {
            for (int j = 0; j < map[i].size(); ++j) 
            {
                if (map[i][j] > 0) 
                {
                    //map[i][j] = bought at index i, sold at index i + j + 1
                    for (int nextbuy = i + j + 2; nextbuy < map.size(); ++nextbuy) 
                    {
                        for (int nextsell = 0; nextsell < map[nextbuy].size(); ++nextsell) 
                        {
                            int currProfit = (map[nextbuy][nextsell] > 0) ? map[i][j] + map[nextbuy][nextsell] : map[i][j];
                            if (currProfit > profit)
                                profit = currProfit;
                        }
                    }
                    
                }
            }
        }
    }
    return profit;
}

int main()
{
    std::cout<<maxProfit_bruteforce(std::vector<int>{3, 3, 5, 0, 0, 3, 1, 4}) << std::endl;
    std::cout<<maxProfit_bruteforce(std::vector<int>{1, 2, 3, 4, 5})<<std::endl;
    std::cout<<maxProfit_bruteforce(std::vector<int>{7,6,4,3,1})<<std::endl; 
    std::cout<<maxProfit_bruteforce(std::vector<int>{7, 1, 5, 3, 6, 4})<<std::endl;
    std::cout << maxProfit_bruteforce(std::vector<int>{2, 1, 2, 0, 1}) << std::endl;

    std::cout << maxProfit(std::vector<int>{3, 3, 5, 0, 0, 3, 1, 4}) << std::endl;
    std::cout << maxProfit(std::vector<int>{1, 2, 3, 4, 5}) << std::endl;
    std::cout << maxProfit(std::vector<int>{7, 6, 4, 3, 1}) << std::endl;
    std::cout << maxProfit(std::vector<int>{7, 1, 5, 3, 6, 4}) << std::endl;
    std::cout << maxProfit(std::vector<int>{2, 1, 2, 0, 1}) << std::endl;
}