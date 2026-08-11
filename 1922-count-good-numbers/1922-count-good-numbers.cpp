class Solution {
public:
    const long long mod= 1e9 +7;

    long long expo(long long a, long long b) { // a^b
        if (b==0) return 1;

        if (b%2==0) return expo((a*a)%mod, b/2);
        else return a*expo((a*a)%mod, b/2)%mod;
    }

    int countGoodNumbers(long long n) {
        long long even= (n+1)/2;
        long long odd= (n/2);

        return (expo(5, even)* expo(4, odd))%mod;
    }
};