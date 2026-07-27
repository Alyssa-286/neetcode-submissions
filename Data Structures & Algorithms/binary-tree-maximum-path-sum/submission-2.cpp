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
    int glomax=INT_MIN;
    int dfs(TreeNode* node)
    {
        if(node==nullptr)
        return 0;
        int leftmax=max(0,dfs(node->left));
        int rightmax=max(0,dfs(node->right));
        glomax=max(leftmax+rightmax+node->val,glomax);
       // if(leftmax>rightmax)
        //return node->val+leftmax;
        //return node->val+rightmax;
        //can update this to 
        return node->val+max(leftmax,rightmax);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
        return 0;
        dfs(root);
        return glomax;

    }
};
