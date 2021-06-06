// https://leetcode-cn.com/problems/ones-and-zeroes/
// leetcode 474


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 传统0-1背包问题的升级版，基本上相同的做法，只是增加了一个维度
// dp[i][j][k]表示前i个背包，0，1容量分别为j,k的时候的最大子集，dp[strs.size()][m][n]即为最终答案

// 获得str[i]的0和1字符数量的函数
int get_number_zero(string s) {
    int cnt = 0;
    for (auto i : s) {
        if (i == '0') ++cnt;
    }
    return cnt;
}


int findMaxForm(vector<string>& strs, int m, int n) {
    int s = strs.size();
    vector<vector<vector<int>>> dp(s + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
    for (int i = 1; i <= s; ++i) {
        // 这里尤其注意j，k从0开始，传统的背包问题是一维的，dp[i][0]必然为0，所以循环可以从1开始，上升到2维后并不成立
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k)
            {
                int zero_times = get_number_zero(strs[i-1]);
                int one_times = strs[i-1].size() - zero_times;
                if (j < zero_times || k < one_times) dp[i][j][k] = dp[i-1][j][k];
                else dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-zero_times][k-one_times]+1);
            }
        }
    }
    return dp[s][m][n];
}

int main()
{
    return 0;
}
