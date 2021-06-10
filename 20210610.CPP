// https://leetcode-cn.com/problems/coin-change-2/
// leetcode 518

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 完全背包问题
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
//     for (int i = 0; i <= n; ++i)
//         dp[i][0] = 1;
//     for (int i = 1; i <= n; ++i)
//         for (int j = 1; j <= amount; ++j) {
//             if (j - coins[i-1] >= 0) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
//             else dp[i][j] = dp[i-1][j];
//         }
//     return dp[n][amount];
// }


// 简化空间复杂度
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= amount; ++j) {
            if (j - coins[i-1] >= 0) dp[j] = dp[j] + dp[j-coins[i-1]];
        }
    return dp[amount];
}

int main()
{
    return 0;
}