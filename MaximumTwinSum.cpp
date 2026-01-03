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

int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* second = reverseList(slow);

    int maxSum = 0;
    ListNode* first = head;

    // Calculate twin sums
    while (second) {
        maxSum = max(maxSum, first->val + second->val);
        first = first->next;
        second = second->next;
    }

    return maxSum;
}

int main() {
    // Example: [4,2,2,3]
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    cout << "Maximum Twin Sum: " << pairSum(head) << endl;
    return 0;
}
