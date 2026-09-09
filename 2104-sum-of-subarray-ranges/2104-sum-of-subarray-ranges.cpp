class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        long long ans = 0;

        vector<int> left(n), right(n);
        stack<int> st;

        // =========================
        // SUM OF MAXIMUMS
        // =========================

        // Previous Greater
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        // Add maximum contribution
        for (int i = 0; i < n; i++) {

            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            ans += 1LL * nums[i] * leftChoices * rightChoices;
        }


        // =========================
        // SUM OF MINIMUMS
        // =========================

        while (!st.empty())
            st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        
        for (int i = 0; i < n; i++) {

            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            ans -= 1LL * nums[i] * leftChoices * rightChoices;
        }

        return ans;
    }
};