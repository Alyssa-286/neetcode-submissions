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
    bool issametree(TreeNode* root,TreeNode* subroot)
    {
        if(root==nullptr && subroot==nullptr)
        return true;
        if(root==nullptr||subroot==nullptr||root->val!=subroot->val)
        return false;
        return(issametree(root->left,subroot->left)&&issametree(root->right,subroot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==nullptr)
        return false;
        if(subroot==nullptr)
        return true;
        //now actual node or left or right
        if(issametree(root,subroot))
        return true;
       // return(isSubtree(root->left,subroot->left)||isSubtree(root->right,subroot->right));
       //you might want to write this but it is wrong because subroot->left points to the left of subroot but we want it to be subroot because root->left suppose 2 then subroot is 2 not subroot of left same goes to right
       return(isSubtree(root->left,subroot)||isSubtree(root->right,subroot));
    }
};
