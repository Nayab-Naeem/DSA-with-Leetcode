/*Problem Description: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

/*
Problem       : Add Two Numbers
Platform      : LeetCode
Difficulty    : Medium
Topic         : Linked List
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(n)
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* Head = new ListNode(0); // dummy node
        ListNode* current = Head;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = x + y + carry;
            carry = sum / 10; 
            int digit = sum % 10;
            
            current->next = new ListNode(digit); // create new node
            current = current->next;
            
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return Head->next; 
    }
};