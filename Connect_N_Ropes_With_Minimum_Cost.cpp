/*  Given are N ropes of different lengths, the task is to connect these ropes into one rope with minimum cost, such that the cost to connect two ropes is equal to the sum of their lengths. */

long long connectRopes(int* arr, int n)

{
    long long int ans=0;
    priority_queue<int, vector<int>, greater<int>>pq;

    if(n==1) return ans;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    while(!pq.empty())
    {

        int first= pq.top();
        pq.pop();

        int second =pq.top();
        pq.pop();

        int sum= first+second;
        ans+=sum;

        if(pq.empty())break;
        pq.push(sum);
    }
    return ans;
}

// Time Complexity: O(N*log(N))
// Auxiliary Space: O(N)
