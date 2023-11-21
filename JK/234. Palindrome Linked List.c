#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct ListNode {
      int val;
      struct ListNode *next;
 };


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    
    slow = reverseList(slow);
    fast = head;

    while (slow != NULL) {
        if (slow->val != fast->val) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}


void append(struct ListNode **head, int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}



// 첫 번째 메인 함수 (정의된 리스트 사용)
int main() {
    struct ListNode *head = NULL;

    // 리스트 생성: 1 -> 2 -> 2 -> 1
    append(&head, 1);
    append(&head, 2);
    append(&head, 2);
    append(&head, 1);

    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    // 메모리 해제
    struct ListNode *current = head;
    struct ListNode *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}


// 두 번째 메인 함수 (사용자 입력으로 리스트 생성)
int main() {
    struct ListNode *head = NULL;
    int n, val;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        append(&head, val);
    }

    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    // 메모리 해제
    struct ListNode *current = head;
    struct ListNode *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}