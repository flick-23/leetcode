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
    void deleteNodes(TreeNode*& root, unordered_map<int,int>&mpp, vector<TreeNode*>& ans){
        if(!root)
            return;
        if (root->left) 
            deleteNodes(root->left, mpp, ans);
        if (root->right) 
            deleteNodes(root->right, mpp, ans);
        if(mpp.find(root->val) != mpp.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mpp;
        for(int i = 0; i < to_delete.size(); i++){
            mpp[to_delete[i]]++;
        }
        vector<TreeNode*>ans;
        deleteNodes(root,mpp,ans);
        if(root)
            ans.push_back(root);
        return ans;
    }
};