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
    void getinorder(TreeNode* root,vector<int> &inorder)
    {
        if(root==NULL)  return;
        
        getinorder(root->left,inorder);
        inorder.push_back(root->val);
        getinorder(root->right,inorder);
    }
    
    TreeNode* constructBST(vector<int> &inorder,int left,int right)
    {
        if(left>right)  return NULL;
        
        int mid = left + (right-left)/2;
        TreeNode *curr = new TreeNode(inorder[mid]);
        curr->left = constructBST(inorder,left,mid-1);
        curr->right = constructBST(inorder,mid+1,right);
        
        return curr;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        getinorder(root,inorder);
        
        return constructBST(inorder,0,inorder.size()-1);
    }
};