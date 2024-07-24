class Solution {
public:
    vector<int> findNSE(vector<int> &a){
        vector<int> ans(a.size(),0);
        stack<int> st;
        for(int i = a.size() - 1 ; i >= 0 ; i--){
            while(!st.empty() && a[st.top()] >= a[i]){
                st.pop(); 
            }
            ans[i] = st.empty()? a.size() : st.top();
            st.push(i);    
        }
        return ans;
    }
    
    vector<int> findPSEE(vector<int> &a){
        vector<int> ans(a.size(),0);
        stack<int> st;
        for(int i = 0 ; i < a.size() ; i++){
            while(!st.empty() && a[st.top()] > a[i]){
                st.pop(); 
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i);    
        }
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int total = 0 ;
        int mod = 1e9 + 7;
        for(int i = 0 ; i < n ; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};