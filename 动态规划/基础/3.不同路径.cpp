/*62.不同路径
https://leetcode.cn/problems/unique-paths/
*/

#include <vector>
#include <cstdio>
#include <ctime>

using std::vector;


class Solution1 {
public:
    // dfs
    int uniquePaths(int m, int n) {
        return dfs(1, 1, m, n);
    }

private:
    int dfs(int i, int j, const int &m, const int &n) {
        if (i > m || j > n)   return 0; // out of bounds
        if (i == m && j == n)   return 1;   // find a path
        return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
    }
};


class Solution2 {
public:
    // dynamic programming
    // Time: O(m*n)
    // Space: O(n)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
                printf("j=%d: dp[j]=%d, ", j, dp[j]);
            }
        }
        return dp[n - 1];
    }
};