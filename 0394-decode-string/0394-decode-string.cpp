class Solution {
public:
    string repeat(string str, int n){
        string ans = "";
        while(n--){
            ans += str;
        }
        return ans;
    }
    int getNum(stack<char>& st){
        string temp = "";
        while(!st.empty() && st.top() >='0' && st.top() <='9'){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        int n = stoi(temp);
        return n;
    }
    string decodeString(string s) {
        int n = s.length();
        stack<char>st;
        string ans = "";
        for(int i = 0; i < n; i++){
            string temp ="";
            char ch = s[i];
            if(ch != ']'){
                st.push(ch);
                continue;
            }
            if(ch == ']'){
                while(!st.empty() && st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                int num = getNum(st);
                // st.pop();
                reverse(temp.begin(), temp.end());
                temp = repeat(temp,num);
                if(!st.empty()){    
                    for(char chr : temp){
                        st.push(chr);
                    }
                } else{
                    ans += temp;
                }
            }
        }
        string temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }
};