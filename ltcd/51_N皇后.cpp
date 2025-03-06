#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    vector<vector<string>> res;
    //row����, col����
    bool isValid(int row, int col, vector<string>& cb, int n) {
        //����У���С�ڵ����Ѿ����ɵ�������iΪ����
        for (int i = 0; i < row; i++) {
            if (cb[i][col] == 'Q') return false;
        }
        //����Ҫ����У���Ϊ�϶�����ͬ��
        //���б��1����ǰ���
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (cb[i][j] == 'Q') return false;
        }
        //���б��2
        for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++) {
            if (cb[i][j] == 'Q') return false;
        }
        return true;
    }
    //n���̳ߴ磬row��ʾ����������
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, chessboard, n)) {   //row��i���Ƿ�ɷ�
                chessboard[row][i] = 'Q';   //���ûʺ�row��i��
                backtracking(n, row + 1, chessboard);
                chessboard[row][i] = '.';   //�����ʺ�
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

