class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>dq;

        vector<int>ans;

        int n=nums.size();

        for(int i=0;i<n;i++){
            // i=0->1 [0]
            // i=1->3  [0,1]
            // i=2->-1 [1,2]


            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front(); // agr current window se bahar ke indeces to unhe remove kro 
            }


            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                //0<=3 to deque mei 3 hi push krdo 
                dq.pop_back();
            }

            dq.push_back(i);


            if(i>=k-1){
                // first window form record maximum 
                ans.push_back(nums[dq.front()]);
            }

           
        }
         return ans;
    }
};