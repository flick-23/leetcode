class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        int len = a.length(),i;
        if (len == 0)
            return 0;
        if (len == 1)
            return 1;
        int count = 0, maxCount = 0;
        map<char, int> mpp;
        // mpp[a[0]]++;
        for ( i = 0; i < len; i++) {   
            if(mpp.find(a[i]) == mpp.end()){
                cout<<"Added a["<<i<<"] : "<<a[i]<<endl;
                mpp[a[i]]++;
                count = mpp.size();
            } else{
                cout<<"Resetting map"<<endl;
                mpp.clear();
                mpp[a[i]]++;
                count = mpp.size();
            }
            maxCount = max(count,maxCount);
        }
        return maxCount;
    }
    */
     vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};