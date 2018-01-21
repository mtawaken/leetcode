/*************************************************************************
    > File Name: work.cpp > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180115 194131
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 1. BST in-order(like sorted array) can accumulate mode
 * 2. clear result mode array everytime 
 *
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        res.clear(); 
        if (root) {
            first = true;
            dfs(root);
        }
        return res;
    }
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        if (first) {
            first = false;
            prev_val = root->val;
            max_count = 0;
            count = 1;
        } else {
            if (prev_val == root->val) {
                count++;
            } else {
                prev_val = root->val;
                count = 1;
            }
        }

        if (count > max_count) {
            // first mode or history_mode = tracked mode
            res.clear();
            res.push_back(root->val);
            max_count = count;
        } else if (count == max_count) {
            // history_mode != tracked mode
            res.push_back(root->val);
        }
        dfs(root->right);
    }

private:
    bool first;
    int prev_val; 
    int count;
    int max_count;
    vector<int> res;
};
int main() {

}
