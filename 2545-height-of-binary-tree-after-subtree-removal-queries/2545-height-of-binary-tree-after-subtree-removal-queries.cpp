/**
 * Definition for a binary tree root.
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
    int currentMaxHeight = 0;
    int heights[100001];
    void leftToRight(TreeNode* root, int currentHeight) {
        if (!root) {
            return;
        }
        // max height till this point, means if this root is removed, the height
        // returned to query will be currentHeight
        heights[root->val] = currentMaxHeight;
        // Update the current max height
        currentMaxHeight = max(currentHeight, currentMaxHeight);
        // Traverse to left and right subtree
        leftToRight(root->left, 1 + currentHeight);
        leftToRight(root->right, 1 + currentHeight);
    }
    void rightToLeft(TreeNode* root, int currentHeight) {
        if (!root) {
            return;
        }
        //Update only if the current height stored is smaller 
        heights[root->val] = max(heights[root->val], currentMaxHeight);
        // Update the current max height
        currentMaxHeight = max(currentHeight, currentMaxHeight);
        // Traverse to left and right subtree
        rightToLeft(root->right, 1 + currentHeight);
        rightToLeft(root->left, 1 + currentHeight);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        leftToRight(root, 0);
        currentMaxHeight = 0;
        rightToLeft(root, 0);
        for (int query : queries) {
            ans.push_back(heights[query]);
        }
        return ans;
    }
};