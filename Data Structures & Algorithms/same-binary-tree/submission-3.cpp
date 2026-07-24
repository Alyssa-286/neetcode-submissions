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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //can we store the nodes of the tree in level order in an array with nulls then we can compare if both arrays are same then return true else false?
        //although we can do this it requres extra space and more time not optmial time O(N) space O(N)
        //we can optimize it better
        if(p==nullptr && q==nullptr)
        {
            return true;
        }
      //  else if((p==nullptr && q!=nullptr) || (p!=nullptr && q== nullptr)||p->val!=q->val)
      //or we can write it as
      if(p==nullptr||q==nullptr||p->val!=q->val)
        return false;
        //traverse left subtree right subtree then if thheu are equal send true
        return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }
};
