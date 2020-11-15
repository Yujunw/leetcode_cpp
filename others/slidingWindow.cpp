/*
 * 滑动窗口问题的模板
 *
 * 1、我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引左闭右开区间 [left, right) 称为一个「窗口」。
 * 2、我们先不断地增加 right 指针扩大窗口 [left, right)，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。
 * 3、此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right)，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）
 * 同时，每次增加 left，我们都要更新一轮结果。
 * 4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。

 * */

#include <iostream>
#include <unordered_map>
using namespace std;

string sildingWindow(string s, string t)
{
    // need记录字符串t中的字符个数，window记录滑动窗口中字符串t的字符的个数，而不是滑动窗口的所有字符个数
    unordered_map<char, int> need, window;
    for(char c : t) {
        need[c]++;
    }

    int left = 0, right = 0;
    int start = 0, len = INT_MAX;
    // valid 变量表示窗口中满足 need 条件的字符个数
    int valid = 0;

    while (right < s.length()) {
        char c = s[right];
        right++;
        /* 进行窗口数据的更新 */

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);

        // 判断左侧窗口是否要收缩
        while(valid == need.size()) {
            char d = s[left];
            left++;

            /* 进行窗口数据的更新 */

        }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
}

int main() {

    return 0;
}
