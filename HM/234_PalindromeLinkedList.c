#include <stdbool.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr) {
        struct ListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    // Find the midpoint of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *start = head;

    // Reverse the second half of the linked list
    struct ListNode *end = reverseList(slow);

    // Compare the first half and the reversed second half
    while (start && end) {
        if (start->val != end->val) {
            return false;
        }
        start = start->next;
        end = end->next;
    }

    return true;
}