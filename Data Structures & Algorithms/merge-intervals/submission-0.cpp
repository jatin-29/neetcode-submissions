class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};              // Bug 5 fix

        // sorting kar de — start time se
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {   // Bug 1 fix: no comma
                 return a[0] < b[0];
             });

        vector<vector<int>> res;                        // Bug 2 fix: >> not >
        res.push_back(intervals[0]);                     // current interval = [1,3]

        for (int i = 1; i < (int)intervals.size(); i++) { // Bug 4 fix: cast
            if (intervals[i][0] <= res.back()[1]) {
                // OVERLAP → haath wale tukde ko extend karo
                res.back()[1] = max(res.back()[1], intervals[i][1]);   // Bug 3 fix
            } else {
                // koi overlap nahi → haath khaali, naya utha lo
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};