#include <stdio.h>
#include <stdlib.h>

//-------------------- NODE STRUCT ------------------------//
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

//-------------------- CLONE FUNCTION ---------------------//
struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    struct Node* curr = head;

    // Step 1: Insert copied nodes after originals
    while (curr) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->random = NULL;
        newNode->next = curr->next;

        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Assign random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate original and copied list
    curr = head;
    struct Node* newHead = head->next;
    struct Node* copy = newHead;

    while (curr) {
        curr->next = curr->next->next;
        if (copy->next)
            copy->next = copy->next->next;

        curr = curr->next;
        copy = copy->next;
    }

    return newHead;
}

//---------------------- UTILITIES ------------------------//

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    node->random = NULL;
    return node;
}

void printList(struct Node* head) {
    while(head) {
        printf("(%d , %d) -> ", head->val, head->random ? head->random->val : -1);
        head = head->next;
    }
    printf("NULL\n");
}


//---------------------- MAIN FOR VS CODE -----------------//
int main() {
    // Creating nodes manually
    struct Node *n1 = newNode(7);
    struct Node *n2 = newNode(13);
    struct Node *n3 = newNode(11);
    struct Node *n4 = newNode(10);
    struct Node *n5 = newNode(1);

    // Linking next pointers
    n1->next=n2; 
    n2->next=n3; 
    n3->next=n4; 
    n4->next=n5;

    // Setting random pointers
    n1->random=NULL;
    n2->random=n1;
    n3->random=n5;
    n4->random=n3;
    n5->random=n1;

    printf("Original List:\n");
    printList(n1);

    struct Node* cloned = copyRandomList(n1);

    printf("\nCloned List:\n");
    printList(cloned);

    return 0;
}
