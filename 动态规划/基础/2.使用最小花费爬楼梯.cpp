/*746. Min Cost Climbing Stairs
https://leetcode.cn/problems/min-cost-climbing-stairs/
*/
#include <vector>

using std::vector;


class Solution1 {
public:
    // dynamic programming
    // Time: O(n)
    // Space: O(n)
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len + 1);
        dp[0] = 0, dp[1] = 0;
        for (int i = 2; i <= len; ++i) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[len];
    }
};

class Solution2 {
public:
    // dynamic programming
    // Time: O(n)
    // Space: O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] {0, 0};
        for (int i = 2, tmp, len = cost.size(); i <= len; ++i) {
            tmp = std::min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
};

