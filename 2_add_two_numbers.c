// Question: https://leetcode.com/problems/add-two-numbers
// Solution: Using tail pointers to maintain current position in each of the linked lists. The result at each point is the sum of the current digits and previous carry. 
// Time complexity: O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *newnode(int x){
        struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newnode -> val = x;
        newnode -> next = NULL;
        return newnode;
    }

    struct ListNode *head = NULL;
    int carry = 0;
    struct ListNode *p;
    while(l1 != NULL && l2 != NULL){
        int val = (l1->val + l2->val + carry);
        if (head == NULL){
            head = p = newnode(val%10);
        }
        else{
            struct ListNode *temp = newnode((val%10));
            p->next = temp;
            p = p->next;
        }
        carry = val / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL){
        int val = (l1->val + carry);
        if (head == NULL){
            head = p = newnode(val%10);
        }
        else{
            p->next = newnode(val%10);
            p = p->next;
        }
        carry = val / 10;
        l1 = l1->next;
    }
    while (l2 != NULL){
        int val = (l2->val + carry);
        if (head == NULL){
            head = p = newnode(val%10);
        }
        else{
            p->next = newnode(val%10);
            p = p->next;
        }
        carry = val / 10;
        l2 = l2->next;
    }
    if (carry != 0)
        p->next = newnode(carry);
    return head;
}