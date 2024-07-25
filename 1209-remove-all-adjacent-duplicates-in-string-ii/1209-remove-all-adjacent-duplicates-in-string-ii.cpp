class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;
            } else {
                st.push({ch, 1});
            }
            if (st.top().second == k) {
                st.pop();
            }
        }
        string ans;
        while (!st.empty()) {
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         stack<pair<char,int>> st;
//         for(int i = 0 ; i < s.length() ; i++){
//             if(st.empty()) st.push({s[i],1});
//             else if(st.top().first == s[i]){
//                 st.push({s[i],st.top().second +1});
//             }
//             else{
//                 st.push({s[i],1});
//             }
//             if(st.top().second == k){
//                 for(int i = 0 ; i < k ; i++){
//                     st.pop();
//                 }
//             }
//         }
//         string ans = "";
//         while(!st.empty()){
//             ans += st.top().first;
//             st.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };