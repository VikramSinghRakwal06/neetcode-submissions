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
    int dfs(TreeNode* root, int& maxi){
        if(!root)return 0;
        int leftSum = max(0,dfs(root->left, maxi));
        int rightSum = max(0,dfs(root->right, maxi));
        int curr = leftSum+rightSum+root->val;
        maxi = max(curr, maxi);
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};
