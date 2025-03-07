#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    //row行col列
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        //检查行是否重复
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) return false;
        }
        //列
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) return false;
        }
        //3*3区域
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board) {
        //i行j列
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;
                //尝试放不同的char型数字到(i, j)
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if(backtracking(board)) return true;    //只要找到一个匹配的数字就先递归返回
                        board[i][j] = '.';
                    }
                }
                return false;   //9个数字都试了，都不行，返回false
            }
        }
        return true;    //遍历完，没有返回false
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};