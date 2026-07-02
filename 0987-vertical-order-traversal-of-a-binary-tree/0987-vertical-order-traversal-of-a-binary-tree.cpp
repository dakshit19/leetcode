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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int /*vertical*/,int /*level*/>>> q;
        map<int /*vertical*/, map<int/*level*/, multiset<int>>> nodes; 
        q.push({root, {0,0}});

        while(!q.empty()){
            auto element = q.front();
            q.pop();
            TreeNode* currNode= element.first;
            int x= element.second.first;
            int y= element.second.second;
            nodes[x][y].insert(currNode->val);
            if (currNode->left) {
                q.push({currNode->left, {x-1, y+1}});
            }
            if (currNode->right) {
                q.push({currNode->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> res;
        for (auto p: nodes){
            vector<int> col;
            for (auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};