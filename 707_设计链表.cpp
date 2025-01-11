#include <iostream>

using namespace std; 

class MyLinkedList {

private:
    struct LNode {
        int val;
        LNode* next;
        LNode(int val = 0) : val(val), next(nullptr) {};
    };

    int size;
    LNode* d_head;

    void print() {
        // LNode* cur = d_head;
        // while(cur->next){
        //     cout << cur->next->val << " ";
        //     cur = cur->next;
        // }
        // cout << "[" << size << "]" << endl;
    };
public:
    MyLinkedList() {
        d_head = new LNode();
        size = 0;
    }

    int get(int index) {
        if (index > size - 1 || index < 0) {
            return -1;
        }
        LNode* cur = d_head->next;
        while (index--) {
            cur = cur->next;
        }

        print();

        return cur->val;
    }

    void addAtHead(int val) {
        LNode* new_node = new LNode(val);
        new_node->next = d_head->next;
        d_head->next = new_node;

        size++;
        print();

        return;
    }

    void addAtTail(int val) {
        LNode* cur = d_head;
        while (cur->next) {
            cur = cur->next;
        }

        LNode* new_node = new LNode(val);
        new_node->next = cur->next;
        cur->next = new_node;

        size++;
        print();

        return;
    }

    void addAtIndex(int index, int val) {
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index > size - 1 || index < 0) {
            return;
        }
        LNode* cur = d_head;
        while (index--) {
            cur = cur->next;
        }

        LNode* new_node = new LNode(val);
        new_node->next = cur->next;
        cur->next = new_node;

        size++;
        print();

        return;
    }

    void deleteAtIndex(int index) {
        if (index > size - 1 || index < 0) {
            return;
        }
        LNode* cur = d_head;
        while (index--) {
            cur = cur->next;
        }

        LNode* del_node = cur->next;
        cur->next = cur->next->next;
        delete del_node;

        size--;
        print();

        return;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */