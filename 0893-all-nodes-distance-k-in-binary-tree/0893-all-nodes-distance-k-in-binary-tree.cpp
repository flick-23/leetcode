/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* node, map<TreeNode*,TreeNode*>&mpp){
        if(!node){
            return;
        }
        if(node->left){
            mpp[node->left] = node;
        }
        if(node->right){
            mpp[node->right] = node;
        }
        markParents(node->left,mpp);
        markParents(node->right,mpp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        map<int,int>visited;
        markParents(root,parent);
        int distance = 0;
        //<node, distance>
        queue<pair<TreeNode*,int>>q;
        vector<int>ans;
        q.push({target,0});
        while(!q.empty() && distance<=k){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            distance = it.second;
            if(visited[node->val] == 1){
                continue;
            }
            TreeNode* up = NULL;
            if(node != root){
                up = parent[node];
            }
            visited[node->val]=1;
            if(distance == k){
                ans.push_back(node->val);
            }
            if(node->left != NULL){
                q.push({node->left,1+distance});
            }
            if(node->right != NULL){
                q.push({node->right,1+distance});
            }
            if(up != NULL){
                q.push({up,1+distance});
            }
        }   
        return ans;
    }
};