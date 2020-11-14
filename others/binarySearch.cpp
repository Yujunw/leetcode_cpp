//
// Created by June on 2020/11/14.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        // 计算mid时要防止溢出，所以不用mid = (left+right)/2;
        int mid = left + (right - left)/2;
        if (nums.at(mid) == target) {
            return mid;
        } else if (nums.at(mid) > target) {
            right = mid - 1;
        } else if (nums.at(mid) < target) {
            left = mid + 1;
        }
    }
    return -1;
}

// 寻找左侧边界的二分搜索,[1,2,2,2,3],返回1
int leftBound(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums.at(mid) < target) {
            left = mid + 1;
        } else if (nums.at(mid) > target) {
            right = mid - 1;
        }
        // 当mid值等于target时，不返回，而是缩小搜索区域
        else if (nums.at(mid) == target) {
            right = mid - 1;
        }
    }

    // 当left == right + 1时，搜索停止，此时若target大于nums中的所有值将会越界
    // 其实只需要判断nums.at(left) != target就可以了，但此时的left可以等于nums.size()，数组越界
    if (left >= nums.size() || nums.at(left) != target) {
        return -1;
    }
    return left;
}

int rightBound(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums.at(mid) < target) {
            left = mid + 1;
        } else if (nums.at(mid) > target) {
            right = mid - 1;
        }
            // 当mid值==target时，继续缩小搜索范围
        else if (nums.at(mid) == target) {
            left = mid + 1;
        }
    }

    // 结束搜索条件依然为left == right+1
    if (right < 0 || nums.at(right) != target) {
        return -1;
    }
    return right;
}

int main() {
    vector<int> nums = {1,2,2,2,9};
    int target = 0;
    cout << leftBound(nums, target) << endl;
    cout << rightBound(nums, target) << endl;

    return 0;
}
