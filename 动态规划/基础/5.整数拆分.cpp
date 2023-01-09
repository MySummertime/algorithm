/*343.整数拆分
https://leetcode.cn/problems/integer-break/
*/

#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming
    // Time: O(n^2)
    // Space: O(n)
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i - j; ++j) {
                dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};