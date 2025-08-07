class Solution {
public:
    int helper(int n, vector<int> &bloom, int k){
    int bouquets = 0;
    int flowers = 0; 

    for(auto it: bloom){
        if(it <= n) { 
            flowers++;
            if(flowers == k) { 
                bouquets++;
                flowers = 0; 
            }
        } else {
            flowers = 0; 
        }
    }

    return bouquets;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = 1;
        int right = 0;
        for(auto it: bloomDay){
            right = max(right,it);
        }

        int ans = -1;

        while(left <= right){
            int mid = (left + right)/2;
            
            if(helper(mid,bloomDay,k) >= m){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return ans;
    }
};