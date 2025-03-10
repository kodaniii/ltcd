#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    //������Ծ���ǵ���Զ�����±�
        int nextDistance = 0;   //��һ����Զ�����±꣬ʹ��i��cur��next֮���ƶ�
        int cnt = 0;            //�ߵĲ���

        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);
            //i��cur��next֮���ƶ�
            //��i�ߵ�cur����ʾ�Ѿ��ߵ��˱�����Ծ���յ�
            if (i == curDistance) {
                cnt++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1) break;
            }
        }

        return cnt;
    }
};