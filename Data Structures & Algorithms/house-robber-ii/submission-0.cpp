class Solution {
private:
    int rob1(vector<int>& nums) {      // <- nested class hata di
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> first;
        vector<int> second;

        // first house include, last exclude
        for(int i = 0; i < n-1; i++)
            first.push_back(nums[i]);

        // first exclude, last include
        for(int i = 1; i < n; i++)
            second.push_back(nums[i]);

        return max(rob1(first), rob1(second));
    }
};