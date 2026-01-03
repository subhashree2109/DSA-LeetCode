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

// Reverse linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    // Reverse list
    head = reverseList(head);

    int maxVal = 0;
    ListNode* curr = head;
    ListNode* prev = NULL;

    while (curr) {
        if (curr->val >= maxVal) {
            maxVal = curr->val;
            prev = curr;
        } else {
            prev->next = curr->next;
        }
        curr = curr->next;
    }

    // Reverse back
    return reverseList(head);
}

int main() {
    // Example: [5,2,13,3,8]
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    head = removeNodes(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
