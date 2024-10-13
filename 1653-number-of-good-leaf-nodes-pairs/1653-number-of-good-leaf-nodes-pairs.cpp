/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) {
            return;
        }
        if (root->left) {
            parent[root->left] = root;
        }
        if (root->right) {
            parent[root->right] = root;
        }
        markParents(root->left, parent);
        markParents(root->right, parent);
    }
    void moveOut(int& count, int distance, TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<pair<TreeNode*, pair<TreeNode*, int>>> q;
        q.push({root, {root, 0}});
        while (!q.empty()) {
            TreeNode* previous = q.front().first;
            TreeNode* node = q.front().second.first;
            TreeNode* up = parent.count(node) == 0 ? NULL : parent[node];
            int d = q.front().second.second;
            q.pop();

            if (d <= distance && !node->left && !node->right && d > 0) {
                count++;
            }
            if (node->left && node->left != previous && 1 + d <= distance) {
                q.push({node, {node->left, 1 + d}});
            }
            if (node->right && node->right != previous && 1 + d <= distance) {
                q.push({node, {node->right, 1 + d}});
            }
            if (up && up != previous && 1 + d <= distance) {
                q.push({node, {up, 1 + d}});
            }
        }
    }
    void dfs(int& count, int distance, TreeNode* root,
             unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) {
            return;
        }
        dfs(count, distance, root->left, parent);
        dfs(count, distance, root->right, parent);
        if (!root->left && !root->right) {
            moveOut(count, distance, root, parent);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        // child, parent
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        int count = 0;
        dfs(count, distance, root, parent);
        return count/2;
    }
};