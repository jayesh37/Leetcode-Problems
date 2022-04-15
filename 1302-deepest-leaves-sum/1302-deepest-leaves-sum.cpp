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
    int sum=0;
    int height;
    
    int getheight(TreeNode *root,int h)
    {
        if(root==NULL)  return 0;
        
        int lh=getheight(root->left,h+1);
        int rh=getheight(root->right,h+1);
        
        return 1+max(lh,rh);
    }
    
    void solve(TreeNode *root,int h)
    {
        if(root==NULL)
            return;
        
        if(h==height){
            sum=sum+ root->val;
            return;
        }
        
        solve(root->left,h+1);
        solve(root->right,h+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        height=getheight(root,0);
        
        solve(root,1);
        
        return sum;
    }
};