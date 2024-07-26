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
    int minimumDiff = INT_MAX;
    int prev = INT_MAX;
    
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return minimumDiff;
        getMinimumDifference(root->left);
        
        // Process Root
        if(prev != INT_MAX){
            minimumDiff = min(minimumDiff,root->val - prev);
        }
        if(root != nullptr){
            prev = root->val;
        }
        
        getMinimumDifference(root->right);
        return minimumDiff;
    }
};