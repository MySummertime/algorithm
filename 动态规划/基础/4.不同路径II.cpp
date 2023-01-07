/*63.不同路径II
https://leetcode.cn/problems/unique-paths-ii/
*/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution1 {
public:
    // memorized dfs
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(obstacleGrid, vis, 0, 0, m, n);
    }

private:
    int dfs(const vector<vector<int>>& graph, vector<vector<int>>& vis, int i, int j, const int& m, const int& n) {
        if (i >= m || j >= n)   return 0;
        if (graph[i][j] == 1)   return 0;
        if (vis[i][j] > 0)  return vis[i][j];
        if (i == m - 1 && j == n - 1) {
            vis[i][j] = 1;
            return 1;
        }
        int ans = dfs(graph, vis, i + 1, j, m, n) + dfs(graph, vis, i, j + 1, m, n);
        vis[i][j] = ans;
        return ans;
    }
};



class Solution2 {
public:
    // dynamic programming
    // Time: O(m*n)
    // Space: O(m*n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
            return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i)  dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)  dp[0][j] = 1;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};



class Solution3 {
public:
    // dynamic programming
    // Time: O(m*n)
    // Space: O(n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
            return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int j = 1; j < n && obstacleGrid[0][j] == 0; ++j) {
            dp[j] = dp[j - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else if (j) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};