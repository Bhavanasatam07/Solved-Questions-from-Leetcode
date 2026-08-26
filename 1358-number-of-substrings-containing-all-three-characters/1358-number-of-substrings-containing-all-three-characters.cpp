class Solution {
public:
    int numberOfSubstrings(string s) {

        int last[3] = {-1, -1, -1};
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            last[s[r] - 'a'] = r;

            int mini = min({last[0], last[1], last[2]});

            ans += mini + 1;
        }

        return ans;
    }
};