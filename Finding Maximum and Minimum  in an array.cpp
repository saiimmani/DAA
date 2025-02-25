#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Finding Maximum and Minimum in an Array
pair<int, int> findMinMax(vector<int>& arr) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int num : arr) {
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }
    return {minVal, maxVal};
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    pair<int, int> minMax = findMinMax(arr);
    cout << "Minimum: " << minMax.first << "\nMaximum: " << minMax.second << endl;
    return 0;
}
