/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180929 204922
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int x = 1;
        int y = 2;
        int z = 0;
        for (int i = 2; i < n; i++) {
            z = y;
            y = x + y;
            x = z;
        }
        return y;
    }
};
