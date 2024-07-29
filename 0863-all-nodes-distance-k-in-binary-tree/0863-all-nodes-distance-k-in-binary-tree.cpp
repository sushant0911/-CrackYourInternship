/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
class Solution {
    void markParent(unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(parent_track, root);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_distance = 0;
        while(!q.empty()){
            int n = q.size();
            if(curr_distance == k) break;
            for(int i = 0 ; i < n ; i++){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent_track.find(curr) != parent_track.end() && !visited[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
            }
        }
        curr_distance++;
    }
    vector<int> result;
    while(!q.empty()){
        result.push_back(q.front()->val); 
        q.pop();
    }
    return result;
}
};