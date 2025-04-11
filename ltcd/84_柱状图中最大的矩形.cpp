#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //单调栈，要找到下一个更低高度的下标，栈口到栈底递减
        stack<int> st;
        int res = 0;
        //前后插入0，方便处理边界情况
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0); //压入的是添加进来高度为0的第一个索引0
        for (int i = 1; i < heights.size(); i++) {
            //情况1：当前柱子高度≥栈顶柱子高度，插入下标
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            }
            //情况2：当前柱子高度＜栈顶柱子高度，循环处理
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    //栈顶元素为中间柱子的索引
                    int mid_idx = st.top();
                    st.pop();
                    //如果栈不为空
                    if (!st.empty()) {
                        //栈顶元素为左边更小的索引
                        int left = st.top();
                        //当前索引为右边更小的索引
                        int right = i;
                        //宽度高度
                        int w = right - left - 1;   //由于left、right都不符合条件，所以要减1
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