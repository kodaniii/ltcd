#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*×ó±ÕÓÒ±Õ*/
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        /*×ó±ÕÓÒ¿ª*/
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};