class Solution {
public:
    typedef long long LL;
    LL div(LL a, LL b) {
        if (a < b)
            return 0;
        
        LL m = 1;
        LL temp_b = b;
        while (a > (temp_b << 1)) {
            temp_b = temp_b << 1;
            m = m << 1;
        }
        
        return m + div(a - temp_b, b);
    }

    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        
        LL a = (LL) dividend;
        LL b = (LL) divisor;
        
        LL c = abs(a);
        LL d = abs(b);
        
        LL result = div(c, d);
        
        if (a < 0 && b > 0)
            result = 0 - result;
        if (a > 0 && b < 0)
            result = 0 - result;
            
        if (result < INT_MIN || result > INT_MAX)
            return INT_MAX;
        
        return (int)result;
    }
};