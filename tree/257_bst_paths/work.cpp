/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180112 140200
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

/*
 * dfs backtrace
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<string> path;
        dfs(root, path, res);    
        return res;
    }
    void dfs(TreeNode* cur, vector<string>& path, vector<string>& res) {
        if (!cur) {
            return;
        }
        path.push_back(to_string(cur->val));
        if (!cur->left && !cur->right) {
            string str;
            for (auto const& s: path) {
                if (!str.empty()) {
                    str += "->";
                }
                str += s; 
            }
            res.push_back(str);
        } else {
            dfs(cur->left, path, res);
            dfs(cur->right, path, res);
        }
        path.pop_back();
    }
};

int main() {

}
