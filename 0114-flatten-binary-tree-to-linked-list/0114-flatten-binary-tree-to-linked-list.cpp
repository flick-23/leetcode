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
    // N L R
    void preorder(TreeNode* root, vector<TreeNode*>& tree) {
        if (!root)
            return;
        TreeNode* node = new TreeNode(root->val);
        tree.push_back(node);
        preorder(root->left, tree);
        preorder(root->right, tree);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> tree;
        preorder(root, tree);
        int i = 1;
        while (i < tree.size()) {
            root->left = NULL;
            root->right = tree[i];
            root = root->right;
            i++;
        }
    }
};