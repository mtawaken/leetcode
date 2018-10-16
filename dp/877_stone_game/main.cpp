/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20181005 113645
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> res {n, vector<int>(n)}; 
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    res[i][j] = piles[i];
                } else {
                    res[i][j] = max(piles[i] - res[i + 1][j], piles[j] - res[i][j - 1]);
                }
            }
        }
        return res[0][n - 1] > 0;

    }
};
