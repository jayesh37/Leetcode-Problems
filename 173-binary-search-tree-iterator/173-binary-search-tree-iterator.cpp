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
class BSTIterator {
public:
    vector<int> v;
    int i=-1;
    int n;
    BSTIterator(TreeNode* root) {
        getinorder(root);
        n=v.size();
    }
    
    void getinorder(TreeNode *root)
    {
        if(root==NULL)  return;
        
        getinorder(root->left);
        v.push_back(root->val);
        getinorder(root->right);
    }
    
    int next() {
        i++;
        return v[i];
    }
    
    bool hasNext() {
        if(i+1<n)
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */