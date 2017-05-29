class Solution {
public:
    int romanToInt(string s) {
        int value[26] = {0};
        value['I' - 'A'] = 1;
        value['V' - 'A'] = 5;
        value['X' - 'A'] = 10;
        value['L' - 'A'] = 50;
        value['C' - 'A'] = 100;
        value['D' - 'A'] = 500;
        value['M' - 'A'] = 1000;
        
        int result = 0;
        int index = 0;
        while (index < s.length()) {
            if (index == s.length() - 1)
                result += value[s[index] - 'A'];
            else {
                if (value[s[index] - 'A'] < value[s[index + 1] - 'A']) 
                    result -= value[s[index] - 'A'];
                else 
                    result += value[s[index] - 'A'];
            }
            
            index ++;
        }
        
        return result;
    }
};