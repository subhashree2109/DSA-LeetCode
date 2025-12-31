#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Create new node
ListNode* newNode(int value){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = NULL, *tail = NULL;
    int carry = 0;

    while(l1 || l2 || carry){
        int sum = carry;
        
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        ListNode* node = newNode(sum % 10);

        if(!head){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

// Utility function to print list
void printList(ListNode* head){
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// TEST
int main(){
    // l1 = [2,4,3]
    ListNode* l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    // l2 = [5,6,4]
    ListNode* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    ListNode* result = addTwoNumbers(l1, l2);

    printf("Output: ");
    printList(result);  // Expected -> 7 0 8

    return 0;
}
