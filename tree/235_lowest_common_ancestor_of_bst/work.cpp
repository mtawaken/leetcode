/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180128 163756
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
 * LCA in bst is easier.
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return NULL;
        }
        while ((root->val - p->val)*(root->val - q->val) > 0) {
            if (root->val > p->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};
