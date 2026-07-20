class Solution {
public:
    void dfs(vector<vector<int>> isConnected, vector<bool> &visited, int i) {
        visited[i]= true;

        for (int neighbour=0; neighbour<isConnected[i].size(); neighbour++) {
            if (!visited[neighbour] && isConnected[i][neighbour]==1) {
                dfs(isConnected, visited, neighbour);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v= isConnected.size();
        vector<bool> visited(v, false);
        int count=0;

        int node= 0;
        for (int i=0; i<v; i++) {
            if (!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};