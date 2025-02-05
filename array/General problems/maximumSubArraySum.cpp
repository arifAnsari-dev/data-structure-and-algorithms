
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.


BruteForce approach to solve this problem 

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int globalMaxima = INT_MIN;
        
        for(int start = 0; start < arr.size(); start++) {
            int currentSum = 0;
            for(int end = start; end < arr.size(); end++) {
                currentSum += arr[end];
                if(currentSum > globalMaxima) {
                    globalMaxima = currentSum;
                }
            }
        }
        return globalMaxima;
    }
};

// Optimised approach to solve this problem (kadane's algorithm)

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int currentMaxima = 0, globalMaxima = INT_MIN;
        int start = 0, end = 0;
        int tempStart = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(currentMaxima + arr[i] > arr[i]) {
                currentMaxima += arr[i];
            } else {
                currentMaxima = arr[i];
                tempStart = i;
            }
            
            if(globalMaxima < currentMaxima) {
                globalMaxima = currentMaxima;
                start = tempStart;
                end = i;
            }
        }
        // Print the start and the end iNdex(start, end)
        return globalMaxima;
    }

// For just finding the maxSubArray sum, it can be written as following

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int currentMaxima = 0, globalMaxima = INT_MIN;
        
        for(auto element: arr) {
            currentMaxima = max(currentMaxima + element, element);
            globalMaxima = max(currentMaxima, globalMaxima);
        }
        return globalMaxima;
    }
};



// Another way (just a bit different implementation of the same appraoch)

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int globalMaxima = INT_MIN, currentMaxima = 0;
        int start = 0, end = 0;
        int tempStart = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            currentMaxima += arr[i];
            if(currentMaxima > globalMaxima) {
                globalMaxima = currentMaxima;
                start = tempStart;
                end = i;
            }
            
            if(currentMaxima < 0) {
                currentMaxima = 0;
                tempStart = i;
            }
        }
        // cout << start << end << endl;
        return globalMaxima;
    }
};