/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        int fullpath = root->val + left + right;
        int onepath = root->val + max(left,right);
        int onlyroot = root->val;

        maxSum = max({maxSum,fullpath, onepath, onlyroot});
        return max(onlyroot,onepath);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
