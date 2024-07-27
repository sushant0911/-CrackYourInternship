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
    bool isLeftLeaf(TreeNode* root){
        if(root == nullptr) return false;
        if(!root->left && !root->right) return true;
        return false;
    }
    
    void findSum(TreeNode* root, int &sum){
        if(root ==  nullptr) return;
        if(isLeftLeaf(root->left)) sum += root->left->val;
        findSum(root->left,sum);
        findSum(root->right,sum);
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0 ;
        findSum(root,sum);
        return sum;
    }
};