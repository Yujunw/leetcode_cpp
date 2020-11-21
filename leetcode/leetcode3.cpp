/*
 * 3. 无重复字符的最长子串
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
    输入: "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * */

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int left = 0, right = 0;
        int res = 0;
        while (right < s.length()) {
            char c = s[right];
            right++;
            charMap[c]++;

            // 当出现重复字符时，左窗口开始收缩
            while (charMap[c] > 1) {
                char d = s[left];
                left++;
                charMap[d]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main() {
    Solution so;
    string s = "dvdf";
    cout << so.lengthOfLongestSubstring(s) << endl;
    return 0;
}
