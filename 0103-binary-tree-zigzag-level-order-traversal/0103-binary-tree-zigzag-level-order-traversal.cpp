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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return {};

        bool flag= false;
        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            int n= q.size();
            stack<int> st;
            vector<int> level;

            for(int i=0; i<n; i++){
                TreeNode* curr= q.front();
                q.pop();

                if (flag) st.push(curr->val);
                else level.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            
            while(!st.empty()){
                level.push_back(st.top());
                st.pop();
            }

            flag= !flag;
            res.push_back(level);
        }

        return res;
    }
};