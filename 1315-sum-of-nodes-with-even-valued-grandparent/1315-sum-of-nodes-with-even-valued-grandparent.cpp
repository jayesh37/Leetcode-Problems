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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr->val % 2==0)
            {
                if(curr->left){
                    if(curr->left->left)
                        sum += curr->left->left->val;
                    if(curr->left->right)
                        sum += curr->left->right->val;
                }
                if(curr->right){
                    if(curr->right->left)
                        sum += curr->right->left->val;
                    if(curr->right->right)
                        sum += curr->right->right->val;
                }
            }
            
            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
        return sum;
    }
};