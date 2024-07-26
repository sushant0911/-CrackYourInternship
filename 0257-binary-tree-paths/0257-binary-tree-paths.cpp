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
    void preOrder(vector<string> &ans, string s, TreeNode* root){
        if(!root) return;
        
        s += to_string(root->val);
        s += "->";
        if(!root->left && !root->right){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
        }
        
        preOrder(ans,s,root->left);
        preOrder(ans,s,root->right);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        preOrder(ans,s,root);
        return ans;
    }
};