class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        
        int i = 2;
        int f1 = 1;
        int f2 = 1;
        while (i <= n) {
            int temp = f1;
            f1 = f2;
            f2 = temp + f2;
            i ++;
        }
        
        return f2;
    }
};