class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b){
                 return a[0] < b[0];
             });

        vector<vector<int>> res;
        int count = 0;

        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {

            // No overlap
            if(intervals[i][0] >= res.back()[1]) {
                res.push_back(intervals[i]);
            }
            // Overlap
            else {
                count++;

                // Keep the interval with smaller ending point
                if(intervals[i][1] < res.back()[1]) {
                    res.back() = intervals[i];
                }
            }
        }

        return count;
    }
};