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
    bool isBalanced(TreeNode* root) {
        // If checkHeight returns -1, the tree is unbalanced
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        // Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        // Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;

        // If current node is unbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Otherwise, return the actual height of this node
        return max(leftHeight, rightHeight) + 1;
    }
};