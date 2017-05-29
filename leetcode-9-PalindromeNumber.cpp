class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || ((x % 10) == 0 && x != 0))
            return false;
        int plain = 0;
        int temp = x < 0 ? -x: x;
        while (x != 0) {
            plain = plain * 10 + x % 10;
            x = x / 10;
        }
        
        return plain == temp;
    }
};