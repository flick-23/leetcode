class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int,int>>a;
        vector<pair<int,int>>b;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1 )
                    a.push_back({i,j});
                if(img2[i][j] == 1)
                    b.push_back({i,j});
            }
        }
        map<pair<int,int>,int>mpp;
        int ans = 0;
        for(auto [i, j] : a){
            for(auto [x,y] : b){
                mpp[{i-x, j-y}]++;
                ans = max(ans,  mpp[{i-x, j-y}]);
            }
        }
        return ans;
    }
};