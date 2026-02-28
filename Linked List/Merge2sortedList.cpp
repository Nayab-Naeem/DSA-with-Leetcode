/*
Problem: Merge Two Sorted Lists
Platform: LeetCode problem  21 
Difficulty: Easy
Topic: Linked List, Two Pointers
Language: C++
Time Complexity: O(n + m)
Space Complexity: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode newNode;
        ListNode* tail = &newNode;
    
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        
        return newNode.next;
    }
};
        