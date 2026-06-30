class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        long long arrowPosition = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            int currentStart = points[i][0];
            int currentEnd = points[i][1];

            if (currentStart > arrowPosition) {
                arrows++;
                arrowPosition = currentEnd;
            }
        }

        return arrows;
    }
};