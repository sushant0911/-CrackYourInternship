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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        stack<TreeNode*> path;
        stack<int> pathSum;
        path.push(root);
        pathSum.push(root->val);
        while(!path.empty()){
            TreeNode* temp = path.top();
            path.pop();
            int tempVal = pathSum.top();
            pathSum.pop();
            
            if(temp->left == nullptr && temp->right == nullptr && tempVal == targetSum){
                return true;
            }
            
            if(temp->right != nullptr){
                path.push(temp->right);
                pathSum.push(temp->right->val + tempVal);
            }
            
            if(temp->left != nullptr){
                path.push(temp->left);
                pathSum.push(temp->left->val + tempVal);
            }
        }
        return false;
    }
};