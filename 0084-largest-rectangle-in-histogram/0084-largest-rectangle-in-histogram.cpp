class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int element = 0;
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * heights[element]);
        }
        return maxArea;
    }
};