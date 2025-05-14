class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        map<int,int> mpp;
        int left = 0; 
        int right = 0;
        int ans = 0;


        while(right < n){
            mpp[fruits[right]]++;
            
            while(mpp.size() > 2 && left <= right){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};