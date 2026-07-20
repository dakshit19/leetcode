class Solution {
public:
    void dfs(const vector<vector<int>>& isConnected,
             vector<bool>& visited, int node) {

        visited[node] = true;

        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            if (isConnected[node][neighbour] && !visited[neighbour]) {
                dfs(isConnected, visited, neighbour);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }
};