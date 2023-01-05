/*70. Climbing Stairs
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