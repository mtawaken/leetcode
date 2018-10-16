/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20181010 113035
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) {
            return 0;
        }
        int max_buy = -prices[0] - fee;
        int max_sell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int buy = max_sell - prices[i] - fee;
            int sell = max_buy + prices[i];
            max_buy = std::max(max_buy, buy);
            max_sell = std::max(max_sell, sell);
        }
        return max_sell;
    }
};
