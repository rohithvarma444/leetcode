class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        int totalN = n + m;
        int ind2 = (n + m) / 2;
        int ind1 = ind2 - 1;

        int cnt = 0;
        int i = 0;
        int j = 0;

        int ind2_val = -1;
        int ind1_val = -1;
        
        while(i< n && j<m){

            if(nums1[i] < nums2[j]){
                if (cnt == ind1) ind1_val = nums1[i];
                if(cnt == ind2) ind2_val = nums1[i];
                cnt++;
                i++;
            } 
            else{
                if(cnt == ind1) ind1_val = nums2[j];
                if(cnt ==ind2) ind2_val = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n){
            if (cnt == ind1) ind1_val = nums1[i];
            if(cnt == ind2) ind2_val = nums1[i];
            cnt++;
            i++;
        }

        while(j < m){
            if(cnt == ind1) ind1_val = nums2[j];
            if(cnt == ind2) ind2_val = nums2[j];
            cnt++;
            j++;
        }

        if(totalN%2 == 0){
            return (ind1_val + ind2_val) / (float) 2;
        }
        return ind2_val;

        
    }
};