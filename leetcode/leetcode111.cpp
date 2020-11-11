/*
 * 给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 *
 * 1. 起点在哪，终点在哪  起点就是根节点，终点在叶子节点
 * 2. 如何判断到达终点  终点无左子节点和右子节点
 *
 * */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int count = 1;
        queue<TreeNode*> q;
        // 先将根节点加入到队列中
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            // 遍历同一层的所有节点
            for (int i = 0; i < sz; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                // 判断是否到达终点
                if (curr->left == nullptr && curr->right == nullptr) {
                    return count;
                }

                // 将相邻节点加入到队伍中
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            count++;
        }
        return 0;
    }

};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node2->right = node5;

    Solution so;
    cout << so.minDepth(node1) << endl;
    return 0;
}
