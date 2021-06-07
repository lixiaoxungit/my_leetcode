// https://leetcode-cn.com/problems/target-sum/
// leetcode 494

#include <iostream>
#include <vector>
using namespace std;

// 转化成0-1背包问题，设数组和为sum，前面符号为+的和为p_sum，为-的为n_sum,则应该有
// p_sum + n_sum = sum, p_sum - n_sum = target, 进而推出p_sum = (sum+target)/2
// 因此转化成背包问题，nums数组中有多少个子集使得他们的和为p_sum
// dp[i][j]表示只选取数组前i个元素中的子集的和为j的组合数
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    int n = nums.size();
    for (auto& i : nums) sum += i;
    int p_sum = sum+target; // 这里先不除2
    if (p_sum % 2 != 0) return 0;
    p_sum /= 2;
    vector<vector<int>> dp(n+1, vector<int>(p_sum+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= p_sum; ++j) {
            if (j - nums[i-1] < 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
        }
    }
    return dp[n][p_sum];
}

int main()
{
    return 0;
}