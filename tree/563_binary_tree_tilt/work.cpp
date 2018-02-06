/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180206 190105
 ************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 1. tranvert problem to another dfs framework
 * 2. global statistical variable
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        total = 0;
        sumTree(root);
        return total;
    }
    int sumTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = sumTree(root->left);
        int r = sumTree(root->right);
        total += abs(l - r);
        return l + r + root->val;
    }
private:
    int total;
};

int main() {

}
