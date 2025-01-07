class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char>st;
        int K = k;
        if(n == k)  return "0";
        string str;
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top()-'0' > num[i]-'0' && k >0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        while(str.length() && str.back() == '0'){
            str.pop_back();
        }
        reverse(str.begin(),str.end());
        if(str.length() == 0)
            return "0";
        return str;
    }
};