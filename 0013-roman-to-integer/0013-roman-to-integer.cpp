class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            int value = 0;
            switch(ch){
                case 'I':value=1;
                if(i+1<s.length() && s[i+1] == 'V'){
                    value = 4;
                    i++;
                } else if(i+1<s.length() && s[i+1] == 'X'){
                    value = 9;
                    i++;
                }
                break;
                case 'V':value=5;
                break;
                case 'X':value=10;
                if(i+1<s.length() && s[i+1] == 'L'){
                    value = 40;
                    i++;
                } else if(i+1<s.length() && s[i+1] == 'C'){
                    value = 90;
                    i++;
                }
                break;
                case 'L':value=50;
                break;
                case 'C':value=100;
                if(i+1<s.length() && s[i+1] == 'D'){
                    value = 400;
                    i++;
                } else if(i+1<s.length() && s[i+1] == 'M'){
                    value = 900;
                    i++;
                }
                break;
                case 'D':value=500;
                break;
                case 'M':value=1000;
                break;
            }
            sum+=value;
        }
        return sum;
    }
};