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
    
    int maxAncestorDiff(TreeNode* root,int mx=-1,int mn=100001) {
        if(root==nullptr)
            return mx-mn;
        
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        
        int l_subtree = maxAncestorDiff(root->left,mx,mn);
        int r_subtree = maxAncestorDiff(root->right,mx,mn);
        
        return max(l_subtree,r_subtree);
    }
};