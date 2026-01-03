#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* partition(ListNode* head, int x) {
    ListNode dummyLess(0), dummyGreater(0);
    ListNode* less = &dummyLess;
    ListNode* greater = &dummyGreater;

    while (head) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    // Important to avoid cycle
    greater->next = NULL;
    less->next = dummyGreater.next;

    return dummyLess.next;
}

int main() {
    // Example: [1,4,3,2,5,2], x = 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    head = partition(head, x);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
