class Solution {
public:
    void helper(int node,const vector<vector<int>> &mat, vector<bool> &vis) {
        vis[node]= true;
        for (int j=0; j<vis.size(); j++) {
            if (mat[node][j]== 1 && vis[j]==false) {
                helper(j, mat, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int v= isConnected.size();
        vector<bool> vis(v, false);
        int province=0;

        for (int i=0; i<v; i++) {
            if (vis[i]==false) {
                province++;
                helper(i, isConnected, vis);
            }
        }

        return province;
    }
};