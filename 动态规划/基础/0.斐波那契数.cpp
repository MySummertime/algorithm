/*509. Fibonacci Number
https://leetcode.cn/problems/fibonacci-number/
*/

#include <vector>

using std::vector;


class Solution1 {
public:
    // dynamic programming
    // Time: O(n)
    // Space: O(n)
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


class Solution2 {
public:
    // dynamic programming
    // Time: O(n)
    // Space: O(1)
    int fib(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0, dp[1] = 1;
        for (int i = 2, sum; i <= n; ++i) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};


class Solution3 {
public:
    // recursion
    // Time: O(2^n)
    // Space: O(n)
    int fib(int n) {
        return recursion(n);
    }

private:
    int recursion(int n) {
        if (n <= 1) return n;
        return recursion(n - 1) + recursion(n - 2);
    }
};