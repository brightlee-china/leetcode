class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        int flg = x < 0 ? -1 : 1;
        x *= flg;
        while (x != 0) {
            result = result * 10 + x % 10;
            x = x / 10;
        }
    
        result *= flg;
        
        if (result <= ((1 << 31) - 1) && result >= (-1 * (1 << 31)))
            return (int)result;
        else 
            return 0;
    }
};