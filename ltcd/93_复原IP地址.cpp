#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    vector<string> res;
    void backtracking(string& s, int startIdx, int pointNum) {
        //����С���㶼ȷ��������
        if (pointNum == 3) {
            //�жϵ��Ķ��Ƿ�Ϸ���[]
            if (isValid(s, startIdx, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = startIdx; i < s.size(); i++) {
            //�жϵ�ǰ������Ϊ�ֶ��Ƿ�Ϸ�
            if (isValid(s, startIdx, i)) {
                s.insert(s.begin() + i + 1, '.');   //��i�ĺ����һ��.
                backtracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }
    // �ж��ַ���s������ұ�����[start, end]����ɵ������Ƿ�Ϸ�
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0��ͷ�����ֲ��Ϸ�
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // �����������ַ����Ϸ�
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // �������255�˲��Ϸ�
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};