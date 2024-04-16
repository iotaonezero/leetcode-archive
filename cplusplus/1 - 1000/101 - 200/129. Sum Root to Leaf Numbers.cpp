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

//

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> st;
        int sum = 0;

        st.push({root, root->val});
        while(!st.empty()) {
            std::pair<TreeNode*, int> p = st.top();
            TreeNode* p1 = p.first;
            int p2 = p.second;
            
            st.pop();

            if(p1->left == NULL && p1->right == NULL)
                sum += p2;

            if(p1->left != NULL)
                st.push({p1->left, p2*10 + p1->left->val});

            if(p1->right != NULL)
                st.push({p1->right, p2*10 + p1->right->val});
        }

        return sum;
    }
};
