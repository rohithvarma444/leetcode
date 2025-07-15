class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int vote = 0;
        int candidate = 0;

        for(int i =0 ;i < n; i++){
            if(vote == 0){
                candidate = nums[i];
                vote = 1;
            }
            else{
                if(candidate == nums[i]){
                    vote++;
                }
                else{
                    vote--;
                }
            }
        }


        return candidate;
    }
};