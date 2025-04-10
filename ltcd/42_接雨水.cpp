#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //单调栈，栈口到栈顶递增，存储下标
        stack<int> st;
        st.push(0);
        //承接雨水量
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            //情况1：当前柱子高度 <= 栈口
            if (height[i] <= height[st.top()]) {
                st.push(i);
            }
            //情况2：当前柱子高度 > 栈口
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    //取出栈顶元素，作为中间的柱子
                    int mid = st.top();
                    st.pop();
                    //如果栈不为空，说明可以形成凹槽接雨水
                    if (!st.empty()) {
                        //凹槽高度，该mid下标对应元素的左右更高柱子分别是当前柱子i和新栈口
                        int h = min(height[st.top()], height[i]) - height[mid];
                        //凹槽宽度
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