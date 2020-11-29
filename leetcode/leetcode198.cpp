/*  198 打家劫舍
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
    示例 1：

    输入：[1,2,3,1]
    输出：4
    解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
         偷窃到的最高金额 = 1 + 3 = 4 。
    示例 2：

    输入：[2,7,9,3,1]
    输出：12
    解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
         偷窃到的最高金额 = 2 + 9 + 1 = 12 。

    0 <= nums.length <= 100
    0 <= nums[i] <= 400

    难点在于找到原问题与子问题的关系
    定义base case：当nums.length == 0时，直接返回0，等于1时返回数组中的元素
    原问题：偷窃nums.length()家房屋所获得的的最大金额
    子问题：偷窃nums.length() - 1家房屋所获得的的最大金额
    定义状态：定义dp最大统计金额
        偷窃到第i家的最大金额:
            不偷窃第i家，最大金额为dp[i-1]
            偷窃第i家，就不能偷窃第i-1家，最大金额为d[i-2]+nums.at(i)


 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        dp[0] = nums.at(0);
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-2] + nums.at(i), dp[i-1]);
        }
        return dp.back();
    }
};

int main() {
    Solution so;
    vector<int> nums = {4, 1, 1, 4, 1, 1, 4};
    cout << so.rob(nums) << endl;
    return 0;
}
