#include <iostream>
#include <string>
#include <stack>
using namespace std; 

class Solution {
public:
    bool isValid(string s) {
        //ºÙ÷¶
        if (s.size() % 2) return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else if (st.empty() || s[i] != st.top()) return false;
            else st.pop();  //∆•≈‰≥…π¶, pop’ª∂•
        }
        return st.empty();
    }
};