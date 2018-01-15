/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180114 104354
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 1. Problem convert
 * 2. dfs + global decorators
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        result = 0;
        auxPath(root);
        return result;
    }
private:
    int auxPath(TreeNode* root) {
        int ln = 0;
        int rn = 0;
        int lrn = 0;
        int rrn = 0;
        if (root && root->left) {
            ln = auxPath(root->left);
            if (root->val == root->left->val) {
                lrn = ln + 1;
            }
        }
        if (root && root->right) {
            rn = auxPath(root->right);
            if (root->val == root->right->val) {
                rrn = rn + 1;
            }
        }
        result = max(result, lrn + rrn);
        return max(lrn, rrn);

    }
    int result;
};

int main() {

}
