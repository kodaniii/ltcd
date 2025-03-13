#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        //按照身高递减排序
        //如果身高相同，按照属性（有几个比他更高的人）递增（反向）排序
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