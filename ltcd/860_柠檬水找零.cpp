#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& b : bills) {
            if (b == 5) five += 1;
            else if (b == 10) {
                if (five < 1) return false;
                five--;
                ten++;
            }
            else if (b == 20) {
                //优先消耗10元，因为如果只剩10元，找零5元时会返回false
                if (five >= 1 && ten >= 1) {
                    five--; ten--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};