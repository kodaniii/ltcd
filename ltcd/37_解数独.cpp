#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    //row��col��
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        //������Ƿ��ظ�
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) return false;
        }
        //��
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) return false;
        }
        //3*3����
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
        //i��j��
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;
                //���ԷŲ�ͬ��char�����ֵ�(i, j)
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if(backtracking(board)) return true;    //ֻҪ�ҵ�һ��ƥ������־��ȵݹ鷵��
                        board[i][j] = '.';
                    }
                }
                return false;   //9�����ֶ����ˣ������У�����false
            }
        }
        return true;    //�����꣬û�з���false
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};