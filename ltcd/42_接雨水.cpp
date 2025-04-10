#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //����ջ��ջ�ڵ�ջ���������洢�±�
        stack<int> st;
        st.push(0);
        //�н���ˮ��
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            //���1����ǰ���Ӹ߶� <= ջ��
            if (height[i] <= height[st.top()]) {
                st.push(i);
            }
            //���2����ǰ���Ӹ߶� > ջ��
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    //ȡ��ջ��Ԫ�أ���Ϊ�м������
                    int mid = st.top();
                    st.pop();
                    //���ջ��Ϊ�գ�˵�������γɰ��۽���ˮ
                    if (!st.empty()) {
                        //���۸߶ȣ���mid�±��ӦԪ�ص����Ҹ������ӷֱ��ǵ�ǰ����i����ջ��
                        int h = min(height[st.top()], height[i]) - height[mid];
                        //���ۿ��
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
            }
            st.push(i);
        }
        return sum;
    }
};