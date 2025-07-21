class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

       
        int currMax = height[0];

        for(int i = 0; i < n; i++){
            currMax = max(currMax,height[i]);
            prefixMax[i] = currMax;
        }

        currMax = height[n-1];
        for(int i = n-1; i >= 0; i--){
            currMax = max(currMax,height[i]);
            suffixMax[i] = currMax;
        }

        int totalWater = 0;

        for(int i = 0; i < n; i++){
            int currWater = min(prefixMax[i],suffixMax[i]) - height[i];
            if(currWater > 0) totalWater += currWater;
        }

        return totalWater;
    }
};