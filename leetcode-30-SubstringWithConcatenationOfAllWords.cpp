class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> pat_map;
        vector<int> result;
        for (int i = 0; i < words.size(); i ++) {
            if (pat_map.find(words[i]) != pat_map.end())
                pat_map[words[i]] = pat_map[words[i]] + 1;
            else 
                pat_map[words[i]] = 1;
        }
        
        int m = words.size();
        int n = s.length();
        int len = words[0].length();
        int len_p = len * m;
        
        for (int i = 0; i + len_p <= n; i ++) {
            unordered_map<string, int> temp(pat_map);
            int cnt = 0;
            int j = i;
            while (cnt < m) {
                string cur = s.substr(j, len);
                if (temp.find(cur) != temp.end() && temp[cur] > 0) {
                    temp[cur] = temp[cur] - 1;
                }
                else {
                    break;
                }
                
                j += len;
                cnt ++;
            }
            
            if (cnt == m)
                result.push_back(i);
        }
        
        return result;
    }
};