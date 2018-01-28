/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180124 203924
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
 * dfs framework with additional params
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        result = INT_MAX;
        inited = false;
        dfs(root, 0);
        if (!inited) {
            return 0;
        } else {
            return result;
        }
    }
    void dfs(TreeNode* node, int depth) {
        if (!node) {
            return;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
        if (!node->left && !node->right) {
            result = min(result, depth + 1);
            inited = true;
        }
    }
private:
    int result;
    bool inited;
};
int main() {

}
