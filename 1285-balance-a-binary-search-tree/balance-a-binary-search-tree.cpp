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
    vector<TreeNode*> nodes;

    TreeNode* balanceBST(TreeNode* root) {
        // 1. Collect nodes in sorted order
        storeNodes(root);
        
        // 2. Build balanced tree from sorted vector
        return buildTree(0, nodes.size() - 1);
    }

private:
    void storeNodes(TreeNode* root) {
        if (!root) return;
        storeNodes(root->left);
        nodes.push_back(root);
        storeNodes(root->right);
    }

    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;

        // Pick the middle node to ensure balance
        int mid = start + (end - start) / 2;
        TreeNode* node = nodes[mid];

        // Recursively build subtrees
        node->left = buildTree(start, mid - 1);
        node->right = buildTree(mid + 1, end);

        return node;
    }
};