/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180106 153144
 ************************************************************************/

#include <iostream>
using namespace std;

/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Note use variable outside inorder structure is also possible(Recommand).
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        return aux(root, 0);
    }
private:
    TreeNode* aux(TreeNode* root, int biggerv) {
        if (!root) {
            return NULL;
        }
        if (root->right) {
            // bigger ones in subtree
            TreeNode* right = aux(root->right, biggerv);
            root->val += right->val;
        } else {
            root->val += biggerv;
        }
        if (root->left) {
            return aux(root->left, root->val);
        }
        return root;
    }
};

int main() {
    return 0;
}
