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
    int dfs(TreeNode* node,int maxsofar)
    {
        int countofgoodnodes=0;
        if(node==nullptr)
        return 0;
        if(node->val>=maxsofar)
        countofgoodnodes++;
        maxsofar=max(maxsofar,node->val);
       countofgoodnodes+= dfs(node->left,maxsofar) + dfs(node->right,maxsofar);
        return countofgoodnodes;
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        int count=root->val;
        count = dfs(root,count);
        return count;
        
    }
};
