class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<int> map(128, 0);
        for (auto c: t)
            map[c] ++;
            
        int begin = 0, end = 0, cnt = m, head = 0, last = 0;
        int dis = INT_MAX;
        while (end < n) {
            if (map[s[end ++]] -- > 0) cnt --;
            //valid 
            while (cnt == 0) {
                if (end - begin < dis) dis = (last = end) - (head = begin);
                if (map[s[begin ++]] ++ == 0) cnt ++; // set invalid
            }
        }
        
        return dis == INT_MAX ? "" : s.substr(head, dis);
    }
};