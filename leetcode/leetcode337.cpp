/* leetcode 337 打家劫舍3
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
  计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

    示例 1:

    输入: [3,2,3,null,3,null,1]

         3
        / \
       2   3
        \   \
         3   1

    输出: 7
    解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
    示例 2:

    输入: [3,4,5,1,3,null,1]

         3
        / \
       4   5
      / \   \
     1   3   1

    输出: 9
    解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

    定义状态：定义2个map，分别表示偷窃到该节点时，偷和不偷的最大金额
    状态转换方程：
        1. 要偷窃o节点，那么就不能偷窃其左右子节点，此时最大金额为f[o] = g(o->left)+g(o->right)
        2. 不偷窃o节点，此时可以选择性偷窃或者不偷窃其左右子树，此时最大金额为
            g(o) = max(f(o->left),g(o->left)) + max(f(o->right),g(o->right))
    如此计算的话，需要提前知道偷窃到左右子节点的最大值，因此需要后序遍历，自底向上
    问题场景在「树」上，就要用到「树的遍历」，这里用「后序遍历」，这是因为：我们的逻辑是子结点陆续汇报信息给父结点，一层一层向上汇报，
        最后在根结点汇总值。

 *
 * */

#include <iostream>
#include <map>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 假设偷窃该节点的最大金额为f，不偷窃该节点的最大金额为g
    map<TreeNode*, int> f, g;

    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        dfs(root->right);

        f[root] = g[root->left] + g[root->right] + root->val;
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }

    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root);
        return max(f[root], g[root]);
    }
};

int main() {
    Solution so;
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(1);
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node2->right = node5;
    node3->right = node6;
    cout << so.rob(node1) << endl;
    return 0;
}
