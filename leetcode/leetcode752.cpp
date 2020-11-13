/*
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
 * 每个拨轮可以自由旋转:例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。锁的初始数字为 '0000' ，
 * 一个代表四个拨轮的数字的字符串。列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁会被永久锁定，
 * 无法再被旋转。字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
 *
 *  起点："0000" ，终点即target
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string plusOne(string basicString, int j) {
        if (basicString[j] == '9') {
            basicString[j] = '0';
        } else {
            basicString[j] += 1;
        }
        return basicString;
    }

    string minusOne(string basicString, int j) {
        if (basicString[j] == '0') {
            basicString[j] = '9';
        } else {
            basicString[j] -= 1;
        }
        return basicString;
    }

    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        set<string> visited;
        set<string> deads(deadends.begin(), deadends.end());

        q.push("0000");
        visited.insert("0000");
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                q.pop();
                if (deads.find(curr) != deads.end()) {
                    continue;
                }

                if (curr == target) {
                    return step;
                }
                for (int j = 0; j < 4; ++j) {
                    string up = plusOne(curr, j);
                    string down = minusOne(curr, j);

                    if (visited.find(up) == visited.end()) {
                        visited.insert(up);
                        q.push(up);
                    }
                    if (visited.find(down) == visited.end()) {
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main() {
    vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    Solution so;
    string target = "8888";
    cout << so.openLock(deadends, target) << endl;
    return 0;
}
