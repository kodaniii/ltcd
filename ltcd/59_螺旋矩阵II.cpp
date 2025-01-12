#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int start_x = 0, start_y = 0;
        int offset = 1;
        int count = 1;

        int i, j;

        int loop = n / 2;

        while (loop--) {
            for (j = start_y; j < n - offset; j++)  res[start_x][j] = count++;
            for (i = start_x; i < n - offset; i++)  res[i][j] = count++;
            for (; j > start_y; j--) res[i][j] = count++;
            for (; i > start_x; i--) res[i][j] = count++;

            start_x++, start_y++;
            offset++;
        }

        if (n % 2) {
            res[n / 2][n / 2] = count;
        }

        return res;
    }
};