// https://leetcode-cn.com/problems/continuous-subarray-sum/
// leetcode 523

#include <iostream>
#include <vector>

using namespace std;

// 直接前序和
// 这样会超时，时间复杂度O(n^2)
// bool checkSubarraySum(vector<int>& nums, int k) {
//     vector<int> prenums = nums;
//     int n = nums.size();
//     for (int i = 1; i < n; ++i) {
//         prenums[i] += prenums[i-1];
//     }
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             int curr_sum = 0;
//             if (i == 0) curr_sum = prenums[j];
//             else curr_sum = prenums[j] - prenums[i-1];
//             if (curr_sum % k == 0) return true;
//         }
//     }
//     return false;
// }

// 使用哈希表优化
// 注意如果上面的curr_sum % k等于0其实等价于 prenums[j]和prenums[i-1]模k余数相同，可以提前计算出来存入哈希表
// 计算后面的前缀和时，查看余数是否在哈希表中
#include <unordered_map>
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> presums; // key是余数，value是该余数第一次出现的下标
    presums[0] = -1; // 考虑在数组最前面的特殊情况，注意前缀和相减表示的是i+1到j的和
    int n = nums.size();
    int resident = 0; // 记录余数
    for (int i = 0; i < n; ++i) {
        resident = (resident + nums[i]) % k;
        if (presums.count(resident)) {
            if (i - presums[resident] >= 2) return true;
        }
        else presums[resident] = i;
    }
    return false;
}


int main() {
    vector<int> nums{23,2,4,6,7};
    int k = 2;
    bool res = checkSubarraySum(nums, k);
    return 0;
}