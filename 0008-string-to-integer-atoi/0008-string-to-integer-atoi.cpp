class Solution {
public:
    long long convert(int i, const string &s, long long res, long long &limit) {
        if (i>=s.size() || !isdigit(s[i])) return res;
        //if (res>= INT_MAX) return INT_MAX;

        int digit= s[i]-'0';
        //check limit
        if (res> (limit-digit)/10) return limit;

        //convert only useful
        return convert(i+1, s, res*10+ digit, limit);
    }

    int myAtoi(string s) {
        int i=0;
        // check whitespaces
        while (s[i]==' ') i++;

        //check sign
        int sign=+1;
        if (i<s.size() && s[i]=='-') {
            i++;
            sign=-1;
        }  else if (i<s.size() && s[i]=='+') {
            i++;
        }

        long long limit; //marking limits
        if (sign == -1) limit = 2147483648LL; 
        else limit = 2147483647LL;

        long long res= convert(i, s, 0, limit);
        return sign*res;
    }
};