#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //����ջ�洢�±꣬��֤����ջ��ջ�׵�ջ���ݼ�
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        //��ʼ������һ��Ԫ�ص��±�ѹջ
        st.push(0);
        //�ӵڶ���Ԫ�ؿ�ʼ�������Ƚ�temperatures[i]��ջ����ջ�ڣ�������ӦԪ��
        //���1��temperatures[i] < ջ��Ԫ�أ���ǰ�¶�û��ջ���ߣ�����ǰ����ѹջ
        //���2��temperatures[i] = ջ��Ԫ�أ���ǰ�¶ȵ���ջ�����������ڣ�ѹջ
        //���3��temperatures[i] > ջ��Ԫ�أ��ҵ��¶ȸ���ջ�������������ϸ���
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[st.top()]) st.push(i);
            else {
                //������С�ڵ�ǰ����temperatures[i]��ջ��Ԫ�س�ջ������res
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};