class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        

        // kth largest element can be find using maxHeap 

         priority_queue<int, vector<int>, greater<int>> pq;

        for(auto num:nums){
            pq.push(num);


            if(pq.size()>k)  pq.pop();
        }

        return pq.top();
    }
};
