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
    bool helper(TreeNode* node,long long minval,long long maxval)
    {
        if(node==nullptr)
        return true;
        if(node->val<=minval || node->val>= maxval)
        return false;
        return (helper(node->left,minval,node->val)&&helper(node->right,node->val,maxval));
    }
    bool isValidBST(TreeNode* root) {
        if (root==nullptr)
        return true;
       // if(root->val>root->left->val && root->val<root->right->val)
        //return true;
        //return(isValidBST(root->left) && isValidBST(root->right));
        long long minval=LLONG_MIN;
        long long maxval=LLONG_MAX;
        return(helper(root,minval,maxval));
    }
};
