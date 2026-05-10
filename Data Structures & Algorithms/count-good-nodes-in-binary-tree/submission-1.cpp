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
    void good(TreeNode* root, int& nodes, int curr){
        if(!root)return ;
        if(root->val>=curr){
            curr=root->val;
            nodes++;
        }
        good(root->left, nodes, curr);
        good(root->right, nodes, curr);
    }
    int goodNodes(TreeNode* root) {
        int nodes = 0;
        if(!root)return 0;
        good(root, nodes, root->val);
        return nodes;
    }
};
