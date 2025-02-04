
Problem statement
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]



// Brute Force approach to solve this problem is 

#include <algorithm>
#include <numeric>

// Implementation of the calculateCandidate function 
int calculateCandidate(int maxAllowedPages, vector<int> &arr) {
    int candidate = 1, pageAllocated = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(pageAllocated + arr[i] <= maxAllowedPages) {
            pageAllocated += arr[i];
        } else {
            candidate++;
            pageAllocated = arr[i];
        }
    }
    return candidate;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(n < m) {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    for(int i = low; i <= high; i++) {
        int candidate = calculateCandidate(i, arr);
        if(candidate <= m) {
            return i;
        }
    }
    return -1;
}


// Optimised apporach to solve this problem(binary search on answers)

#include <algorithm>
#include <numeric>

// Implementation of the calculateCandidate function 
int calculateCandidate(int maxAllowedPages, vector<int> &arr) {
    int candidate = 1, pageAllocated = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(pageAllocated + arr[i] <= maxAllowedPages) {
            pageAllocated += arr[i];
        } else {
            candidate++;
            pageAllocated = arr[i];
        }
    }
    return candidate;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(n < m) {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        int candidate = calculateCandidate(mid, arr);
        
        if(candidate <= m) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}