/* Given an array arr[] and an integer K where K is smaller than the size of the array, 
the task is to find the Kth smallest element in the given array. It is shown that all array elements are distinct.

Note:-  l and r denotes the starting and ending index of the array. */

// using PriorityQueue T.C.== O(N)

#include <bits/stdc++.h> 

int kthSmallest(vector<int>& arr, int n, int k) {

    priority_queue<int> pq;

    for(int i=0; i<k; i++){

        pq.push(arr[i]);

    }

    for(int i=k; i<n; i++){

        if(arr[i] < pq.top()){

            pq.pop();

            pq.push(arr[i]);

        }

    }

    return pq.top();

} 

 

/*

// sorting

int kthSmallest(int n,int k,vector<int> arr){

    sort(arr.begin(), arr.end());

    return arr[k-1];

// T.C.== O(NlogN)
}

*/
