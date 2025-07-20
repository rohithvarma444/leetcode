class Solution {
public:
    void findNSE(vector<int> &arr, vector<int> &nse,int n){
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty()? n: st.top();
            st.push(i);
        }
    }

    void findPSE(vector<int> &arr,vector<int> &pse,int n){
        stack<int> st;
        for(int i =0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty()? -1: st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n,-1),pse(n,-1);
        findNSE(arr,nse,n);
        findPSE(arr,pse,n);

        long long  totalSum = 0;
        long long mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int leftOcc = i - pse[i];
            int rightOcc = nse[i] - i;

            totalSum += ((leftOcc * rightOcc)%mod * arr[i] )%mod;
            totalSum %= mod;
        }

        return totalSum;
    }
};