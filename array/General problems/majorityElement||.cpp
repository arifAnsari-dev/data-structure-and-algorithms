/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 
*/


// This is the bruteforce approach to solve this problem 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> ans;
        for(auto possibleAns: nums) {
            int count = 0;

            for(auto element: nums) {
                if(element == possibleAns) {
                    count++;
                    if(count > nums.size()/3) {
                        ans.insert(possibleAns);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};


// Optimised Appraoch to solve this problem is (modified moore's voting algorithm )


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        int firstAns = -1, secondAns = -1;
        int firstCount = 0, secondCount = 0;

        for(auto element: nums) {
            if(element == firstAns) {
                firstCount++;
            } else if(element == secondAns) {
                secondCount++;
            } else if(firstCount == 0) {
                firstAns = element;
                firstCount = 1;
            } else if(secondCount == 0) {
                secondAns = element;
                secondCount = 1;
            } else {
                firstCount--;
                secondCount--;
            }
        }
        firstCount = 0, secondCount = 0;
        for(auto element: nums) {
            if(element == firstAns) {
                firstCount++;
            } else if(element == secondAns) {
                secondCount++;
            }
        }
        if(firstCount > nums.size()/3) {
            ans.push_back(firstAns);
        }
        if(secondCount > nums.size()/3) {
            ans.push_back(secondAns);
        }

        return ans;
    }
};