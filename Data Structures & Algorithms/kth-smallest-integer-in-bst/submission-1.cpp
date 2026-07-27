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
    /*
        void dfs(TreeNode* node, vector<int>&ans)
    {
        if(node==nullptr)
        return;
        dfs(node->left,ans);
        ans.push_back(node->val);
        dfs(node->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        dfs(root,ans);
        return ans;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr)
        return 0;
        vector<int>ans;
        ans=inorderTraversal(root);
        return ans[k-1];
    }*/
    //now can we optimize space? without vectors? and alsoo time for very large trees with so many nodes?
    //yessss sooooooo
    void inorder(TreeNode* node,int &k,int &result)
    {
        if(node==nullptr)
        return;
        inorder(node->left,k,result);
        k--;
        if(k==0)
        {
            result=node->val;
            return;
        }
        if(k>0)
        {
            inorder(node->right,k,result);
        }
        
    }
     int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr)
        return 0;
        int result=-1;
        inorder(root,k,result);
        return result;
     }

};
