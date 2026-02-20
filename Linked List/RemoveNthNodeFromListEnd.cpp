/* 
Problem Description:
Given the head of a linked list, remove the nth node from the end 
of the list and return its head.
*/

/*
Problem       : 19. Remove Nth Node From End of List
Platform      : LeetCode
Difficulty    : Medium
Topic         : Linked List, Two Pointers
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(1)
*/
/** * Definition for singly-linked list. * struct ListNode { * int val; * ListNode *next; * ListNode() : val(0), next(nullptr) {} * ListNode(int x) : val(x), next(nullptr) {} * ListNode(int x, ListNode *next) : val(x), next(next) {} * }; */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count total nodes
        int sz = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            sz++;
            temp = temp->next;
        }
        
        // Step 2: Remove head if needed
        if (n == sz) {
            ListNode* newHead = head->next;
            delete head;  // optional
            return newHead;
        }
        
        // Step 3: Find node before target
        ListNode* prev = head;
        for (int i = 1; i < sz - n; i++) {
            prev = prev->next;
        }
        
        // Step 4: Remove target node
        ListNode* toDelete = prev->next;
        prev->next = prev->next->next;
        delete toDelete;  // optional
        
        return head;
    }
};