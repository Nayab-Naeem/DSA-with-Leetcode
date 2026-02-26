/*---------------------------------------------------------------
Problem         : 1404. Number of Steps to Reduce a Number in Binary Representation to One
Platform        : LeetCode
Difficulty      : Medium
Topic           : String, Simulation, Binary Arithmetic
Language        : C++
Time Complexity : O(n)
Space Complexity: O(1)
===============================================================*/
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Start from rightmost bit and move left
        for (int i = s.length() - 1; i > 0; i--) {     //checking the last bit
            
            int bit = (s[i] - '0') + carry;   //converting into integer and adding

            if (bit % 2 == 0) {
                // Even → divide by 2
                steps += 1;
            } else {
                // Odd → add 1 + divide by 2
                steps += 2;
                carry = 1;
            }
        }

        // If carry remains at MSB
        if (carry == 1) {
            steps += 1;
        }

        return steps;
    }
};