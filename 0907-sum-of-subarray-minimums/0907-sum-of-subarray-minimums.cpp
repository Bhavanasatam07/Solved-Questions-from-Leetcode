class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
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

            ans = (ans + arr[i] * leftChoices * rightChoices) % MOD;
        }

        return ans;
    }
};