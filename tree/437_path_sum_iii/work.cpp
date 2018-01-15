/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180115 104910
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
 * 1. problem convert
 * 2. two dfs
 *
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        count = 0; 
        dfs(root, sum);
        return count;
    }
private:
    void dfs(TreeNode* cur, long long sum) {
        if (!cur) {
            return;
        }
        work(cur, sum);
        dfs(cur->left, sum);
        dfs(cur->right, sum);
    }
    void work(TreeNode* root, long long sum) {
        if (!root) {
            return; 
        }
        if (sum == root->val) {
            count++;
        }
        work(root->left, sum - root->val);
        work(root->right, sum - root->val);
    }
    long long count;
};
