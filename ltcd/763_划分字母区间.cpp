#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    //��¼�����һ�γ��ֵ�λ��
    int last_pos[26] = { 0 };
public:
    vector<int> partitionLabels(string s) {
        //��ʼ��last_pos����
        for (int i = 0; i < s.size(); i++) {
            last_pos[s[i] - 'a'] = i;
        }
        vector<int> res;
        //leftΪ������˵㣬rightΪ�Ҷ˵㣬����ұ�
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, last_pos[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};