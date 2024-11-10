/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string& s1, string& s2) {
        int m = 0;
        for (int i = 0; i < s1.length(); ++i)
            if (s1[i] == s2[i])
                ++m;
        return m;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(nullptr));
        for (int i = 0; i < 30; ++i) {
            string w = words[rand() % words.size()];
            int m = master.guess(w);
            if (m == 6)
                break;
            vector<string> t;
            for (int j = 0; j < words.size(); ++j)
                if (match(w, words[j]) == m)
                    t.push_back(words[j]);
            words = t;
        }
    }
};