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
    bool symmetry(TreeNode* left, TreeNode* right){
        if(!left || !right){
            return left == right;
        }
        return (left->val == right->val) && symmetry(left->left, right->right) && symmetry(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        bool ans = symmetry(root->left, root->right);
        return ans;
    }
};