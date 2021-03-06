/* 122. 买卖股票的最佳时机 II
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    示例 1:
    输入: [7,1,5,3,6,4]
    输出: 7
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

    示例 2:
    输入: [1,2,3,4,5]
    输出: 4
    解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
         因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

    示例 3:
    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
    提示：

    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4

    特殊做法：由于不限制买卖次数，所以每次只要低买高卖就肯定能赚到最大利润

    动态规划：
    定义状态：
        定义二维数组dp[i][j]表示第i天在j状态下所能赚取的最大利润，其中j=0表示持有股票，j=1表示持有现金
    初始化：
        在第1天持有股票，则dp[0][0] = -prices[0]
        在第1天持有现金，则dp[0][1] = 0
    状态转移方程：
        若在第i天持有股票，第i天的最大利润为 max{第i-1天持有股票的最大利润，第i-1天持有现金然后买入股票的金额}
        若在第i天持有现金，第i天的最大利润为 max{第i-1天持有现金的最大利润，第i-1天持有股票然后卖出的金额}


 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int tmp = prices[i] - prices[i-1];
            if (tmp > 0) {
                profit += tmp;
            }
        }
        return profit;
    }

    int maxProfit2(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }

        return dp[prices.size()-1][1];
    }
};

int main() {
    Solution so;
    vector<int> prices = {7,1,5,3,6,4};
    cout << so.maxProfit2(prices) << endl;
    return 0;
}
