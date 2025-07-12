class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int leftSum = 0;
        int rightSum = 0;
        int totalSum = 0;
        int maxSum = 0;
        for(int i = 0; i<k;i++){
            leftSum += cardPoints[i];
        }
        totalSum = leftSum;
        int rightIndex = n-1;
        
        for(int i = k-1; i>=0; i--){

            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            totalSum = max(totalSum, leftSum + rightSum);
            rightIndex--;
        }

        return totalSum;
    }
};