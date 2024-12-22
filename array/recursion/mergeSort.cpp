#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Implementation of the merge function 
    void merge(vector<int> &arr, int startIndex, int midIndex, int endIndex) {
        
    }


    void mergeSort(vector<int>& arr, int startIndex, int endIndex) {
        // Implement the merge sort logic here
        if(startIndex < endIndex) {
            int midIndex = startIndex + (endIndex - startIndex) / 2;

            mergeSort(arr, startIndex, midIndex - 1);
            mergeSort(arr, midIndex + 1, endIndex);

            merge(arr, startIndex, midIndex, endIndex);
        }
    }
};

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    Solution solution;
    solution.mergeSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Sample Input:
arr = {38, 27, 43, 3, 9, 82, 10}

Correct Output:
3 9 10 27 38 43 82
*/
