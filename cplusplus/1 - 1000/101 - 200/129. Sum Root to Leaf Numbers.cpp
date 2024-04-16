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
private:
    int compute(TreeNode* root, int sum) {
        if(root->left != NULL && root->right != NULL)
            return compute(root->left, (sum + root->val) * 10) + 
                   compute(root->right, (sum + root->val) * 10);
        
        else if(root->left != NULL)
            return compute(root->left, (sum + root->val) * 10);
        
        else if(root->right != NULL)
            return compute(root->right, (sum + root->val) * 10);

        return sum + root->val;
    }
    
public:
    int sumNumbers(TreeNode* root) {
        if(root->left != NULL && root->right != NULL)
            return compute(root->left, root->val * 10) + 
                   compute(root->right, root->val * 10);
        
        else if(root->left != NULL)
            return compute(root->left, root->val * 10);
        
        else if(root->right != NULL)
            return compute(root->right, root->val * 10);

        return root->val;
    }
};
