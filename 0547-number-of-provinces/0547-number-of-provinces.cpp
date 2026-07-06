class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // bfs solution
        int v= isConnected.size();
        vector<bool> visited(v, false);
        queue<int> q;
        int province= 0;

        for (int i=0; i<v; i++){
            if (visited[i]) continue;
            else {
                visited[i]= true;
                province++;
                q.push(i); // node added to queue
                
                while(!q.empty()) {
                    int node= q.front();
                    q.pop();
                    visited[i]= true;

                    for (int j=0; j<v; j++) {
                        if (!visited[j] && isConnected[node][j]) {
                            visited[j]= true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        
        return province;
    }
};