/*
===========================================================
Problem Description
-----------------------------------------------------------
Given the head of a sorted linked list, remove duplicate
nodes so that each element appears only once.

Return the modified linked list.
===========================================================

Problem        : Remove Duplicates from Sorted List
Platform       : LeetCode 83
Difficulty     : Easy
Topic          : Linked List
Language       : C++
Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:

    /*
    ===========================================================
    Approach: Single Traversal (Linked List Traversal)

    Observation:
    Since the list is sorted, duplicate values appear
    consecutively.

    Algorithm:
    1. Set pointer current = head.
    2. Traverse while current and current->next exist.
    3. If current->val == current->next->val:
           remove current->next
           current->next = current->next->next
       else:
           move current = current->next
    4. Return head.

    Why It Works:
    - Sorted order ensures duplicates are adjacent.
    - We only adjust pointers to skip duplicate nodes.

    Time Complexity: O(n)
    Space Complexity: O(1)
    ===========================================================
    */

    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;

        while(current != NULL && current->next != NULL) {

            if(current->val == current->next->val) {
                current->next = current->next->next;
            }
            else {
                current = current->next;
            }

        }

        return head;
    }
};