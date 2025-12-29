#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Write logic here later
        return head;
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution s;
    head = s.removeNthFromEnd(head, 2);

    // Print list
    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
