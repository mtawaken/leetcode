/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180124 200515
 ************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

/*
 * 1. convert to tree height framework
 * 2. plant additional computation for left tree height + right tree heigh
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        height(root);
        return result;
    }
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        result = max(result, l + r);
        return max(l, r) + 1; 
    }
private:
    int result;
};
