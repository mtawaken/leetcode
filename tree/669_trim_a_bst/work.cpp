/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180110 133351
 ************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) {
            return NULL;
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        } else if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

int main() {
    return 0;
}
