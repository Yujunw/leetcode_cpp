//
// Created by June on 2020/11/3.
/*
 *
    给定一个 没有重复 数字的序列，返回其所有可能的全排列。


    解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：
    1、路径：也就是已经做出的选择。
    2、选择列表：也就是你当前可以做的选择。
    3、结束条件：也就是到达决策树底层，无法再做选择的条件。

    代码模板：
    result = []
    def backtrack(路径, 选择列表):
        if 满足结束条件:
            result.add(路径)
            return

        for 选择 in 选择列表:
            做选择
            backtrack(路径, 选择列表)
            撤销选择

    其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」，特别简单。
 * */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtrace(vector<int>& nums, vector<int> path)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int digit : nums) {
            // find时间复杂度为O(n)
            if (find(path.begin(), path.end(), digit) != path.end()) {
                continue;
            }
            path.push_back(digit);
            backtrace(nums, path);
            path.pop_back();
        }
    }

    void backtrace2(vector<int>& nums, vector<int> path, vector<bool> used)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // 如果digit已经被用过，就不该再被使用，可以画出递归树
            if (used.at(i)) {
                continue;
            }
            cout << "No. " << i+1 << endl;
            path.push_back(nums.at(i));
            // 被用过的digit，true
            used.at(i) = true;
            backtrace2(nums, path, used);
            // path中的最后一个数字要被移除，used=false
            used.at(i) = false;
            // 假设path={1,2,3},3被移除，可以重新选择3，程序回到上一层，撤销2
            path.pop_back();
            for(int digit:path) {
                cout << digit << '\t';
            }
            cout << endl;
        }
        cout << "over" << endl;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        // 利用一个bool数组记录使用过的数字，节省时间复杂度
        vector<bool> used(nums.size(), false);
        backtrace2(nums, path, used);
        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = so.permute(nums);
    for(auto vec : res) {
        for(int i : vec) {
            cout << i << '\t';
        }
        cout << endl;
    }
    return 0;
}
