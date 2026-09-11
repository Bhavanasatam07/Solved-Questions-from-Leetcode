class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxarea = 0;
        int n = heights.size();
        for (int i =0 ; i < n; i++){
            while ( !st.empty() && heights[st.top()] >= heights[i]){
                int element = st.top(); 
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int area = heights[element] *( nse - pse -1);
                maxarea = max(maxarea , area);
            }
            st.push(i);
        }
            while(!st.empty()){
                int element = st.top();
                st.pop();
                int nse = n;
                int pse = st.empty() ? -1 : st.top();
                int area = heights[element] *( nse - pse -1);
                maxarea = max(maxarea , area);
            }
        return maxarea;
    }
};