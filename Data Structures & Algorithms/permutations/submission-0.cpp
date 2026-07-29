class Solution {

    void solve(vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& output,
               vector<bool>& used){

        if(temp.size()==nums.size()){
            output.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){

            if(used[i])
                continue;

            // Choose
            used[i]=true;
            temp.push_back(nums[i]);

            // Explore
            solve(nums,temp,output,used);

            // Undo
            temp.pop_back();
            used[i]=false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> temp;
        vector<vector<int>> output;

        vector<bool> used(nums.size(), false);

        solve(nums,temp,output,used);

        return output;
    }
};