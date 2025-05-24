class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break;

                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                waterTrapped += distance * boundedHeight;
            }
            st.push(i);
        }

        return waterTrapped;
    }
};