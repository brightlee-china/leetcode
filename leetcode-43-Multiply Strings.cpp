class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "0";
        int len1 = num1.length();
        int len2 = num2.length();
        for (int i = len1 - 1; i >= 0; i --) {
            int in = 0;
            string temp = "";
            if (num1[i] == '0')
                temp = "0";
            else {
                for (int j = len2 - 1; j >= 0; j --) {
                    int a = num2[j] - '0';
                    int b = num1[i] - '0';
                    int c = in + a * b;
                    char d = c % 10 + '0';
                    in = c / 10;
                    temp.append(1, d);
                }
            }
            
            if (in > 0) {
                char d = in + '0';
                temp.append(1, d);
            }
            
            int index = len1 - i - 1;
            // result += temp
            in = 0;
            int l = result.length();
            for (int k = 0; k < temp.length(); k ++) {
                if (index < l) {
                    int a = result[index] - '0';
                    int b = temp[k] - '0';
                    int c = a + b + in;
                    char d = c % 10 + '0';
                    in = c / 10;
                    result[index ++] = d;
                }
                else {
                    int b = temp[k] - '0';
                    int c = b + in;
                    char d = c % 10 + '0';
                    in = c / 10;
                    result.append(1, d);
                }
            }
            
            if (in > 0) {
                char d = in + '0';
                result.append(1, d);
            }
        }
        
        string res = "";
        int i = result.length() - 1;
        for (; i >= 0; i --) {
            if (result[i] != '0' || i == 0)
                break;
        } 
        
        for (; i >= 0; i --) {
            res.append(1, result[i]);
        }
        
        return res;
    }
};