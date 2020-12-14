/* 53. 最大子序和
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    示例:
    输入: [-2,1,-3,4,-1,2,1,-5,4]
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

    定义状态：定义dp[i]为遍历到第i个元素时的最大子序和，此时dp[i]不一定与dp[i-1]相关，因此定义dp[i]为以i结尾的最大子序和
    状态转移方程：
        dp[i] = max(dp[i-1]+nums[i], nums[i])

    base case: dp[0] = nums[0]
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        // 最大值不一定是最后一个元素
        int res = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if (res < dp[i]) {
                res = dp[i];
            }
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << so.maxSubArray(nums) << endl;
    return 0;
}
