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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> nums(3);
        vector<int> arr;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int level = it.first;
            TreeNode* node = it.second;
            if (nums.size() < 2 * level && level != 0) {
                nums.resize(2 * level);
            }
            nums[level].push_back(node->val);
            if (node->left)
                q.push({level + 1, node->left});
            if (node->right)
                q.push({level + 1, node->right});
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 != 0) {
                reverse(nums[i].begin(),nums[i].end());
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                arr.push_back(nums[i][j]);
            }
        }
        q.push({0, root});
        int i = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int level = it.first;
            TreeNode* node = it.second;
            node->val = arr[i++];
            if (node->left)
                q.push({level + 1, node->left});
            if (node->right)
                q.push({level + 1, node->right});
        }

        return root;
    }
};