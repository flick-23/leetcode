class Solution {
public:
    string helper(string str,string ans){
        char ch = str[0];
        int count = 1;
        for(int i=1;i<str.length();i++){
            if(ch==str[i]){
                count++;
            } else{
                string temp =to_string(count);
                ans+= temp + ch;
                count = 1;
                ch=str[i]; 
            }
        }
        ans+=to_string(count)+ch;
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string rle ="11";
        for(int i = 2; i<n; i++){
            rle = helper(rle,"");
        }
        return rle;
    }
};