//
// Created by June on 2020/11/1.
//
/*
 * 给定不同面额的硬币 coins 和一个总金额 amount。
 * 编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 你可以认为每种硬币的数量是无限的。
 *
 * 首先，这个问题是动态规划问题，因为它具有「最优子结构」的。要符合「最优子结构」，子问题间必须互相独立。
 * 凑零钱问题为什么说它符合最优子结构呢？比如你想求 amount = 11 时的最少硬币数（原问题），如果你知道凑出 amount = 10
 * 的最少硬币数（子问题），你只需要把子问题的答案加一（再选一枚面值为 1 的硬币）就是原问题的答案。
 * 因为硬币的数量是没有限制的，所以子问题之间没有相互制，是互相独立的。
 *
 * 就要思考如何列出正确的状态转移方程？
1、确定 base case，显然目标金额 amount 为 0 时算法返回 0，因为不需要任何硬币就已经凑出目标金额了。
2、确定「状态」，也就是原问题和子问题中会变化的变量。由于硬币数量无限，硬币的面额也是题目给定的，只有目标金额会不断地向
    base case 靠近，所以唯一的「状态」就是目标金额 amount。
3、确定「选择」，也就是导致「状态」产生变化的行为。目标金额为什么变化呢，因为你在选择硬币，你每选择一枚硬币，就相当于减少了目标金额。所以说所有硬币的面值，就是你的「选择」。
4、明确 dp 函数/数组的定义。我们这里讲的是自顶向下的解法，所以会有一个递归的 dp 函数，一般来说函数的参数就是状态转移中会变化的量，也就是上面说到的「状态」；函数的返回值就是题目要求我们计算的量。就本题来说，状态只有一个，即「目标金额」，题目要求我们计算凑出目标金额所需的最少硬币数量。所以我们可以这样定义 dp 函数：
 dp(n) 的定义：输入一个目标金额 n，返回凑出目标金额 n 的最少硬币数量。
 * */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 备忘录
    unordered_map<int, int> memo;

    /*
     * 子问题总数为递归树节点个数，这个比较难看出来，是 O(n^k)，总之是指数级别的。每个子问题中含有一个 for 循环，复杂度为 O(k)。
     * 所以时间复杂度为 O(k * n^k)，指数级别。
     * */
    int dp(const vector<int> &coins, int amount)
    {
        // 确定base case
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }

        int res = INT32_MAX;
        int subProblem;

        for (int coin: coins) {
            // 子问题
            subProblem = dp(coins, amount - coin);
            if (subProblem == -1) {
                continue;
            }
            // 子问题加1即得原问题的解
            res = min(res, subProblem + 1);
        }

        if (res == INT32_MAX) {
            return -1;
        } else {
            return res;
        }
    }

    /*
     * 「备忘录」大大减小了子问题数目，完全消除了子问题的冗余，所以子问题总数不会超过金额数 n，即子问题数目为 O(n)。处理一个子问题的时
     * 间不变，仍是 O(k)，所以总的时间复杂度是 O(kn)。
     * */
    int dp_memo(vector<int>& coins, int amount)
    {
        // 确定base case
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }

        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int res = INT32_MAX;
        int subProblem;
        for(int coin : coins) {
            subProblem = dp_memo(coins, amount - coin);
            if (subProblem == -1) {
                continue;
            }
            res = min(res, 1 + subProblem);
        }

        if (res != INT32_MAX) {
            memo[amount] = res;
        } else {
            memo[amount] =  -1;
        }
        return memo[amount];
    }

    int dp_dp(vector<int>& coins, int amount)
    {
        if (amount < 0) {
            return -1;
        }
        // 数组大小为 amount + 1，初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // 确定base case
        dp.at(0) = 0;

        // 外层 for 循环在遍历所有状态的所有取值
        for (int i = 0; i < dp.size(); ++i) {
            // 内层 for 循环在求所有选择的最小值
            for(int coin : coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp.at(i) = min(dp.at(i), 1 + dp.at(i - coin));
            }
        }
        return dp.at(amount) == amount + 1 ? -1 : dp.at(amount);
    }

    int coinChange(vector<int>& coins, int amount)
    {
        return dp_dp(coins, amount);
    }
};

int main()
{
    Solution so;
    vector<int> coins = {1, 2, 5};
    int amount = 100;

    cout << so.coinChange(coins, amount) << endl;
    return 0;
}