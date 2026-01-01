#include <bits/stdc++.h>
using namespace std;

//----------------- List + Tree Definitions -----------------//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//---------------------- SOLUTION ---------------------------//
class Solution {
public:
    TreeNode* build(ListNode*& head, int n){
        if(n <= 0) return NULL;

        TreeNode* left = build(head, n/2);

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        root->left = left;
        root->right = build(head, n - n/2 - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while(temp){ 
            n++; 
            temp = temp->next;
        }

        return build(head, n);
    }
};


//---------------------- UTILITY ----------------------------//
void printInorder(TreeNode* root){
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

ListNode* createList(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i=1;i<arr.size();i++){
        temp->next = new ListNode(arr[i]);
        temp=temp->next;
    }
    return head;
}


//----------------------- TEST MAIN --------------------------//
int main(){
    // sorted linked list input
    vector<int> arr = {-10,-3,0,5,9};
    ListNode* head = createList(arr);

    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);

    cout << "Inorder Traversal (should be sorted): ";
    printInorder(root);
    cout << endl;

    return 0;
}
