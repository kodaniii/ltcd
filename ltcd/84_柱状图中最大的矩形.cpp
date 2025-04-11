#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //����ջ��Ҫ�ҵ���һ�����͸߶ȵ��±꣬ջ�ڵ�ջ�׵ݼ�
        stack<int> st;
        int res = 0;
        //ǰ�����0�����㴦��߽����
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0); //ѹ�������ӽ����߶�Ϊ0�ĵ�һ������0
        for (int i = 1; i < heights.size(); i++) {
            //���1����ǰ���Ӹ߶ȡ�ջ�����Ӹ߶ȣ������±�
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            }
            //���2����ǰ���Ӹ߶ȣ�ջ�����Ӹ߶ȣ�ѭ������
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    //ջ��Ԫ��Ϊ�м����ӵ�����
                    int mid_idx = st.top();
                    st.pop();
                    //���ջ��Ϊ��
                    if (!st.empty()) {
                        //ջ��Ԫ��Ϊ��߸�С������
                        int left = st.top();
                        //��ǰ����Ϊ�ұ߸�С������
                        int right = i;
                        //��ȸ߶�
                        int w = right - left - 1;   //����left��right������������������Ҫ��1
                        int h = heights[mid_idx];
                        res = max(res, w * h);
                    }
                }
                st.push(i);
            }
        }
        return res;
    }
};