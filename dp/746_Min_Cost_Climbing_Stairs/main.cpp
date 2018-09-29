/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180929 163055
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 2) {
            return 0;
        }
        std::vector<int> res(cost.size());
        res[0] = cost[0];
        res[1] = cost[1]; // cause non-negtive
        for (int i = 2; i < res.size(); ++i) {
            res[i] = std::min(res[i - 2], res[i - 1]) + cost[i];
        }
        return std::min(res[res.size() - 1], res[res.size() - 2]);
    }
};

int main()
{
}
