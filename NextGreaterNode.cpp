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

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> values;
    for (ListNode* curr = head; curr; curr = curr->next)
        values.push_back(curr->val);

    vector<int> ans(values.size(), 0);
    stack<int> st; // store indices

    for (int i = 0; i < values.size(); i++) {
        while (!st.empty() && values[i] > values[st.top()]) {
            ans[st.top()] = values[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main() {
    // Example: [2,7,4,3,5]
    ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    vector<int> result = nextLargerNodes(head);

    for (int x : result)
        cout << x << " ";

    return 0;
}
