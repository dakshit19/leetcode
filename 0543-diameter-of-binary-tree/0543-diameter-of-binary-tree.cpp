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
    int height(TreeNode* node){
        if (node == nullptr) return 0;
        int lh= height(node->left);
        int rh= height(node->right);

        return 1+ max(lh,rh);
    }

    int max_ht= INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int lh= height(root->left);
        int rh= height(root->right);
        max_ht= max(max_ht, lh+rh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return max_ht;
    }
};