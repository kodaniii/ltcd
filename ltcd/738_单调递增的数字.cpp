#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        //flag��¼����Ҫ��ֵ9���±꣬����±����ȫҪ��ֵΪ9
        int flag = str.size();
        //����λ�����ߵ�һλ�����޸ĵ�λ
        //�����λ<��λ����λ--����λ��Ϊ9
        for (int i = str.size() - 1; i > 0; i--) {
            if (str[i - 1] > str[i]) {
                flag = i;
                str[i - 1]--;
            }
        }
        for (int i = flag; i < str.size(); i++) {
            str[i] = '9';
        }
        return stoi(str);
    }
};