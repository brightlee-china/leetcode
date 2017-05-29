class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        
        string *lines = new string[numRows];
        int flg = 1;
        int row = 0;
        for (int i = 0; i < s.length(); i ++, row += flg) {
            lines[row].push_back(s[i]);
            if (row == 0)
                flg = 1;
            
            if (row == numRows - 1) 
                flg = -1;
        }
        
        string result;
        for (int i = 0; i < numRows; i ++) {
            result += lines[i];
        }
        
        return result;
    }
};