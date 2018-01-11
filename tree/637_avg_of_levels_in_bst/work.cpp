/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180111 105851
 ************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) {
            return res;
        }
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int n = queue.size();
            double avg = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();
                avg += (node->val);
                if (node->left) {
                    queue.push_back(node->left);
                }
                if (node->right) {
                    queue.push_back(node->right);
                }
            }
            res.push_back(avg / n);
        }
        return res;
 
    }
};
int main() {

}
