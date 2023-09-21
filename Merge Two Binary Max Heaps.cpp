/*You are given two integer arrays ‘ARR1’ and ‘ARR2’ of size ‘N’ and ‘M’ respectively, Both ‘ARR1’ and ‘ARR2’ represent a Max-Heap. 
Your task is to merge the two arrays firstly keep all the elements of the ‘ARR1’ (without changing order) 
than elements of array ‘ARR2’ (without changing order), 
and then find the Max-Heap obtained by merging arrays.
Print an array of sizes ‘N + M’, representing the Max-Heap obtained after merging. */




#include <bits/stdc++.h>

void heapify(vector<int> &arr, int n, int i) {
    // 0-based indexing
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, std::vector<int> &arr2) {
    vector<int> ans;
    for (auto i : arr1) {
        ans.push_back(i);
    }
    for (auto i : arr2) {
        ans.push_back(i);
    }

    int size = ans.size();

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, size, i);
    }

    return ans;
}
