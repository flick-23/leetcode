class Solution {
public:
    bool isMatch(string& word, string& target){
        int i = 0, j = 0;
        while(i < word.length() && j < target.length()){
            if(word[i] != target[j]){
                return false;
            }
            int len1 = 1, len2 = 1;

            while( i+1 < word.length() && word[i] == word[i+1]){
                i++;
                len1++;
            }

            while( j+1 < target.length() && target[j] == target[j+1]){
                j++;
                len2++;
            }

            if(len1 > len2 || (len1 < len2 && len2 <3)){
                return false;
            }
            i++;
            j++;
        }
        return i == word.length() && j == target.length();
    }
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for(auto word : words){
            if(isMatch(word,s)){
                count++;
            }
        }
        return count;
    }
};