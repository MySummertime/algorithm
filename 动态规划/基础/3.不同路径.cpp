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
    // TLE
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
    // memorized dfs
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(m, n, vis, 0, 0);
    }

private:
    int dfs(const int& m, const int& n, vector<vector<int>>& vis, int i, int j) {
        if (i >= m || j >= n)   return 0;
        if (vis[i][j] > 0)  return vis[i][j];
        if (i == m - 1 && j == n - 1) {
            vis[i][j] = 1;
            return 1;
        }
        int ans = dfs(m, n, vis, i + 1, j) + dfs(m, n, vis, i, j + 1);
        vis[i][j] = ans;
        return ans;
    }
};


class Solution3 {
public:
    // dynamic programming
    // Time: O(m*n)
    // Space: O(m*n)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};


class Solution4 {
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