// https://leetcode-cn.com/problems/power-of-four/
// leetcode 342
#include <iostream>

using namespace std;
// 基础的循环写法
// bool isPowerOfFour(int n) {
//     while (n > 1) {
//         if (n % 4) return false;
//         n /= 4;
//     }
//     return n == 1;
// }

// 首先判断是否是2的倍数，用位运算n&(n-1)计算
// 取模算法 (3+1)^n ≡ 1 (mod 3) 可以推出(x+1)^n ≡ 1(mod x) 对于任意的x > 1
bool isPowerOfFour(int n) {
    return n > 0 && (n % 3 == 1) && !(n & (n -1));
}
int main(){
    cout << boolalpha << isPowerOfFour(256);
    return 0;
}