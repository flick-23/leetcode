class Solution {
public:
    vector<int> computeZArray(const string& str) {
        int n = str.length();
        vector<int> Z(n, 0); // Initialize Z array with zeros

        // Initialize the left and right boundaries of the current "box"
        int L = 0, R = 0;

        for (int i = 1; i < n; ++i) {
            if (i > R) {
                // Case 1: i is outside the current "box"
                L = R = i; // Set both L and R to i
                // Extend the "box" to the right as long as the characters match
                while (R < n && str[R] == str[R - L]) {
                    R++;
                }
                Z[i] = R - L; // The length of the match is R - L
                R--;          // Adjust R to the last matching position
            } else {
                // Case 2: i is inside the current "box"
                int k = i - L; // Calculate the position k within the "box"
                if (Z[k] < R - i + 1) {
                    Z[i] = Z[k]; // Copy the Z value from position k
                } else {
                    L = i; // Move the left boundary of the "box" to i
                    while (R < n && str[R] == str[R - L]) {
                        R++;
                    }
                    Z[i] = R - L; // The length of the match is R - L
                    R--;          // Adjust R to the last matching position
                }
            }
        }
        return Z;
    }
    vector<string> splitSentence(string sentence) {
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ') {
                temp += sentence[i];
            } else {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
    string combineSentence(vector<string> str) {
        string ans = "";
        for (int i = 0; i < str.size(); i++) {
            ans += str[i];
            if (i < str.size() - 1) {
                ans += " ";
            }
        }
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        if (sentence[sentence.length() - 1] != ' ') {
            sentence += ' ';
        }
        vector<string> sen = splitSentence(sentence);
        for (int i = 0; i < n; i++) {
            string word = dictionary[i];
            for (int j = 0; j < sen.size(); j++) {
                string temp = sen[j].substr(0, word.length());
                if(temp == word && sen[j].length() > temp.length()){
                    sen[j] = word;
                }
            }
        }
        return combineSentence(sen);
    }
};