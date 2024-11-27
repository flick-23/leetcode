class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int>secret_hash;
        unordered_map<char,int>guess_hash;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bulls++;
            } else{
                secret_hash[secret[i]]++;
                guess_hash[guess[i]]++;
            }
        }
        for(auto item : guess_hash){
            if(secret_hash[item.first] !=0 && item.second != 0){
                cows += min(secret_hash[item.first], item.second);
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};