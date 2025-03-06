#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    vector<vector<string>> res;
    //row行数, col列数
    bool isValid(int row, int col, vector<string>& cb, int n) {
        //检查列，列小于等于已经生成的行数，i为行数
        for (int i = 0; i < row; i++) {
            if (cb[i][col] == 'Q') return false;
        }
        //不需要检查行，因为肯定不是同行
        //检查斜线1，向前检查
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (cb[i][j] == 'Q') return false;
        }
        //检查斜线2
        for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++) {
            if (cb[i][j] == 'Q') return false;
        }
        return true;
    }
    //n棋盘尺寸，row表示遍历的行数
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, chessboard, n)) {   //row行i列是否可放
                chessboard[row][i] = 'Q';   //放置皇后，row行i列
                backtracking(n, row + 1, chessboard);
                chessboard[row][i] = '.';   //撤销皇后
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return res;
    }
};

