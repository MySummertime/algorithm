/*70. Climbing Stairs
https://leetcode.cn/problems/climbing-stairs/
*/
#include <vector>

using std::vector;


class Solution1 {
public:
    // dynamic programming
    // Time: O(n)
    // Space: O(n)
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};


class Solution2 {
public:
    // dynamic programming
    // Time: O(n)
    // Space: O(1)
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp[3];
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for (int i = 3, sum; i <= n; ++i) {
            sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};


class Solution3 {
public:
    // dynamic programming(完全背包)
    // Time: O(m*n)
    // Space: O(n)
    int climbStairs(int n, int m = 2) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};