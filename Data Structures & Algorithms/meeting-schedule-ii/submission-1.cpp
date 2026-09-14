class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = 0;

        for(auto meetings : intervals) {

            int start = meetings.start;
            int end = meetings.end;

            if(!pq.empty() && pq.top() <= start) {
                pq.pop();
            }

            pq.push(end);

            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};