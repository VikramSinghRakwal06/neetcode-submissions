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
    void isValid(TreeNode* root, bool& flag, int mini, int maxi){
        if(!root)return;
        if(!flag)return;
        if(root->val<=mini || root->val>=maxi){
            flag = false;
            return;
        }
        if(flag){
            isValid(root->left, flag, mini, root->val);
            isValid(root->right, flag, root->val, maxi);
        }

    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        isValid(root, flag, INT_MIN, INT_MAX);
        return flag;
    }
};
