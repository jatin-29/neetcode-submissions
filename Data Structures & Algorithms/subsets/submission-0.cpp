class Solution {

    private:
    void solve(vector<int>&nums, vector<vector<int>>&output, vector<int>&ans, int index){
        //base case 
        if(index>=nums.size()){
            output.push_back(ans);
            return;
        }

        // Exclude
        solve(nums,output,ans,index+1);


        // include
        ans.push_back(nums[index]);
        solve(nums,output,ans,index+1);


        ans.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        

        vector<vector<int>>output;
        vector<int>ans;
        int index=0;
        solve(nums,output,ans,index);

        return output;

    }
};
