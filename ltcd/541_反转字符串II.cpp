#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            //本次遍历满足k个，全部reverse
            //abc, k=3
            if (i + k <= s.size()) {
                reverse(s, i, i + k);
            }
            //不足k个
            else {
                reverse(s, i, s.size());
            }
        }

        return s;
    }

private:
    void reverse(string& s, int idx_l, int idx_r) {
        //cout << "reverse: " << idx_l << " " << idx_r << endl;
        for (int left = idx_l, right = idx_r - 1; left < (idx_l + idx_r) / 2; left++, right--) {
            swap(s[left], s[right]);
            //cout << "swap: " << s[left] << " " << s[right] << endl;
        }
    }
};