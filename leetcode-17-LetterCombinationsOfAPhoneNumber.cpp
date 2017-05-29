class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> number_word = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.empty())
            return result;
        result.push_back("");
        
        for (int i = 0; i < digits.size(); i ++) {
            int d = digits[i] - '0';
            if (d < 0 || d > 9) break;
            vector<string> temp;
            for (int j = 0; j < number_word[d].size(); j ++) {
                for (int k = 0; k < result.size(); k ++) {
                    temp.push_back(result[k] + number_word[d][j]);
                }
            }
            
            result.swap(temp);
        }
        
        return result;
    }
};