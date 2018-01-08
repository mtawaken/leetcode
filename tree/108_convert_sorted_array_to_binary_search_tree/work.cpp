/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180106 165943
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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return aux(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* aux(vector<int>& nums, int s, int e) {
        if (e - s < 0) {
            return NULL;
        } 
        int mid = (e + s) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = aux(nums, s, mid - 1);
        root->right = aux(nums, mid + 1, e);
        return root;
    } 
};

int main() {
    std::vector<int> nums{
        1,2,3,4,5,6,7
    };
    Solution s;
    s.sortedArrayToBST(nums);
    return 0;
}
