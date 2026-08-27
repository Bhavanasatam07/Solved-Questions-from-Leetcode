class Solution {
public:
    string minWindow(string s, string t) {

        int need[128] = {0};

        // t ki frequency
        for (char c : t) {
            need[c]++;
        }

        int l = 0;
        int count = 0;
        int start = 0;
        int minLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {

            
            if (need[s[r]] > 0) {
                count++;
            }
            need[s[r]]--;
            while (count == t.size()) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                need[s[l]]++;

                if (need[s[l]] > 0) {
                    count--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};