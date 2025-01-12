#include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* d_head = new ListNode(0, head);
        
        ListNode* cur = d_head;
        
        while (cur->next && cur->next->next) {
            ListNode* tmp = cur->next;
            ListNode* tmp_next_head = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            tmp->next = tmp_next_head;

            cur = tmp;
        }

        return d_head->next;
    }
};

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