#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int getPivotIndex(vector<int> &arr, int startIndex, int endIndex) {
        int index = startIndex - 1, pivot = arr[endIndex];

        for (int i = startIndex; i < endIndex; i++) {
            if(arr[i] < pivot) {
                index++;
                swap(arr[i], arr[index]);
            }
        }
        index++;
        swap(arr[endIndex], arr[index]);
        return index;
    }

public:
    void quickSort(vector<int>& arr, int startIndex, int endIndex) {
        if(startIndex < endIndex) {
            int pivotIndex = getPivotIndex(arr, startIndex, endIndex);
            quickSort(arr, startIndex, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, endIndex);
        }
    }
};

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
    Solution solution;
    solution.quickSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Sample Input:
arr = {10, 80, 30, 90, 40, 50, 70}

Correct Output:
10 30 40 50 70 80 90
*/
