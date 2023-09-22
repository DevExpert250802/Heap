/*   You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/lists such that the output array/list should be sorted in ascending order.*/
#include <bits/stdc++.h> 
 vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {   
       vector<int>ans;   

       for(int i=0;i<k;i++){ 

            for(int j=0;j<kArrays[i].size();j++){

                  ans.push_back(kArrays[i][j]);       
             }
       }    
       sort(ans.begin(),ans.end());    

       return ans; 
}  

// T.C. =  O(K * N)
// S.C. = O(N * k)

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Approach 2

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
     vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i<k;i++) {
            for(int j = 0;j<kArrays[i].size();j++) {
                pq.push(kArrays[i][j]);
            }
        }
         while (!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
}

// T.C. = O(k * N * log M)
// S.C. = O(N * k)



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Approach 3


#include <bits/stdc++.h> 

class node {
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    } 
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    // Initialize a min-heap of node pointers
   priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1: Insert the first element of each array into the minHeap
    for (int i = 0; i < k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2: While minHeap is not empty
    while (!minHeap.empty()) {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        // If there's a next element in the same array, push it to the minHeap
        if (j + 1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}


// T.C. = O(N * log M)
// S.C. = O(N)
