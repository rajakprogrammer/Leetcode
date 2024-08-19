class Solution {
public:
    int minSteps(int n) {
        // Create a DP array to store minimum steps for each i
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;  // maximum number of operations is i (e.g., all paste operations)
            for (int j = 1; j <= i / 2; ++j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }
        
        return dp[n];
    }
};
