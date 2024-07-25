class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            if(tokens[i] == "+"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 + op2);
            }
            else if(tokens[i] == "-"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 - op2);
            } 
            else if(tokens[i] == "*"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 * op2);
            }
            else if(tokens[i] == "/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 / op2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};