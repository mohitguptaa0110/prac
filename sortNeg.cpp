#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(n);
    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
        
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    vector<int> arr = {4, -2, -3, 6, 1, -5, 2, 7, 9, -1};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
