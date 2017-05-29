class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        if (n < m)
            return addBinary(b, a);
        
        string result(n + 1, '0');
        int in = 0;
        int i = n - 1, j = m - 1;
        int index = n;
        while (i >= 0) {
            int cur = in;
            if (j >= 0)
                cur = cur + a[i --] - '0' + b[j --] - '0';
            else 
                cur = cur + a[i --] - '0';
            
            result[n --] = cur == 3 || cur == 1 ? '1' : '0';
            in = cur > 1 ? 1 : 0;
        }
        
        if (in == 1) {
            result[0] = '1';
            return result;
        }
        else {
            result.erase(0, 1);
            return result;
        }
    }
};