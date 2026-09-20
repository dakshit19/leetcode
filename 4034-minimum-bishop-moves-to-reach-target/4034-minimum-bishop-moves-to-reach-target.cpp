class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sx= source[0];
        int sy= source[1];
        int tx= target[0];
        int ty= target[1];

        if (sx==tx && sy==ty) return 0;
        else if (abs(sx-tx)==abs(ty-sy)) return 1;
        else if ((sx+sy)%2!=(tx+ty)%2) return -1;;

        return 2;
    }
};