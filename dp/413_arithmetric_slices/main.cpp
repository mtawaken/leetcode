/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20181008 154806
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        bool prev = false;
        int count = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            for (int j = i + 2; j < A.size(); ++j) {
                bool continued = false;
                if (A[j] - A[j - 1] == A[j - 1] - A[j - 2]) {
                    continued = true;
                }
                if (j - i == 2) {
                    prev = continued;
                    if (continued) {
                        count++;
                    }
                    continue;
                }
                if (prev && continued) {
                    prev = 1;
                    count++;
                } else {
                    prev = 0;
                }
            }
        }
        return count;
    }
};
