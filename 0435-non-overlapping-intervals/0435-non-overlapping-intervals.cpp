class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int n = intervals.size();

        int count = 1;                  // first interval taken
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int currentStart = intervals[i][0];

            if (currentStart >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return n - count;
    }
};