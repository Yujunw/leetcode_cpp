/*
 * BFS问题的本质就是让你在一幅「图」中找到从起点 start 到终点 target 的最近距离
 * 1. 起点在哪，终点在哪
 * 2. 如何判断到达终点
 * */

#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Node {
public:
    int x;
    int y;
    Node(int x, int y) : x(x), y(y) {}

    bool operator==(Node &rhs) {
        return this->x == rhs.x && this->y == rhs.y;
    }
};

int bfs(Node start, Node target)
{
    queue<Node> q;
    set<Node> visited; // 避免走回头路

    q.push(start); // 将起点加入到队列中
    visited.insert(start);

    int step = 0; // 记录扩散的步数

    while (!q.empty()) {
        /* 将当前队列中的所有节点向四周扩散 */
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            Node curr = q.front();
            /* 划重点：这里判断是否到达终点 */
            if (curr == target) {
                return step;
            }
            q.pop();
            /* 将 cur 的相邻节点加入队列 */
            vector<Node> adj = {Node(curr.x+1, curr.y), Node(curr.x-1, curr.y), Node(curr.x, curr.y-1),                                         Node(curr.x, curr.y+1)};
            for(Node n : adj) {
                if (visited.find(n) != visited.end()) {
                    q.push(n);
                    visited.insert(n);
                }
            }
        }
        // 未添加新节点之前，队列中的节点都在同一层，必须全部遍历完后才能step++
        step++;
    }
    return step;
}

int main() {

    return 0;
}
