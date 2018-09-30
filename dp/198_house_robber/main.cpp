/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180929 210626
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
        int x = nums[0];
        int y = std::max(nums[0], nums[1]);
        int ans = 0;
        for (int i = 2; i < nums.size(); ++i) {
            ans = std::max(x + nums[i], y);
            x = y;
            y = ans;
        }
        return ans;
    }
};

int main()
{
    std::vector<int> x{1,2,3,1};
    Solution s;
    std::cout << s.rob(x);
}
