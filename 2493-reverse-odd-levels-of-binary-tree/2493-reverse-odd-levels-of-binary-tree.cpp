class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root; // Handle edge case
        
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelNodes;

            // Collect nodes at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse values at the odd levels
            if (reverse) {
                int left = 0, right = levelNodes.size() - 1;
                while (left < right) {
                    swap(levelNodes[left]->val, levelNodes[right]->val);
                    ++left;
                    --right;
                }
            }
            
            reverse = !reverse; // Toggle reverse for the next level
        }

        return root;
    }
};
