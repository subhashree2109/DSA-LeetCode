#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // TODO: Implement logic
        return NULL;
    }
};

int main() {
    // Quick check - empty input
    vector<ListNode*> lists;

    Solution s;
    ListNode* result = s.mergeKLists(lists);

    if(result == NULL) cout << "Merged list is empty" << endl;
    return 0;
}
