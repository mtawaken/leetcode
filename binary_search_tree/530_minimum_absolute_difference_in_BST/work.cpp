/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;
class Solution {
public:
    /*
     * 这个求的是相邻父子相差最小的间隔，不符合题意`
     */
    int getMinimumDifference2(TreeNode* root) {
        int l = INT_MAX, r = INT_MAX;
        if (root->left) {
            l = std::min(abs(root->val - root->left->val), getMinimumDifference(root->left));
        }
        if (root->right) {
            r = std::min(abs(root->val - root->right->val), getMinimumDifference(root->right));
        }
        return std::min(l, r);
    }
    /*
     * 拿出所有的数比较间隔最小的
     */
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> vec;
        dfs(root, vec);
        std::sort(vec.begin(), vec.end());
        int res = INT_MAX;
        for (int i = 1; i < vec.size(); ++i) {
            res = std::min(res, vec[i] - vec[i - 1]);
        }
        return res;

    }
    void dfs (TreeNode* root, std::vector<int>& vec) {
       if (!root) return;
       vec.push_back(root->val);
       dfs(root->left, vec);
       dfs(root->right, vec);
    }
};

int main () {
    TreeNode *r = new TreeNode(3);
    r->left = new TreeNode(5);
    r->left->right = new TreeNode(6);
    r->right = new TreeNode(2);
    Solution s;
    std::cout << s.getMinimumDifference(r);
    return 0;
}
