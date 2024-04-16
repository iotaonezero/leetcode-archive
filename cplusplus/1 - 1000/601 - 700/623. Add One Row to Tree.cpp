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
    void dfs(TreeNode* root, int val, int depth, int d) {
        if(root == NULL)
            return;
        
        if(d == depth) {
            TreeNode* tmpL = root->left;
            TreeNode* tmpR = root->right;

            TreeNode* tL = new TreeNode();
            tL->val = val;
            root->left = tL; tL->left = tmpL; tL->right = NULL;

            TreeNode* tR = new TreeNode();
            tR->val = val;
            root->right = tR; tR->left = NULL; tR->right = tmpR;

            return;
        }

        dfs(root->left, val, depth, d + 1);
        dfs(root->right, val, depth, d + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* tree = new TreeNode();
            tree->val = val;
            tree->left = root; tree->right = NULL;
            return tree;
        }

        dfs(root, val, depth, 2);
        
        return root;
    }
};
