/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180128 170909
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * BFS
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            vector<int> values;
            int size = queue.size();
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();
                if (node) {
                    values.push_back(node->val);
                    queue.push_back(node->left);
                    queue.push_back(node->right);
                }
            }
            if (values.size() != 0) {
                res.push_back(values);
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
