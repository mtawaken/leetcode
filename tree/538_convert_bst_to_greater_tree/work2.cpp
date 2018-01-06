/*************************************************************************
    > File Name: work2.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180106 162026
 ************************************************************************/

#include <iostream>
#include <stack>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * process all numbers in reverse order: BST inverser inorder traverse
 * work.cpp is recursive mode
 * work2.cpp is non-recursive mode, need stack for backwards and set for dedup
 */

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        // inverse inorder traverse
        stack.push(root);
        dedup.insert(root);
        int plus = 0;
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            if (node->right && dedup.find(node->right) == dedup.end()) {
                stack.push(node->right);
                dedup.insert(node->right);
                continue;
            }
            stack.pop();
            plus += node->val;
            node->val = plus;
            if (node->left) {
                stack.push(node->left);
                dedup.insert(node->left);
            }
        }
        return root;
    }
private:
    std::stack<TreeNode*> stack;
    std::set<TreeNode*> dedup;
};

int main (){

}
