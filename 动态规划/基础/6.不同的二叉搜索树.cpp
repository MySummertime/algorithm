/*96.不同的二叉搜索树
https://leetcode.cn/problems/unique-binary-search-trees/
*/

#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming
    // Time: O(n^2)
    // Space: O(n)
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};