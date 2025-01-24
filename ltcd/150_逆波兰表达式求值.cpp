#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                auto num2 = st.top(); st.pop();
                auto num1 = st.top(); st.pop();
                if (tokens[i] == "+") st.push(num1 + num2);
                if (tokens[i] == "-") st.push(num1 - num2);
                if (tokens[i] == "*") st.push(num1 * num2);
                if (tokens[i] == "/") st.push(num1 / num2);
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }

        return st.top();
    }
};