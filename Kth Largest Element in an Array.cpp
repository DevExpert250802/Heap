/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?*/


class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }

        for(int i=k; i<arr.size(); i++){
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};
