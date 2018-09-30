/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180930 122154
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> _processed;
public:
    NumArray(vector<int> nums) {
        if (nums.size() == 0) {
            return;
        }
        _processed.reserve(nums.size()); 
        _processed[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            _processed[i] = _processed[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i > 0) {
            return _processed[j] - _processed[i - 1] ;
        } else {
            return _processed[j];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
