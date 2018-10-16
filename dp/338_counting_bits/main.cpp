/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20181002 111849
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i) {
            res[i] = i % 2 + res[i / 2];
        }
        return res;
    }
};
