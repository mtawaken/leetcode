/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180110 173135
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
 * 1. dfs + bst-find
 * 2. bst->array & two pointer for sum problem
 * 3. bst->hashtable
 */

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k); 
    }
    bool dfs(TreeNode* root, TreeNode* cur, int k) {
        if (!cur) {
            return false;
        }
        if (find(root, cur, k - cur->val)) {
            return true;
        }
        return dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }
    bool find(TreeNode* root, TreeNode* cur, int v) {
        if (!root) {
            return false;
        }
        if (root != cur && root->val == v) {
            return true;
        }
        if (root->val < v) {
            return find(root->right, cur, v);
        } else {
            return find(root->left, cur, v);
        }
    }
    
};

int main() {
    TreeNode* two = new TreeNode(2);
    TreeNode* one = new TreeNode(1);
    TreeNode* three = new TreeNode(3);
    two->left = one;
    two->right = three;
    Solution s;
    std::cout << s.findTarget(two, 4);
    return 0;
}
