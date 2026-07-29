class Solution {
    private:
    void solve(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans, int start){
        if(target==0){
         ans.push_back(temp);
         return;
        }


        for(int i=start; i<nums.size();i++){
            if(nums[i]>target) break;

            // choose 
            temp.push_back(nums[i]);
            solve(nums,target-nums[i],temp,ans,i);

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
sort(nums.begin(),
             nums.end());

        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(nums,target,temp,ans,0);
        return ans;
        
    }
};
