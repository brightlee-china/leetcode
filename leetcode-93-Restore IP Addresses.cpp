class Solution {
public:
    void solve(vector<string> &result, vector<string> &cur, string &s, int start, int cnt) {
        int e = s.size() - 4 + cnt;
        if (start >= e)
                return;

        if (cnt == 4) {
            string c = s.substr(start);
            if (c.size() > 3 || atoi(c.c_str()) > 255)
                return;
            if (c[0] == '0' && c.size() > 1)
                return;

            string temp = cur[0];
            temp += "." + cur[1];
            temp += "." + cur[2];
            temp += "." + c;
            result.push_back(temp);
            return;
        }

        if (s[start] == '0'){
            cur.push_back("0");
            solve(result, cur, s, start + 1, cnt + 1);
            cur.pop_back();
            return;
        }

        for (int i = 1; i <= 3; i ++) {
            string a = s.substr(start, i);
            if (atoi(a.c_str()) > 255)
                break;

            cur.push_back(a);
            solve(result, cur, s, start + i, cnt + 1);
            cur.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> cur;
        solve(result, cur, s, 0, 1);
        return result;
    }
};