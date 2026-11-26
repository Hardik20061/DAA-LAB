/*
 * Question 33: Remove the N-th node from the end of a singly linked list.
 * Approach: Two Pointers (Fast & Slow) with Dummy Head Node
 * Time Complexity: O(L) - Single pass through the list of length L.
 * Space Complexity: O(1) - Constant pointer overhead.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* removeNthFromEnd(struct Node *head, int n) {
    // Dummy node simplifies edge cases like removing the first node
    struct Node dummy;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    // Advance fast pointer by n + 1 steps so gap between fast and slow is n
    for (int i = 0; i <= n; i++) {
        if (fast == NULL) return head; // n is larger than list length
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the target node to delete
    struct Node *toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    return dummy.next;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    printf("After removing %d-th from end: ", n);
    printList(head);
    return 0;
}
