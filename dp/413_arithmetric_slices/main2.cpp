/*************************************************************************
    > File Name: main2.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20181008 161425
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
private:
    map<int, int> _dp;
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int prev, cur, prevpos;
        int count = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (i == 1) {
                prev = A[1] - A[0];
                prevpos = 0;
                continue;
            }
            cur = A[i] - A[i - 1];
            if (cur != prev) {
                count += cal_num(i - prevpos);
                prevpos = i - 1;
                prev = cur;
            }
        }
        count += cal_num(A.size() - prevpos);
        return count;
    }
    int cal_num(int n) {
        if (n < 3) {
            return 0;
        }
        auto iter = _dp.find(n);
        if (iter != _dp.end()) {
            return iter->second;
        }
        int sum = 0;
        for (int i = 3; i <= n; ++i) {
            sum += n - i + 1;
        }
        _dp[n] = sum;
        return sum;
    }
};
