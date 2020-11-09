/*
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 *
 * 原点在左上角，向下是x轴，向右是y轴，需要判断左上角和右上角是否有皇后
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    bool isvalid(vector<string> board, int row, int col) {
        int n = board.size();
        // 判断同列是否有皇后
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 判断左上角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 判断右上角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n ; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrace(vector<string> board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.at(row).length(); ++col) {
            if (!isvalid(board, row, col)) {
                continue;
            }
            board[row][col] = 'Q';
            backtrace(board, row + 1);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // 先自定义棋盘
        vector<string> board(n, string(n, '.'));
        backtrace(board, 0);
        return res;
    }
};

int main() {
    Solution so;
    vector<vector<string>> res = so.solveNQueens(8);
    for(vector<string> vec: res) {
        for(string s: vec) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
