class Solution {
public:
    string countAndSay(int n) {
        queue<int> a;
        a.push(1);
        a.push(-1);
        n --;
        while ( n --) {
            int num = a.front();
            int cnt = 0;
            while (a.front() != -1) {
                if (a.front() == num) {
                    cnt ++;
                    a.pop();
                    if (a.front() == -1) {
                        a.push(num);
                        a.push(cnt);
                        a.pop();
                        break;
                    }
                }
                else {
                    a.push(num);
                    a.push(cnt);
                
                    num = a.front();
                    cnt = 0;
                }
            }
            
            a.push(-1);
        }
        
        string result = "";
        while (a.front() != -1) {
            int c = a.front();
            a.pop();
            result = to_string(c) + result;
        }
        
        return result;
    }
};