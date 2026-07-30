class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1) return 0;




        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });


        long long lastEnd=LLONG_MIN;


        int kept=0;
        for(auto& party: intervals){
            if(party[0]>=lastEnd){
                kept++;
                lastEnd=party[1];
            }
        }
        return n-kept;
    }
};
