class Solution {
public:
    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftht= 1+ height(node->left);
        int rightht= 1+ height(node->right);

        return max(leftht, rightht);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int currentDia= height(root->left) + height(root->right);

        int leftDia= diameterOfBinaryTree(root->left);
        int rightDia= diameterOfBinaryTree(root->right);

        return max(currentDia, max(leftDia, rightDia));
    }
};