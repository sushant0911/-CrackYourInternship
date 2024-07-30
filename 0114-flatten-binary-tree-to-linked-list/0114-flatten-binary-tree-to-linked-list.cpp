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
    // TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        // if(root == nullptr) return;
        // flatten(root->right);
        // flatten(root->left);
        // root->right = prev;
        // root->left = nullptr;
        // prev = root;
        // return;
        
        if(root == nullptr) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()) curr->right = st.top();
            curr->left = nullptr;
        }
        return;
    }
};