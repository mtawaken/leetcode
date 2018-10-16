/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20181008 115023
 ************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp {s.size(), vector<int>(s.size())};
        int count = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            dp[i][i] = 1;
            count++;
            for (int j = i + 1; j < s.size(); ++j) {
                if (j - i == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        count++;
                    } else {
                        dp[i][j] = 0;
                    }
                    continue;
                }
                if (dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    count++;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("aaa") << endl;
}
