//
// Created by June on 2020/10/28.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * 暴力递归
 * 针对递归问题，我们可以先画出递归树
 *          f(20)
 *          /   \
 *       f(19)  f(18)
 *       /   \   /  \
 *    f(18) f(17) ...
 *    /  \
 *    ......
 *    / \
 *  f(1) f(2)
 *
 *  可以看到f(18),f(17),...等被大量重复计算，存在大量重复子问题
 *  递归算法的时间复杂度 = 子问题个数 * 解决一个子问题需要的时间
 *  子问题个数 = 递归树节点个数，2^n
 *  时间复杂度为O(2^n)
 * */
int f1(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    return f1(n-1) + f1(n-2);
}

/*
 * 带备忘录的递归解法
 * 即然耗时的原因是重复计算， 那么我们可以造一个「备忘录」
 * 每次算出某个子问题的答案后别急着返回，先记到「备忘录」里再返回;
 * 每次遇到一个子问题先去「备忘录」里查 一查，如果发现之前已经解决过这个问题了，直接把答案拿出来用
 * 一般使用一个数组充当这个「备忘录」，当然你也可以使用哈希表(字 典)，思想都是一样的。
 *
 * 自顶向下的方法，每个结果都只需要计算一遍，时间复杂度为O(N)
 * */
int helper(vector<int> memo, int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    if (memo.at(n) != 0) {
        return memo.at(n);
    }
    memo.at(n) = helper(memo, n-1) + helper(memo, n-2);
    return memo.at(n);
}

int f2(int n)
{
    vector<int> memo(n+1, 0);
    return helper(memo, n);
}

/*
 * dp数组的迭代解法
 * 我们可以把这个「备忘录」独立出来成为一张表，就叫做 DP table
 * 自底向上的解法，先计算f(1),f(2),f(3),慢慢到f(20)
 * 效率与备忘录类似
 * 状态转移方程：
 * f(n) = 1, n=1,2
 * f(n) = f(n-1) + f(n-2), n>2
 *
 * */
int f3(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    vector<int> dp(n+1, 0);
    dp.at(1) = 1;
    dp.at(2) = 1;
    for (int i = 3; i <= n; ++i) {
        dp.at(i) = dp.at(i-1) + dp.at(i-2);
    }

    return dp.at(n);
}

/*
 * 对空间复杂度进行优化
 * 根据斐波那契数列 的状态转移方程，当前状态只和之前的两个状态有关，其实并不需要那么⻓ 的一个 DP table 来存储所有的状态，
 * 只要想办法存储之前的两个状态就行 了。
 * 空间复杂度为O(1)
 * */
int f4(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    int prev = 1, curr = 1, temp;
    for (int i = 3; i <= n; ++i) {
        temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    return curr;
}

int main()
{
    int n = 20;
    cout << f4(n) << endl;
    return 0;
}