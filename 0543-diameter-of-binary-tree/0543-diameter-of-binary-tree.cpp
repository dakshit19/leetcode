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
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> s;
        unordered_map<TreeNode*, int /* diameter*/> m;
        if (root) s.push(root);
        int res=0;
        
        while(!s.empty()){
            TreeNode* curr= s.top();
            if (curr->left && m.find(curr->left)==m.end()){
                s.push(curr->left);
            } else if (curr->right && m.find(curr->right)==m.end()){
                s.push(curr->right);
            } else {
                s.pop();
                int leftHeight = curr->left ? m[curr->left] : 0;
                int rightHeight = curr->right ? m[curr->right] : 0;
                // Store height of current node
                m[curr] = 1 + max(leftHeight, rightHeight);
                // Update diameter
                res = max(res, leftHeight + rightHeight);
            }
        }
        
        return res;
    }
};