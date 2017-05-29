class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
            return "";
        
        vector<string> stk;
        stringstream line(path);
        string temp, result;
        while (getline(line, temp, '/')) {
            if (temp == "" || temp == ".") 
                continue;
            
            if (temp == ".." && !stk.empty()) 
                stk.pop_back();
            else if (temp != "..")
                stk.push_back(temp);
        }
        
        for (auto str: stk)
            result += "/" + str;
        
        return result.empty() ? "/" : result;
    }
};  