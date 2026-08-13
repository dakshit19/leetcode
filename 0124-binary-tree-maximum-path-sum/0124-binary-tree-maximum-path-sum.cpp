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
    int maxim= INT_MIN;

    int solve(TreeNode* node) {
        if (node== nullptr) return 0;
        int leftsum= max(0, solve(node->left));
        int rightsum= max(0, solve(node->right));
        maxim= max(maxim, node->val+ leftsum+ rightsum);

        return node->val+ max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxim;
    }
};