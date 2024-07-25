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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0 ; i < size ; i++){  
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);  
                if(temp->right) q.push(temp->right); 
                level.push_back(temp->val);
            }
            if(flag){
                reverse(level.begin(), level.end());
            }
            flag = !flag;
            ans.push_back(level);
        } 
    return ans;    
    }
};