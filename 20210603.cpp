// https://leetcode-cn.com/problems/contiguous-array/
// leetcode 525

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 0看成-1，连续区间中数字相同等价于和为0，等价于前缀和之差为0，等价于前缀和相同，使用哈希表几率前缀和
int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> presums; // key是前缀和，value是该和第一次出现的下标
    presums[0] = -1; // 考虑在数组最前面的特殊情况，因为前缀和相减是i+1到j的求和,比如0到2的求和应该是presum[2]-presum[-1]
    // presum[-1] = 0 
    int n = nums.size();
    int curr_sum = 0; // 记录余数
    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) ++curr_sum;
        else --curr_sum;
        if (presums.count(curr_sum)) 
            max_length = max(max_length, i - presums[curr_sum]);
        else presums[curr_sum] = i;
    }
    return max_length;
}

int main()
{

    return 0;
}