/* 1143. 最长公共子序列
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

    一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
    例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

    若这两个字符串没有公共子序列，则返回 0。

    示例 1:

    输入：text1 = "abcde", text2 = "ace"
    输出：3
    解释：最长公共子序列是 "ace"，它的长度为 3。
    示例 2:

    输入：text1 = "abc", text2 = "abc"
    输出：3
    解释：最长公共子序列是 "abc"，它的长度为 3。
    示例 3:

    输入：text1 = "abc", text2 = "def"
    输出：0
    解释：两个字符串没有公共子序列，返回 0。
 
    提示:

    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    输入的字符串只含有小写英文字符。

    遇到两个字符串的动态规划，考虑建立二维数组dp[m+1][n+1]
    之所以要加1，是为了传入空字符串时也可以进行判断，同时在for循环中也避免了判断边界条件
    定义状态：二维数组dp[i][j]表示text[0..i]和text[0..j]的最长公共子序列的长度。
    base case：画出dp table可以看出，空字符串与text1或者text2的最长公共子序列的长度均为0
    定义状态转移方程：
        若text1[i] == text2[j]，则dp[i][j]可以加1，并且i前移，j前移
        若text1[i] != text2[j]，
            遍历两个字符串:
                1、若当前两个字符相等：
                    当前状态 = 两个元素的前一个状态 + 1
                2、若当前两个字符不等：
                    当前状态 = 两个元素任一元素的前一个状态 的 最大值

 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // 定义dp数组，同时初始化base case
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                char c1 = text1[i];
                char c2 = text2[j];

                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution so;
    string s1 = "abcde";
    string s2 = "ace";
    cout << so.longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
