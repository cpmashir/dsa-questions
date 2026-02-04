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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int, TreeNode*> helper(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = helper(node->left);
        auto right = helper(node->right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        if (leftDepth == rightDepth) {
            return {leftDepth + 1, node};
        }
        
        if (leftDepth > rightDepth) {
            return {leftDepth + 1, left.second};
        }
        
        return {rightDepth + 1, right.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;
    }
};