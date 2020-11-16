/*
 * 字符串的排列
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
    换句话说，第一个字符串的排列之一是第二个字符串的子串。

    示例1:
    输入: s1 = "ab" s2 = "eidbaooo"
    输出: True
    解释: s2 包含 s1 的排列之一 ("ba").
     

    示例2:
    输入: s1= "ab" s2 = "eidboaoo"
    输出: False
     

    注意：

    输入的字符串只包含小写字母
    两个字符串的长度都在 [1, 10,000] 之间

 * */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> needs;
        unordered_map<char, int> window;

        for(char c: s1) {
            needs[c]++;
        }

        int valid = 0;
        int left = 0, right = 0;

        while (right < s2.length()) {
            char c = s2[right];
            right++;
            if (needs.count(c)) {
                window[c]++;
                if (window[c] == needs[c]) {
                    valid++;
                }
            }

            while (right - left >= s1.length()) {
                if (valid == needs.size()) {
                    return true;
                }
                char d = s2[left];
                left++;
                if (needs.count(d)) {
                    if (needs[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution so;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << so.checkInclusion(s1, s2) << endl;
    return 0;
}
