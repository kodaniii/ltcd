#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //��ʼ���������ǹ�Ϊ���1
        vector<int> c(ratings.size(), 1);
        //ֻ����ұߺ��ӣ��������߸߾�+1
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
        }
        //�����ߺ��ӣ����ұ߸�+1��ͬʱ�Ƚ���һ�ּ��Ľ����ȡ�����
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) c[i - 1] = max(c[i - 1], c[i] + 1);
        }
        int res = 0;
        for (auto& _c : c) {
            res += _c;
        }
        return res;
    }
};