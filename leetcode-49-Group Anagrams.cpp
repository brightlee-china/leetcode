class Solution {
public:
    string sorted_word(string &s) {
        int a[26] = {0};
        for (int i = 0; i < s.length(); i ++) {
            a[s[i] - 'a'] ++;
        }
        
        string result(s.length(), 'a');
        int p = 0;
        for (int i = 0; i < 26; i ++) {
            for (int j = 0; j < a[i]; j ++) {
                result[p ++] += i;
            }
        }
        
        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        unordered_map<string, vector<string> > u_m;
        for (int i = 0; i < strs.size(); i ++) {
            string index = sorted_word(strs[i]);
            u_m[index].push_back(strs[i]);
        }
        
        unordered_map<string, vector<string>>::iterator it;
        for (it = u_m.begin(); it != u_m.end(); it ++) {
            result.push_back(it -> second);
        }
        
        return result;
    }
};