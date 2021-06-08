// https://leetcode-cn.com/problems/last-stone-weight-ii/
// leetcode 1049

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 将问题转化为求数组不超过sum/2的最大值，结果即为sum-2*该值
// 背包问题，价值和容量都是sum/2
// 对于这种价值和容量相同的情况，其实可以直接用一个bool数组(表示背包是否能够被装满)，然后从sum/2开始递减找到第一个为true的
int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for(auto& i : stones) sum += i;
    int m = sum / 2;
    int n = stones.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j - stones[i - 1] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-stones[i-1]]+stones[i-1], dp[i-1][j]);
        }
    }
    return sum - 2 * dp[n][m];
}


int main()
{
    return 0;
}