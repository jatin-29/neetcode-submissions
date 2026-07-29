class Solution {
    private:
    void solve(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans, int start){
        if(target==0){
         ans.push_back(temp);
         return;
        }


        for(int i=start; i<nums.size();i++){
            if(nums[i]>target) break;


            if(i>start && nums[i]==nums[i-1]) continue;
 
            // choose 
            temp.push_back(nums[i]);
            solve(nums,target-nums[i],temp,ans,i+1);

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),
             candidates.end());

        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(candidates,target,temp,ans,0);
        return ans;
    }
};
