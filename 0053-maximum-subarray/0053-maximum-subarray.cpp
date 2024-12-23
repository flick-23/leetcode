class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int cMax=0, gMax=a[0],i;
        for(i=0;i<a.size();i++){
            cMax += a[i];
            if(a[i]>cMax){
                cMax=a[i];
            }
            if(gMax <= cMax)
                gMax = cMax;
        }
        return gMax;
    }
};