#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* d_head = new ListNode();
        d_head->next = head;

        ListNode* cur = d_head;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode* del_node = cur->next;
                cur->next = cur->next->next;
                delete del_node;
            }
            else {
                cur = cur->next;
            }
        }
        return d_head->next;
    }
};