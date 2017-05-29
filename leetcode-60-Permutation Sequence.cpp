class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        int *vis = new int[n + 1];
        memset(vis, 0, sizeof(int) * (n + 1));
        for (int h = 1; h <= n; h ++) {
            int cnt = 1;
            int j = 1;
            while (j <= n - h)
                cnt *= j ++;
            for (int i = 1; i <= n; i ++) {
                if (!vis[i]) {
                    if (k <= cnt) {
                        result.append(1, i + '0');
                        vis[i] = 1;
                        break;
                    }
                    else {
                        k -= cnt;
                    }
                }
            }
        }

        return result;
    }
};