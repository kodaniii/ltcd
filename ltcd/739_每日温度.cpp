#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈存储下标，保证单调栈从栈底到栈顶递减
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        //初始化：第一个元素的下标压栈
        st.push(0);
        //从第二个元素开始遍历，比较temperatures[i]和栈顶（栈口）索引对应元素
        //情况1：temperatures[i] < 栈顶元素，当前温度没有栈顶高，将当前索引压栈
        //情况2：temperatures[i] = 栈顶元素，当前温度等于栈顶，但不高于，压栈
        //情况3：temperatures[i] > 栈顶元素，找到温度高于栈顶的索引，不断更新
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[st.top()]) st.push(i);
            else {
                //将所有小于当前气温temperatures[i]的栈内元素出栈并更新res
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