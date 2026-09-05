class Solution {
public:
    int reverse(int x) {
        long long res=0;
        //int sign= (x<0)?-1:1;
        while (x!=0) {
            int num= x%10;
            x/=10;
            res= (res*10)+num;
        } 
        if (res>INT_MAX || res<INT_MIN) return 0;
        return (int)res;
    }
};