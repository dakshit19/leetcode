class Solution {
public:
    long long solve(long long start, long long step, long long size, bool left) {
        if (size == 1)
            return start;
        if (!left && size % 2 == 0)
            start += step;

        return solve(start, step*2, (size+1)/2, !left);
    }

    long long lastInteger(long long n) {
        return solve(1, 1, n, true);
    }
};