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
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;

        int left= 1+ depth(node->left);
        int right= 1+ depth(node->right);
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        if (abs(depth(root->left)-depth(root->right))>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};