/* 
Problem Description (LeetCode Problem 401):
A binary watch has 4 LEDs to represent hours (0–11) 
and 6 LEDs to represent minutes (0–59).
Given an integer turnedOn representing the number of LEDs that are currently ON,
return all possible valid times the watch could represent.
Rules:
- Hour must not contain a leading zero.
- Minute must always be two digits (can contain leading zero).
*/
/*
Problem       : Binary Watch problem 401
Platform      : LeetCode
Difficulty    : Easy
Topic         : Bit Manipulation / Enumeration
Language      : C++
Time Complexity  : O(12 × 60) ≈ O(1)
Space Complexity : O(1)  // excluding output storage
*/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string> result;
        
        // Try every possible hour (0–11)
        for(int hour = 0; hour < 12; hour++) {
            
            // Try every possible minute (0–59)
            for(int minute = 0; minute < 60; minute++) {
                
                // Count total number of LEDs that are ON
                int totalBits = __builtin_popcount(hour) + 
                                __builtin_popcount(minute);
                
                // If it matches required turnedOn LEDs
                if(totalBits == turnedOn) {
                    
                    string time = to_string(hour) + ":";
                    
                    // Ensure minute has two digits
                    if(minute < 10)
                        time += "0";
                    
                    time += to_string(minute);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};
