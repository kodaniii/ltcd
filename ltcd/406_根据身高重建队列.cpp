#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        //������ߵݼ�����
        //��������ͬ���������ԣ��м����������ߵ��ˣ���������������
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto& p : people) {
            int pos = p[1];
            res.insert(res.begin() + pos, p);
        }
        return res;
    }
};