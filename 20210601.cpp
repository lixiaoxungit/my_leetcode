// https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
// leetcode 1744

#include <iostream>
#include <vector>
using namespace std;

// 计算糖果数量的前缀和
// 计算该query的favorite那天的时候所吃的糖果的区间范围
// 计算favorite糖果的范围
// 观察是否有交集
vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    vector<long long> presum(candiesCount.size());
    if (!candiesCount.empty()) {
        presum[0] = candiesCount[0];
        for (size_t i = 1; i < candiesCount.size(); i++)
        {
            presum[i] = presum[i-1] + candiesCount[i];
        }
    }

    vector<bool> res;
    for (int i = 0; i < queries.size(); ++i) {
        int index = queries[i][0];
        int day = queries[i][1];
        int max_cnt = queries[i][2];
        long long floor = index == 0 ? 1 : presum[index-1] + 1;
        long long ceil = presum[index];
        long long floor_1 = day + 1;
        long long ceil_1 = floor_1 * max_cnt;
        res.push_back(!(floor > ceil_1 || floor_1 > ceil));
    }
    return res;   
}

int main(){
    vector<vector<int>> que{{4,2,4}};
    vector<int> can{7,4,5,3,8};
    vector<bool> res = canEat(can, que);
    return 0;
}