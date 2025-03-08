#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int preDiff = 0;    //��һ�β�ֵ
        int curDiff = 0;    //��ǰ��ֵ
        int res = 1;        //��ֵ������Ĭ���������һ����ֵ
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                res++;
                preDiff = curDiff;  //�ڶ��仯ʱ����preDiff
            }
            cout << preDiff << " " << curDiff << endl;
        }
        return res;
    }
};