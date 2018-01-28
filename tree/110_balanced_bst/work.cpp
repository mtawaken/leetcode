/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180128 153457
 ************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * calculate height need bottom up, so does check balanced. Merge into one dfs:
 * 1. carry additional param
 * 2. global variable
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int tmp;
        return isBalanced(root, tmp); 
    }
    int isBalanced(TreeNode* node, int& height) {
        if (!node) {
            height = 0;
            return true;
        }
        int l, r;
        if (!isBalanced(node->left, l) || !isBalanced(node->right, r) || abs(l - r) > 1) {
            return false;
        }
        height = max(l, r) + 1; 
        return true;
    } 
};
