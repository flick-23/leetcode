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
        vector<vector<int>>ans;
        if(!root)
            return ans; 
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int row = it.second;

            mpp[row].push_back(node->val);
            if(node->left){
                q.push({node->left,row+1});
            }
            if(node->right){
                q.push({node->right,row+1});
            }
        }
        for(auto it : mpp){
            vector<int>temp = it.second;
            if(it.first % 2 != 0){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};