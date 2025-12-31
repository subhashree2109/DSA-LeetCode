#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void insert(Node **list, int num) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->num = num;
    newnode->next = NULL;

    if (*list == NULL) {
        *list = newnode;
        return;
    }
    
    Node *temp = *list;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}

Node* deleteDuplicates(Node *list) {
    if (!list) return NULL;

    Node *temp = list;
    Node *newList = NULL;
    int duplicate = -200;  // Some value not present in linked list

    while (temp) {
        if (temp->next && temp->num == temp->next->num) {
            duplicate = temp->num;  // Mark as duplicate
        } 
        else if (temp->num != duplicate) {
            insert(&newList, temp->num); // Insert only unique numbers
        }
        temp = temp->next;
    }

    return newList;
}

void printList(Node *head) {
    while (head) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

int main(){
    Node *list=NULL;

    // Example: sorted duplicate list
    insert(&list,1);
    insert(&list,2);
    insert(&list,3);
    insert(&list,3);
    insert(&list,4);
    insert(&list,4);
    insert(&list,5);

    printf("Original list: ");
    printList(list);

    Node *result = deleteDuplicates(list);

    printf("After removing duplicates: ");
    printList(result);
}
