class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int flg = 1;
        int i = 0;
        while (i < str.length() && str[i] == ' ') i ++;
        if (str[i] == '+') {
            flg = 1;
            i ++;
        }
        else if (str[i] == '-') {
            flg = -1;
            i ++;
        }
        
        int cnt = 0;
        for (; i < str.length() && str[i] >= '0' && str[i] <= '9'; i ++, cnt ++) {
            result = result * 10 + str[i] - '0';   
        }
        
        result *= flg;
        
        if (cnt > 11) {
            if (flg == 1)
                return (1 << 31) - 1;
            else
                return (1 << 31) * -1;
        }
        
        if (result < (-1 * (1 << 31)))
            return -1 * (1 << 31);
        if (result > (1 << 31) - 1)
            return (1 << 31) - 1;
        
        return result;
    }
};