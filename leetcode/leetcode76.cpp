/*
 * 给你一个字符串s、一个字符串t。返回s中涵盖t所有字符的最小子串。如果s中不存在涵盖t所有字符的子串，则返回空字符串 "" 。
注意：如果s中存在这样的子串，我们保证它是唯一的答案。
示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 
提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

 * */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // need记录字符串t的所有字符，window记录滑动窗口中t的字符，注意不是记录滑动窗口中的所有字符
        unordered_map<char, int> need, window;
        for(char c: t) {
            need[c]++;
        }

        int left = 0, right = 0;
        // valid 变量表示窗口中满足 need 条件的字符个数
        int valid = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;
        while (right < s.length()) {
            // c是将移入窗口的字符
            char c = s[right];
            right++;
            // 如果need中包含c字符，则需要加以统计，不包含的话就继续右移窗口，window不用管
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                // 更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                // d是即将移除窗口的字符
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    Solution so;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << so.minWindow(s, t) << endl;
    return 0;
}
