/* 72. 编辑距离
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
    你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符
     
    示例 1：
    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')

    示例 2：
    输入：word1 = "intention", word2 = "execution"
    输出：5
    解释：
    intention -> inention (删除 't')
    inention -> enention (将 'i' 替换为 'e')
    enention -> exention (将 'n' 替换为 'x')
    exention -> exection (将 'n' 替换为 'c')
    exection -> execution (插入 'u')

    提示：
    0 <= word1.length, word2.length <= 500
    word1 和 word2 由小写英文字母组成

    遇到两个字符串的动态规划，考虑建立二维数组dp[m+1][n+1]
    定义状态：二维数组dp[i][j]表示word1[0..i]转换成word2[0..j]的最小编辑距离
    base case：画出dp table可以看出，空字符串转换成word1或者word2的最小编辑距离递增
    状态转移方程：
        画出dp table



 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // 初始化base case
        for (int i = 0; i < m+1; ++i) {
            dp[i][0] = i;
        }

        for (int j = 0; j < n+1; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                // dp table是(m+1)*(n+1)，但是字符串还是m，n维，减1后才是从第一个字符开始遍历
                char c1 = word1[i-1];
                char c2 = word2[j-1];
                // 如果两个字符相同，则i，j两个指针都同时前进一步，无需操作
                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作
                    dp[i][j] = min(min(dp[i-1][j-1] + 1, dp[i-1][j] + 1), dp[i][j-1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution so;
    string s1 = "intention";
    string s2 = "execution";
    cout << so.minDistance(s1, s2) << endl;
    return 0;
}
