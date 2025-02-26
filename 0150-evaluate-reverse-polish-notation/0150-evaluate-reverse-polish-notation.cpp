class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string ch : tokens){
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                if(ch == "+"){
                    st.push(top2 + top1);
                }
                if(ch == "-"){
                    st.push(top2 - top1);
                }
                if(ch == "*"){
                    st.push(top2 * top1);
                }
                if(ch == "/"){
                    st.push(top2 / top1);
                }
            } else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};